#pragma once
#include <vector>
#include <stdexcept>
using namespace std;

// Описание  класса

class Money {
private:
    vector <unsigned char> amount;

public:
    Money(); // Конструктор по умолчанию
    Money(const vector<unsigned char>& digits); // Конструктор принимающий вектор элементов и создающий объект
    Money(const Money& other); // создание копии объекта Money
    Money& operator= (const Money& other); // Операция присваивания объектов
    Money operator+ (const Money& other) const; // Операция сложения объектов
    Money operator- (const Money& other) const; // Операция вычитания объектов
    bool operator== (const Money& other) const;
    bool operator< (const Money& other) const;
    bool operator> (const Money& once) const; 



};

