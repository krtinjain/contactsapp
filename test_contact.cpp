
#include <iostream>
#include "Contact.h"
using namespace std;

int main(){

    cout << "###### Testing Email class: " << endl;
	Email my_email("USC", "tommytrojan@usc.edu");
	my_email.print();

	cout << "###### Testing Phone class: " << endl;
	Phone my_phone1("Home", "3101922847");
	Phone my_phone2("Home", "213-192-2847");
	my_phone1.print();
	my_phone2.print();
    
    cout << "###### Testing SNAccount class: " << endl;
	//SNAccount instagram("IG", "msabrishami");
	SocialNetwork instagram("IG", "msabrishami");
	//instagram.get_contact(false);
	instagram.print();
    
    return 0;
}

