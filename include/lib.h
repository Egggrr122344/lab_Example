#pragma once
#include <iostream>
#include <string>
using namespace std;

// Описание  класса
class Money {
private:
    unsigned char* amount; // Указатель на массив для хранения денежной суммы
    size_t size; // Размер массива

public:
    // Конструкторы
    Money();
    Money(const size_t& size, unsigned char t = 0);
    Money(const initializer_list<unsigned char> &t);
    Money(const Money& other);
    Money(Money&& other) noexcept;
    ~Money();

    // Методы вставки и вывода
    void setAmount(const initializer_list<unsigned char> &t);
    void printAmount() const;

    // Арифметические операции
    Money operator+(const Money& other) const;
    Money operator-(const Money& other) const;
    Money& operator=(const Money& other);

    // Операции сравнения
    bool operator>(const Money& other) const;
    bool operator<(const Money& other) const;
    bool operator==(const Money& other) const;

    size_t getSize(); 

    unsigned char* getArray();

};
