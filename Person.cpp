#include "Person.h"
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
Person::Person(){ 
    // Already Done! :)  
    set_person();
}


Person::Person(string fname, string lname, string bdate){
    // TODO 
    this->f_name = fname;
    this->l_name = lname;
   birthdate =new Date(bdate);
   this->birthdate = birthdate;
   add_contact();


}

Person::Person(ifstream& infile){
    
     // *START_PERSON line has been read by loadDB  
     string line;
         getline(infile, line);   //get first name and last name
         //string fname, lname, birthdate;
         int pos = line.find(",");
         this->l_name = line.substr(0, pos);
         this->f_name = line.substr(pos + 2, line.size() - 1);
         getline(infile, line);  //get birthdate 
         this->birthdate = new Date(line);
         
         while (line.substr(0, 11) != "*END-PERSON" || line.substr(0, 13) != "*END-DATABASE" )
         {
             getline(infile, line);   //get contacts  or *END_PERSON line
             if(line.substr(0, 11) == "*END-PERSON" )
             {
               break;
             }
             else
                {
                string class_str, type_str, type_value;
                int pos1, pos2, pos3;
                pos1 = line.find(":");
                pos2 = line.find("(");
                pos3 = line.find(")");

                class_str = line.substr(0, pos1);
                type_str = line.substr(pos2 + 1, pos3 - pos2 - 1);
                type_value = line.substr(pos3 + 2);

                if (class_str == "Email")
                {

                    //string line_email_addr = type_value;
                    Email* emailobj = new Email(type_str, type_value);
                    contacts.push_back(emailobj);
                }
                else if (class_str == "Phone")
                {

                    //string line_phone_num = type_value;
                    Phone* phoneobj = new Phone(type_str, type_value);
                    contacts.push_back(phoneobj);
                }
                else if (class_str == "SocialNetwork")
                {

                    //string line_handle = type_value;
                    SocialNetwork* SNobj = new SocialNetwork(type_str, type_value);
                    contacts.push_back(SNobj);
                }
             }
         }
     
}


Person::~Person(){
    // TODO
      delete birthdate;
     // delete [] contacts;
   // cout << "Object is being deleted\n";
}
void Person::add_contact()
{
    while (1) 
    {
        string YNresponse;
        string ContactInfoType;
        cout << "Are you interested in adding contact information to a person object?(Y/N)\n";
        cin >> YNresponse;

        if (YNresponse == "Y"|| YNresponse == "y")
        {
            cout << "What type of ContactInfo should be added?(Email/Phone/SocialNetwork)\n";
            cin >> ContactInfoType; 
            if (ContactInfoType == "Email"|| ContactInfoType == "email") {
                ContactInfo  *Emailobj =new Email();
               // Email  *Emailobj =new Email();
               // Email Emailobj;
               // Emailobj->print();
                contacts.push_back(Emailobj);
            }
            else if (ContactInfoType == "Phone"|| ContactInfoType == "phone") {
                ContactInfo * Phoneobj= new Phone();
               // Phone* Phoneobj = new Phone();
               // Phone Phoneobj;
                contacts.push_back(Phoneobj);
               // Phoneobj->print();

            }
            else if (ContactInfoType == "SocialNetwork"||ContactInfoType == "socialnetwork") {
                ContactInfo *  SocialNetworkobj = new SocialNetwork();
                //SocialNetwork* SocialNetworkobj = new SocialNetwork();
               // SocialNetwork SocialNetworkobj;
                contacts.push_back(SocialNetworkobj);

            }
        }
        else if (YNresponse == "N" || YNresponse == "n")
        {
           /*
            for (int i = 0; i < contacts.size(); i++)
            {
               contacts[i]->print();
            }
           */ 
            break;
        }
    }
}

/*
void Person::remove_contact()
{
    string  remove_option, YNdelete;
    ContactInfo* ptrdelete;
    ContactInfo*  temp;

    int optionnum, contactscount;

    while (1)
    {
        cout << "Contacts Remove Menu:\n";
        for (int i = 0; i < contacts.size(); i++)
        {

            cout << "[" << i + 1 << "]";
            contacts[i]->get_contact(false);
            contacts[i]->print();
        }
        cout << "quit option(q/quit/0)\n";
        contactscount = contacts.size();
        cin >> remove_option;
        if (remove_option.substr(0,1) == "q" || remove_option.substr(0,1) == "Q" || remove_option.substr(0,1) == "0")
        {
            break;
        }
        
        else
        {
            optionnum = atoi(remove_option.c_str());

            if (optionnum > 0 && optionnum < (contactscount + 1))
            {
                cout << " are you sure about deleting this contact?(Y/N)\n";
                contacts[optionnum - 1]->print();
                cin >> YNdelete;
                if (YNdelete == "Y" || YNdelete == "y")
                {
                    //contacts[optionnum - 1]->print();
                    ptrdelete = contacts[optionnum - 1];
                    for (int j = optionnum; j < contactscount; j++)
                    {
                        temp = contacts[j];
                        contacts[j - 1] = temp;
                    }
                    contacts[contactscount - 1] = ptrdelete;
                    contacts.pop_back();
                }
            }
        }
    }

}
*/



void Person::remove_contact() {


    while (1)
    {
        if (contacts.size() == 0)
        {
            cout << "No contacts to remove! / All availble have been removed!" << endl;
            return;
        }
        else
        {
            cout << "Remove contact information menu:" << endl;
            string spr;
            int k = 0;
            for (int i = 0; i < contacts.size(); i++)
            {
                k = i + 1;
                cout << "[" << k << "]     ";
                contacts[i]->print();
            }

            cout << "Which contact to remove (select number, or quit)? ";
            cin >> spr;
            transform(spr.begin(), spr.end(), spr.begin(), ::tolower);
            if (spr == "quit" || spr == "q")
            {
                return;
            }

            else
            {
                int flag = 0;
                int flag2 = 0;
                int num;
                for (int j = 0; j < spr.length(); j++)
                {
                    if (isdigit(spr[j]) == false)
                    {
                        flag = 1;
                    }

                }
                if (flag == 0)
                {
                    num = atoi(spr.c_str());
                    for (int i = 0; i < contacts.size(); i++)
                    {
                        if (i + 1 == num)
                        {
                            flag2 = 1;
                        }

                    }
                    if (flag2 == 1) //remove contact
                    {
                        contacts.erase(contacts.begin() + num - 1);
                    }
                    else if (flag2 == 0)
                    {
                        break;
                    }
                }
                else if (flag == 1)
                {
                    break;
                }


            }



        }
    }



}


void Person::set_person(){
    //TODO
    // prompts for the information of the user
    // first/last name can have spaces!
    // date format must be "M/D/YYYY", but user can make mistakes
    // OOP: the one who wrote the Date class did take care of handling mistakes 
   
	cout << "First Name: ";
    // TODO: read the first name 
    //cin >> f_name;
    getline(cin, f_name);
	cout << "Last Name: ";
    // TODO: read the last name
   //cin >> l_name;
    getline(cin, l_name);
    cout << "Birthdate (M/D/YYYY): ";
    // TODO: get birthdate from user as a string and use it to create a new Date (dynamic allocation)
   // cin >> bdate;
    getline(cin, bdate); 
    birthdate = new Date(bdate);
    this->birthdate = birthdate;
    add_contact();
}


void Person::print_person() {
    // Already done! 
    cout << l_name << ", " << f_name << endl;
    birthdate->print_date("Month D, YYYY");
    
    for (int i = 0; i < contacts.size(); i++) {
       // contacts[i]->get_contact();

        contacts[i]->print();
        
    }
    
}



bool Person::operator==(const Person& rhs){
    // TODO
    // Hint: Look at how we overloaded == in Date
    // Two persons are equal only if they have the same first name, last name and date of birth! 

    if ((this->f_name == rhs.f_name) && (this->l_name == rhs.l_name) && (this->birthdate == rhs.birthdate))
    {
        return true;
    }
    else
    {
        return false;
    }


}


bool Person::operator!=(const Person& rhs){ 
    // TODO
    // Hint: two things are either equal or not equal 

    if ((this->f_name != rhs.f_name) || (this->l_name != rhs.l_name) || (this->birthdate != rhs.birthdate))
    {
        return true;
    }
    else
    { 
        return false;
    }

}


void Person::write_to_file(ofstream& outfile) {   
    outfile << "*START-PERSON----------------------------" << endl;
    outfile << l_name << ", " << f_name << endl;
    outfile << birthdate->get_date() << endl;
    for (int i =0 ;i < contacts.size(); i++)
    {
        outfile << contacts[i]->get_contact(true) << endl;
    }
    outfile << "*END-PERSON------------------------------" << endl;

}

void Person::modify(int mod)
{
   if(mod == 1)
   {
      string name;
      cout<< "Enter new first name: "<<endl;
      cin>> name;
      f_name = name;
   
   
   }
   else if(mod == 2)
   {
      string name;
      cout<< "Enter new last name: "<<endl;
      cin>> name;
      l_name = name;
   
   
   }
   else if(mod == 3)
   {
      string name;
      cout<< "Enter new birthdate: "<<endl;
      cin>> name;
      birthdate = new Date(name);
      this->birthdate = birthdate;
   
   
   }
  
   else if(mod == 4)
   {
      
      remove_contact();
   
   } 
   
   else if(mod == 5)
   {
      add_contact();
   }
   else
   {
      cout<< "WRONG CHOICE" << endl;
   }
}







