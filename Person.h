#ifndef PERSON_H
#define PERSON_H

#include "Date.h"
#include"Contact.h"
#include <fstream>
#include <vector>
class Person{
    friend class Network;
private:
	string f_name;  // can have space 
	string l_name;  // can have space
	Date *birthdate;
	string bdate;
    // other attributes will be added later
   Person *next;
   Person *prev;
    
   vector<ContactInfo*> contacts;


public: 
    Person();
    Person(string f_name, string l_name, string bdate);
    Person(ifstream& infile);
    ~Person();
    //string line;
	void print_person();
	void set_person();
    void add_contact();
    void remove_contact();
    bool operator==(const Person& rhs);
    bool operator!=(const Person& rhs);
   
    void write_to_file(ofstream& outfile);
    void modify(int mod);
    };


#endif
