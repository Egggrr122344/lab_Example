#pragma once
#include <iostream>
#include <string>
using namespace std;


class Money {
private:
    unsigned char* amount; 
    size_t size; 

public:
    
    Money();
    Money(const size_t& size, unsigned char t = 0 );
    Money(const initializer_list<unsigned char> &t);
    Money(const Money& other);
    Money(Money&& other) noexcept;
    ~Money();

    
    void setAmount(const initializer_list<unsigned char> &t);
    void printAmount() const;

    
    Money operator+(const Money& other) const;
    Money operator-(const Money& other) const;
    Money& operator=(const Money& other);

    
    bool operator>(const Money& other) const;
    bool operator<(const Money& other) const;
    bool operator==(const Money& other) const;

    size_t getSize(); 

    unsigned char* getArray();

    bool helper(unsigned char* arr, size_t sizeArr); // для тестов сравнение объекта класса с массивом 

};
