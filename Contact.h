#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include <sstream> 
#include <stdlib.h>
using namespace std;

class ContactInfo {
	friend class Network;
	friend class Person;

    protected: //TODO: should type be private or protected?	Think about it.
	string type;
public:
	virtual void print()=0;
	virtual string get_contact(bool full = false)=0;
   // virtual string get_contact(bool full=false) = 0;
	virtual void set_contact()=0;
};


// Complete the Email declaraction from scratch here 

class Email : public ContactInfo{
private:
	string email_addr;
public:
	Email();
	Email(string type, string email_addr);
	void set_contact();
	string get_contact(bool full);
	void print();
};
// Complete the phone declaration from scratch
class Phone : public ContactInfo {
private:
	string num;
public:
	Phone();
	Phone(string type, string num);
	string get_contact(bool full);
	void set_contact();
	void print();
};

// Complete the Social Netwrok Account declaration from scratch
class SocialNetwork : public ContactInfo {
private:
    string handle;
public:
	SocialNetwork();
	SocialNetwork(string type, string handle);
	void set_contact();
	string get_contact(bool full);
	void print();
};


#endif

