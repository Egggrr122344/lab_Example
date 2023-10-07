#pragma once
#include <iostream>
#include <string>
using namespace std;

// Описание  класса
class Money {
private:
    unsigned char* amount; // Указатель на динамический массив для хранения денежной суммы
    size_t size; // Размер массива

public:
    // Конструкторы
    Money();
    Money(const size_t& size, unsigned char t = 0);
    Money(const std::initializer_list<unsigned char>& t);
    Money(const Money& other);
    Money(Money&& other) noexcept;
    ~Money();

    // Методы
    void setAmount(const std::initializer_list<unsigned char>& t);
    void printAmount() const;

    // Арифметические операции
    Money operator+(const Money& other) const;
    Money operator-(const Money& other) const;

    // Операции сравнения
    bool operator>(const Money& other) const;
    bool operator<(const Money& other) const;
    bool operator==(const Money& other) const;
};
