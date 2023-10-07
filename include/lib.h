#pragma once
#include <iostream>
#include <string>
using namespace std;

// Описание  класса

class Money {
private:
    unsigned char* amount; // Хранение денежной суммы
    size_t size; // Размер массива


public:
    Money(); // Конструктор по умолчанию создает объект с нулевым значением
    Money(const size_t & n, unsigned char t = 0) : size(n);
    Money(const initializer_list <unsigned char> &t) : size(t.size()); // Конструктор принимающий массив элементов и создающий объект
    Money(const string& t ) : size(t.length());
    Money(const Money& other) : size(other.size); // создание копии объекта Money
    Money(Money&& other) noexcept : amount(other.amount), size(other.size);

    virtual ~Money() noexcept;

    Money& operator =(const Money& other); // Операция присваивания объектов
    Money operator +(const Money& other) const; // Операция сложения объектов
    Money operator -(const Money& other) const; // Операция вычитания объектов

    bool operator ==(const Money& other) const; // Операция сравнения ==
    bool operator <(const Money& other) const;
    bool operator >(const Money& once) const;

   
    
    size_t getSize();
    string toString();


    

    ostream& print(ostream& os);

};
ostream &operator <<(ostream& os, const Money& object);

