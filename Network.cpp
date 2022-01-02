#include "Network.h"
//#include "misc.h"
#include <fstream>
#include <dirent.h>
#include <limits>
#include<sstream>
#include<string.h>
#include <typeinfo>
Network::Network(){
    // TODO
    // What should be the initial values for head, tail, and count?
    count = 0; 
    head = NULL;
    tail = NULL; 
}


void Network::push_front(Person* newEntry){
    // TODO
    // Adds a new entry to the front of the LL (where head is pointing)
    if(count == 0)
    {
      head = newEntry;
      tail = newEntry;
      newEntry->next = NULL;
      newEntry->prev = NULL;
    }
    else
    {
      newEntry->next = head;
      newEntry->prev = NULL;
      head->prev = newEntry;
      head = newEntry;


    }
    count++;
}


void Network::push_back(Person* newEntry){
    // TODO
    // Adds a new entry to the back of the LL (where tail is pointing)
   if(count == 0)
    {
      head = newEntry; 
      tail = newEntry;
     newEntry->next = NULL;
     newEntry->prev = NULL;
    }
   else
   { 
      newEntry->prev = tail;
      newEntry->next = NULL;
      tail->next = newEntry;
      tail = newEntry;

   }
    count++;
   
}



void Network::printDB(){
    // Already done! 
    cout << "Number of items: " << count << endl;
    cout << "------------------------------" << endl;
    Person* ptr = head;
    while(ptr != NULL){
        ptr->print_person();
        cout << "------------------------------" << endl;
        ptr = ptr->next;
    }
}

Network::~Network(){
    Person* ptr = head;

    
    while(head != NULL){
        Person* ptr = head; 
        head = head->next;
        delete ptr;
    }

    
    // TODO 
    // Delete all the dynamically allocated items

/*
    while (ptr != NULL) {

        delete ptr;
        ptr = ptr->next;
            }

*/

}


Person* Network::search(Person* searchEntry){
    // TODO
    
    // Searches the Network to find an entry which has similar attributes as searchEntry
    // if found, returns a pointer to it, else returns NULL
    // Hint: We already implemented the == operator for two Person objects
    // Note: searchEntry is not a Person, but a Person* 
    
    Person* temp = head;
    
    while(temp != NULL)
    {
         
      if((temp->f_name == searchEntry->f_name) && (temp->l_name == searchEntry->l_name) && (temp->birthdate->get_date() == searchEntry->birthdate->get_date() ))
      {
         
         
         return temp;
      }
      temp = temp->next;
    }
    return NULL;
}


Person* Network::search(string fname, string lname, string bd){
    // TODO
    //Person* temp = new Person(fname,lname,bd);
    
   // search(temp);
    
    // Search based on fname, lname, and birthdate
    // if found, returns a pointer to it, else returns NULL
    // Note: two ways to implement this:
    // 1st) making a new Person with fname, lname, bdate and and using search(Person*)
    // 2nd) using fname, lname, and bd directly 
    

    Person* temp = head;

    while (temp != NULL)
    {

        if ((temp->f_name == fname) && (temp->l_name == lname) && (temp->birthdate->get_date() == bd))
        {


            return temp;
        }
        temp = temp->next;
    }
    return NULL;


    }

/*
Person* Network::search(string fname, string lname) {
    // TODO
    //Person* temp = new Person(fname,lname,bd);

   // search(temp);

    // Search based on fname, lname, and birthdate
    // if found, returns a pointer to it, else returns NULL
    // Note: two ways to implement this:
    // 1st) making a new Person with fname, lname, bdate and and using search(Person*)
    // 2nd) using fname, lname, and bd directly 


    Person* temp = head;
    Person* edit = head;
    int i;
    
    while (edit != NULL)
    {

        if ((edit->f_name == fname) && (edit->l_name == lname))
        {

            i++;
            count++;
            cout<< "["<< itr<< "]" <<endl;
            edit->numb = itr;
            edit->print_person();
            cout << "------------------------------" << endl;
        }
        edit = edit->next;
    }
       
    if(i == 0)
    {return NULL;}
    else{return head;}


}
*/

vector <Person*> Network::search(string fname, string lname) {
    // TODO
    //Person* temp = new Person(fname,lname,bd);

   // search(temp);

    // Search based on fname, lname, and birthdate
    // if found, returns a pointer to it, else returns NULL
    // Note: two ways to implement this:
    // 1st) making a new Person with fname, lname, bdate and and using search(Person*)
    // 2nd) using fname, lname, and bd directly 


    Person* temp = head;
    vector <Person*> result;
    int numba = 0;
    while (temp != NULL)
    {

        if ((temp->f_name == fname) && (temp->l_name == lname))
        {
                     
            result.push_back(temp);
        }
        temp = temp->next;
    }
    return result;


}

Person* Network::select_person(string fname, string lname) {
   // TODO
    
   Person* temp = head;
    vector <Person*> result;
    
    while (temp != NULL)
    {

        if ((temp->f_name == fname) && (temp->l_name == lname))
        {
                       
            result.push_back(temp);
        }
        temp = temp->next;
    }
    if (result.size() != 0)
            {   
                cout<<"Found! \n";
                if (result.size() == 1)
                {
                   result[0]->print_person(); 
                   cout<<endl;                   
                   Person* edit = result[0];
                   return edit;

                }
                else
                {
                  for (int i = 0; i < result.size(); i++)
                    {
                       cout<<"["<<i+1<<"]"<<endl;
                       result[i]->print_person();  
                    }
                   cout << "Enter the numeric code of person to select:  \n";
                   int pin;
                   cin >> pin;
               
                   cout<<endl;
                   Person* edit = result[pin-1];
                   //edit->print_person();
                   return edit;
                   
                } 
                

            }
        else
        {
            cout << "no entry was found! \n";
            return NULL;
        }
    //return result;
    
}



void Network::saveDB(string filename){
    // TODO
    // Saves the netwrok in file <filename>
    // Look at studentDB.db as a template of the format of our database files
    ofstream outfilename(filename.c_str());
    
    Person* ptr = head;
    while(ptr != NULL){
        ptr->write_to_file(outfilename);
         ptr = ptr->next;
    }
    outfilename << "*END-DATABASE------------";
    outfilename.close();
    
    
}


void Network::loadDB(string filename){ 
    ifstream infile;
    infile.open(filename.c_str());
    if(count !=0) {
      count = 0;
    }
    string person_line;
    getline(infile, person_line); // read *START_PERSON line 
    //cout<<person_line<<endl;
    while (person_line.substr(0, 13) == "*START-PERSON")
    {
        Person* chintu = new Person(infile);// call Person(ifstream& infile)  to get person object
        push_back(chintu);
       
        getline(infile, person_line);   // read next one *START_PERSON line
        if (person_line.substr(0, 13) == "*END-DATABASE") break;// end reading the file 
    } 
    
    infile.close();
    // TODO
    // Loads the netwrok from file <filename>
    // The format of the input file is similar to saveDB
    // Look at network studentDB.db as a template
    // When a new database is being loaded, you need to delete the previous dataset
}

/*
void Network::loadDB(string filename) {
    ifstream infile;
    infile.open(filename.c_str());
        while (!infile.eof())
        {
        Person* chintu = new Person(infile);
        push_back(chintu);
        
        }

    infile.close();
    // TODO
    // Loads the netwrok from file <filename>
    // The format of the input file is similar to saveDB
    // Look at network studentDB.db as a template
    // When a new database is being loaded, you need to delete the previous dataset
}
*/


Network::Network(string fileName){
    // TODO
    // Hint: just call loadDB 
    loadDB(fileName);
}


bool Network::remove(string fname, string lname, string bd)
{
    // TODO
    // remove the entry with matching fname, lname, bd
    // If it exists, returns true, otherwise, returns false
    if(search(fname,lname,bd) == NULL)
    {return false;}
    if(count == 0)
    {return false;}
    else
    {
      Person* temp = search(fname,lname,bd); 
      count--;
      if(temp == head && temp == tail) 
      {
         head = NULL;
         tail = NULL;
      }
      else if(temp == head)
      {
         temp->next->prev = NULL;
         head = temp->next;
         
         return true;
         
      } 
      else if(temp == tail)
      {
      temp->prev->next = NULL;
      tail = temp->prev;
      return true;
      }
      else
      {
         temp->prev->next = temp->next;
         temp->next->prev = temp->prev;
         return true;
      }
      
    }
    
   
}

void Network::sendEmail(string addr, string subject, string content, string attachment){
    // Sending a command looks like:
    // echo "content" | mailx -s "subject" -a "attachment" addr;
    // TODO: Search how you can run a unix command in C++
    // TODO: You need to add double quotation character (") to both sides of strings for this command. 
    // Adding other characters (like ? in code below) should be easy, but double quotation says: I'm a character but not a typical character! 
    // string new_str = '?' + old_str + '?'
    // TODO: Complete this method

    addr = "\"" + addr + "\"";
    content = "\"" + content + "\"";
    subject = "\"" + subject + "\"";
    string cmd;
    cmd = "echo " + content + " | mailx -s " + subject + " ";
    if (attachment == "")
        cmd += addr;
    else {
        attachment = "\"" + attachment + "\"";
        cmd += "-a "  + attachment + " " + addr;
    }
    cout << "|" << cmd << "|" << endl;
    system(cmd.c_str());
}


 
void Network::showMenu(){
    int opt;
    while(1){
        cout << "\033[2J\033[1;1H";
         // printMe("banner");
        cout << "Select from below: \n";
        cout << "1. Save network database \n";
        cout << "2. Load network database \n";
        cout << "3. Add a new person \n";
        cout << "4. Remove a person \n";
        cout << "5. Search & Edit \n";
        cout << "6. Print database \n";
        cout << "7. Send Email \n";
        cout << "0. Quit \n";
        cout << "\nSelect an option ... ";
        
        if (cin >> opt) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Wrong option! Quitting ... " << endl;
            return;
        }

        string fname, lname, fileName, bdate;
        cout << "\033[2J\033[1;1H";

        if (opt==1){ 
            // Already done! 
            cout << "Saving network database \n";
            cout << "Enter the name of the save file: ";
            cin >> fileName;
            this->saveDB(fileName);
            cout << "Network saved in " << fileName << endl;
        }
        else if (opt==2){ 
            // Already done! 
            cout << "Loading network database \n";
            // Note: we added a nice feature to show the files in current directory
            
            DIR *dir;
            struct dirent *ent;
            if ((dir = opendir ("./")) != NULL)
            {
                string str;
                while ((ent = readdir (dir)) != NULL)
                {
                    str = ent->d_name;
                    if (str.size() > 3)
                    {
                        if (str.substr(str.size()-3) == ".db")
                            cout << str << endl; 
                    }
                }
                closedir (dir);
            }
            
               
            cout << "Enter the name of the load file: ";
            cin >> fileName;
            ifstream check(fileName.c_str());
            if (! bool(check))
                cout << "Warning! File does not exist! \n";
            else {
                loadDB(fileName);
                cout << "Network loaded from " << fileName << " with " << count << " items \n";
            }
        }
        else if (opt == 3){
            // TODO
            // Prompt and get the information of a new Person
            // You need to make sure this item does not already exists!
            // If it does not exist, push it to the front of the LL
            cout << "Adding a new item (push front)\n";
            string fname,lname,birthdate;
            cout << "First Name: ";
            getline(cin,fname);
            cout << "Last Name: ";
            getline(cin,lname);
            cout << "Enter DOB (M/D/YYYY): ";
            cin >> birthdate;
            
            if(search(fname,lname,birthdate) == NULL)
            {
               push_back(new Person(fname,lname,birthdate));
            }
            
            
        }
        else if (opt == 4){
            // TODO 
             string fname,lname,birthdate;
            cout << "Removing an item \n";
            cout << "First name: ";
            getline(cin,fname);
            cout << "Last name: ";
            getline(cin,lname);
            cout << "Birthdate: ";
            cin>>birthdate;
            if(search(fname,lname,birthdate) != NULL)
            {
               remove(fname,lname,birthdate);
               cout << "Remove Successful! \n";
            }
            else{cout << "Person not found! \n";}
            // If found and removed successfully: cout << "Remove Successful! \n";
            // else: cout << "Person not found! \n";
        }
                    

        else if (opt==5){
            // TODO
           
            cout << "Searching: \n";
           string fname,lname,birthdate;
          
            cout << "First name: ";
            getline(cin,fname);
            cout << "Last name: ";
            getline(cin,lname);
            
            //vector<Person*>res;
            
            //res = search(fname, lname);
            Person* res = select_person(fname, lname);
            if (res != NULL)
            {  
                res->print_person();
                cout<<endl;                   
                   
                cout<<"Enter numeric code of modification to be carried out"<<endl;
                cout<<"[1] Edit first name"<<endl;
                cout<<"[2] Edit last name"<<endl;
                cout<<"[3] Edit birthdate"<<endl;
                cout<<"[4] Remove contact information"<<endl;
                cout<<"[5] Add contact information"<<endl;
                int m;
                cin>>m;
                res->modify(m);
            }
            else
            {
                cout << "no entry was found! \n";
            }


        }

        else if (opt==6){
            // TODO 
            printDB();
            cout << "Network Database: \n";
           
        }
        else if (opt==7){
            // TODO 
            cout << "Send Email to: \n";
            
            string fname,lname,birthdate;
          
            cout << "First name: ";
            getline(cin,fname);
            cout << "Last name: ";
            getline(cin,lname);
            
            Person* res = select_person(fname, lname);
            if(res != NULL)
            {              
               vector<ContactInfo*> emails;
               Email* eml = new Email("home","jliu8288@usc.edu");
               for(int k = 0; k< res->contacts.size(); k++)
               {
                  if(typeid(*(res->contacts[k])) == typeid(*eml))
                  {                                        
                     emails.push_back(res->contacts[k]); 
                  }
               }
               if(emails.size() == 1)
               {
                  //emails[0];
                  string stri,strn,subj,cont1,cont2;
                  stri = emails[0]->get_contact(false);
                  //cout<<stri<<endl;
                  int pos;
                  pos = stri.find(")");
                  strn = stri.substr(pos+2, stri.length());
                  //cout<<strn<<endl;
                  cout<<"Email subject: "<<endl;
                  while(isspace(cin.peek())) cin.ignore();
                  getline(cin,subj);
                  //cin>>endl;
                  cout<<"Email content: ";
                  getline(cin,cont1);
                  /*
                  while (getline(cin, cont2))
                  {
                      if (cont2 == " ")
                          break;

                      cont1 += cont2;
                  }
                  */
                  cout<<"sending email" << endl;;
                  sendEmail(strn, subj, cont1, "");
               }
               else if(emails.size() < 1)
               {
                  cout<<"No email found for this user \n";
               }
               else
               { 
                  cout<<"Select a saved email id: \n";
                  for(int k = 0; k<emails.size(); k++)
                  {
                     cout<<"["<<k+1<<"]"<< " ";
                     emails[k]->print();   
                  }
                  
                  int l;
                  cin>>l;
                  string stri,strn,subj,cont1,cont2;
                  stri = emails[l-1]->get_contact(false);
                  //cout<<stri<<endl;
                  int pos;
                  pos = stri.find(")");
                  strn = stri.substr(pos+2, stri.length());
                  //cout<<strn<<endl;
                  cout<<"Email subject: " << endl;
                  while(isspace(cin.peek())) cin.ignore();
                  getline(cin,subj);
                  cout<<"Email content: ";
                  getline(cin,cont1);
                  /*
                  while (getline(cin, cont2))
                  {
                      if (cont2 == " ")
                          break;

                      cont1 += cont2;
                  }
                  */
                  cout<<"sending email"<<endl;
                  sendEmail(strn, subj, cont1, "");
                  
               }
            }
            else{
             cout << "no entry was found! \n";   
            }
            
        }

        else if (opt==0)
            // QUIT! 
            return;
        else
            cout << "Nothing matched!\n";
       
        // Don't touch the lines below! :)  
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin.clear();
        cout << "\n\nPress Enter key to go back to main menu ... ";
        string temp;
        std::getline (std::cin, temp);
        cout << "\033[2J\033[1;1H";
    }
}
