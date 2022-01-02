
#include <iostream>
#include <cstring>
#include "Date.h"
using namespace std;

int main(){

    Date d0;
    d0.print_date("M/D/YYYY");
    d0.print_date("D-Month-YYYY");
    d0.print_date("Month D, YYYY");
    cout << "--------------------------\n";

    Date d1(2, 5, 2000);
	d1.print_date("M/D/YYYY");
    d1.print_date("D-Month-YYYY");
    d1.print_date("Month D, YYYY");
    cout << "--------------------------\n";

    Date d2(5, 10, 2000);
	d2.print_date("M/D/YYYY");
    d2.print_date("D-Month-YYYY");
    d2.print_date("Month D, YYYY");
    cout << "--------------------------\n";

    Date d3("05/02/2000");
	d3.print_date("M/D/YYYY");
    d3.print_date("D-Month-YYYY");
    d3.print_date("Month D, YYYY");
    cout << "--------------------------\n";

    Date d4("5/10/2000");
	d4.print_date("M/D/YYYY");
    d4.print_date("D-Month-YYYY");
    d4.print_date("Month D, YYYY");
    cout << "--------------------------\n";

    cout << (d2==d4) << " " << (d2!=d4) << endl;
    cout << (d3==d4) << " " << (d3!=d4) << endl;
    cout << (d3>d4) << " " << (d3<d4) << endl;


    // You can write down other test scenarios for yourself here! 
    Date d5;
    string temp;
    while (1){
        cout << "Give me a date: ";
        cin >> temp;
        d5.set_date(temp);
        d5.print_date("Month D, YYYY");
    }

    return 0;
}


