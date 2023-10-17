#include <iostream>
#include "lib.h"
using namespace std;


int main() {
    Money money1 {0,0,5,5,5};
    Money money2 {1,2,6,7,8};
    Money money3;
    Money money4 = money1.operator+(money2);

    money1.printAmount();

    money2.printAmount();

    money3.printAmount();

    

    money3.printAmount();

    cout << money1.operator<(money2) << endl;

    cout << money1.operator>(money2) << endl;

    cout << money1.operator==(money2) << endl; 

    money1.operator+(money2).printAmount();  

    money1.operator-(money2).printAmount();
    money4.printAmount();
    


}