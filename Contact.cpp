#include "Contact.h"
#include <algorithm>
#include<sstream>

Email::Email() { set_contact(); }
Email::Email(string type, string email_addr){
    // Already done
    this->type = type;
    this->email_addr = email_addr;
}


void Email::set_contact(){
    // Already done! 
    // We don't need to validate the entered email address.  
	cout << "Enter the type of email address: ";
	cin >> type; 
    cout << "Enter email address: ";
    cin >> email_addr;
}


string Email::get_contact(bool full = false){
    // TODO
    // return example: "(Personal) username@gmail.com" 
    if(!full)
    {
       ostringstream ss;
       ss <<"(" << type << ") " << email_addr;
       string emailstr = ss.str();
       return emailstr;
    }
    else if(full)
    {
       ostringstream ss;
       ss <<"Email: (" << type << ") " << email_addr;
       string emailstr = ss.str();
       return emailstr;
    }
}


void Email::print(){
    // TODO
    // Hint: use get_contact

    string emailstr = get_contact(false);
    cout << emailstr<<"\n";

}

Phone::Phone() { set_contact(); }
Phone::Phone(string type, string num){
    // TODO
    // It is possible that the phone number is given with (292-431-9876) or without (2924319876) dashes. 
    // We are sure that all phone numbers have 10 digits. 
    this->type = type;
    this->num = num;
}


void Phone::set_contact(){
    // TODO
    
    // Use these prompts:    
	 cout <<"Enter the type of phone number: ";
    cin >> type;
	 cout << "Enter the phone number: ";
    cin >> num;
}


string Phone::get_contact(bool full = false){
    // TODO
    // return example "(Cell) 213-876-0023"
    if(!full)
    {
       ostringstream ss;
       ss << "(" << type << ") " << num;
       string phonestr = ss.str();
       return phonestr;
    }
    else if(full)
    {
       ostringstream ss;
       ss << "Phone: (" << type << ") " << num;
       string phonestr = ss.str();
       return phonestr;
    }
   }

void Phone::print() {
    // TODO 
    // Hint: use get_contact

    string phonestr = get_contact(false);
    cout << phonestr << "\n";
}



SocialNetwork::SocialNetwork() { set_contact(); }
SocialNetwork::SocialNetwork(string type, string handle) {
    // TODO
    // It is possible that the phone number is given with (292-431-9876) or without (2924319876) dashes. 
    // We are sure that all phone numbers have 10 digits. 
    this->type = type;
    this->handle = handle;
}


void SocialNetwork::set_contact() {
    // TODO

    // Use these prompts:    
    cout <<"Enter the name of social network platform: ";
    cin >> type;
    cout << "Enter the handler of the social network: ";
    cin >> handle;
}


string SocialNetwork::get_contact(bool full = false) {
    // TODO
    // return example "(Instragram)usc.ede "
    if(!full)
    {
       ostringstream ss;
       ss << "(" << type << ") " << handle;
       string SocialNetworkstr = ss.str();
       return SocialNetworkstr;
    }
    else if(full)
    {
       ostringstream ss;
       ss << "SocialNetwork: (" << type << ") " << handle;
       string SocialNetworkstr = ss.str();
       return SocialNetworkstr;
    }
}




void SocialNetwork::print() {
    // TODO 
    // Hint: use get_contact

    string SocialNetworkstr = get_contact(false);
    cout << SocialNetworkstr << "\n";
}
