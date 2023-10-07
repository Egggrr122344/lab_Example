#include <iostream>
#include "lib.h"
using namespace std;


int main() {
    Money money1 {1,2,3,4};
    Money money2 {1,2,3};
    Money money3;

    money1.printAmount();

    money2.printAmount();

    money3.printAmount();

    cout << money1.operator<(money2) << endl;

    cout << money1.operator>(money2) << endl;

    cout << money1.operator==(money2) << endl; 

    money1.operator+(money2).printAmount();  

    money1.operator-(money2).printAmount();


}