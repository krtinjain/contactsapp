
#include "Date.h"
#include<sstream>
#include<string.h>
Date::Date(){
    // Already done! 
    // cout << "Default constructor called! " << endl;
    day = 1;
    month = 1;
    year = 1970;
}


Date::Date(int day, int month, int year){
    // Already done! 
    // cout << "Constructor with integer arguments is called!" << endl;
    set_date(day, month, year);
}


Date::Date(string str){
    // Already done! 
    // input format is M/D/YYYY
    // cout << "Constructor wtih string argument is called" << endl;
    set_date(str); 
}


bool Date::operator==(const Date& rhs){
    // TODO
    if((this->day == rhs.day)&&(this->month == rhs.month)&&(this->year == rhs.year))
    {
      return true;
    }
    else
    {
      return false;
    }

}

bool Date::operator!=(const Date& rhs){
    // TODO
    if ((this->day != rhs.day) || (this->month != rhs.month) || (this->year != rhs.year))
    {
        return true;
    }
    else
    {
        return false;
    }


}

bool Date::operator < (const Date& rhs){
    // TODO
   if(this->year < rhs.year)
   {
      return true;
   }
   else if((this->month < rhs.month) && (this->year == rhs.year))
   {
      return true;
   }
   else if((this->day < rhs.day) && (this->month == rhs.month) && (this->year == rhs.year))
   {
      return true;
   }
   else
   {
      return false;
   }


}

bool Date::operator > (const Date& rhs){
    // TODO
   if(this->year > rhs.year)
   {
      return true;
   }
   else if((this->month > rhs.month)&&(this->year==rhs.year))
   {
      return true;
   }
   else if((this->day > rhs.day) && (this->month == rhs.month) && (this->year == rhs.year))
   {
      return true;
   }
   else
   {
      return false;
   }

}

bool Date::check_date(int _day, int _month, int _year){
     
     if(_year <= 0 || _month <= 0)
     {return false;}
     if (_day<1 || _day > 31)
		return false;
    
    if ((_month == 2 || _month == 4 || _month == 6 || _month == 9 || _month == 11) && _day > 30)
      return false;
    
    else if (_month == 2)
    {
      if(_year % 4 != 0 && _day > 28)
      {
         return false;
      }
      else if(_year % 4 == 0 && _year % 100 == 0 && _year % 400 != 0 && _day > 28)
      {
         return false;
      }
      else 
      {
         return true;
      }
    }
    return true;
    
    // TODO -- you did this in Lab3
    // Leap years are those years divisible by 4, except for century years which are not divisible by 400. 
}

bool Date::set_date(string str){
     
     
     string month, day, year,substr1;
     int pos1 = str.find("/");
     month = str.substr(0, pos1);
     substr1 = str.substr(pos1+1, str.size() - 1);
    
     int pos2 = substr1.find("/");
     day = substr1.substr(0, pos2);
    
     year = substr1.substr(pos2+1, substr1.size() - 1);
    
   // cout<<year;
    
    stringstream ss1(month);
    stringstream ss2(day);
    stringstream ss3(year);
    
    int x = 0, y = 0, z = 0;
    ss1 >> x;
    ss2 >> y;
    ss3 >> z;
    
    int n = str.length();
    bool flag = true;
    for(int i = 0; i < n; i++)
    {
      if(int(str[i]) >= 33 && int(str[i]) <= 126)
      {
         flag = true;
      }
      else
      {
         flag = false;
         break;
      }
    }
    
    if(flag == true)
    {
      return set_date(y, x, z);
    }
    if(flag == false)
    {
      return set_date(0,0,0);
    }
    
    
    
    // TODO
    // input format should be M/D/YYYY

    // You may use these prompts
    // cout << "Error! Invalid date!" << endl;
    // cout << "Date set to default!" << endl;
}


bool Date::set_date(int day, int month, int year){
    // Already done!
    // returns a true if operation successful, or false if unsuccessful
    // understand why we used "this" statement in this method
    if (check_date(day, month, year)){
        this->day = day;
        this->month = month;
        this->year = year;
        return true;
    }
    else {
        cout << "Error! Invalid date!" << endl;
        cout << "Date set to default!" << endl;
        this->day = 1;
        this->month = 1;
        this->year = 1970;
        return false;
    }
}


void Date::print_date(string type){
    
    if (type == "M/D/YYYY")
    {
     cout<<this->month<<"/"<<this->day<<"/"<<this->year<<endl;  
    }
    else if(type == "D-Month-YYYY")
    {
         if(this->month == 1)
        {
         cout<<this->day<<"-"<<"January"<<"-"<<this->year<<endl;
        }
        else if(this->month == 2)
        {
         cout<<this->day<<"-"<<"February"<<"-"<<this->year<<endl;
        }
        else if(this->month == 3)
        {
         cout<<this->day<<"-"<<"March"<<"-"<<this->year<<endl;
        }
        else if(this->month == 4)
        {
         cout<<this->day<<"-"<<"April"<<"-"<<this->year<<endl;
        }
        else if(this->month == 5)
        {
         cout<<this->day<<"-"<<"May"<<"-"<<this->year<<endl;
        }
        else if(this->month == 6)
        {
         cout<<this->day<<"-"<<"June"<<"-"<<this->year<<endl;
        }
        else if(this->month == 7)
        {
         cout<<this->day<<"-"<<"July"<<"-"<<this->year<<endl;
        }
        else if(this->month == 8)
        {
         cout<<this->day<<"-"<<"August"<<"-"<<this->year<<endl;
        }
        else if(this->month == 9)
        {
         cout<<this->day<<"-"<<"September"<<"-"<<this->year<<endl;
        }
        else if(this->month == 10)
        {
         cout<<this->day<<"-"<<"October"<<"-"<<this->year<<endl;
        }
        else if(this->month == 11)
        {
         cout<<this->day<<"-"<<"November"<<"-"<<this->year<<endl;
        }
        else if(this->month == 12)
        {
         cout<<this->day<<"-"<<"December"<<"-"<<this->year<<endl;
        }
    }
    else if(type == "Month D, YYYY")
    {
        if(this->month == 1)
        {
         cout<<"January "<<this->day<<", "<<this->year<<endl;
        }
        else if(this->month == 2)
        {
         cout<<"February "<<this->day<<", "<<this->year<<endl;
        }
        else if(this->month == 3)
        {
         cout<<"March "<<this->day<<", "<<this->year<<endl;
        }
        else if(this->month == 4)
        {
         cout<<"April "<<this->day<<", "<<this->year<<endl;
        }
        else if(this->month == 5)
        {
         cout<<"May "<<this->day<<", "<<this->year<<endl;
        }
        else if(this->month == 6)
        {
         cout<<"June "<<this->day<<", "<<this->year<<endl;
        }
        else if(this->month == 7)
        {
         cout<<"July "<<this->day<<", "<<this->year<<endl;
        }
        else if(this->month == 8)
        {
         cout<<"August "<<this->day<<", "<<this->year<<endl;
        }
        else if(this->month == 9)
        {
         cout<<"September "<<this->day<<", "<<this->year<<endl;
        }
        else if(this->month == 10)
        {
         cout<<"October "<<this->day<<", "<<this->year<<endl;
        }
        else if(this->month == 11)
        {
         cout<<"November "<<this->day<<", "<<this->year<<endl;
        }
        else if(this->month == 12)
        {
         cout<<"December "<<this->day<<", "<<this->year<<endl;
        }
    }
    else
    {
      cout<<"Wrong print type!"<<endl;
    }
    // TODO
    // Different types for print, are: 
    // "M/D/YYYY"
    // "Month D, YYYY"
    // "D-Month-YYYY"
    // otherwise, cout << "Wrong print type!" << endl;
}

string Date::get_date(){
    // Already done!
    ostringstream ss;
    ss << month << "/" << day << "/" << year; 
    string str = ss.str();
    return str;
}

