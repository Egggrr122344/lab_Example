#include <iostream>
#include "lib.h"
#include <exception>
#include <stdexcept>
    // Конструктуры 
    Money::Money() :size {0} , amount {nullptr} {

        cout << "Default constructor" << "\n"; 
    }

    Money::Money(const size_t& n, unsigned char t = 0) : size(n) {
        amount = new unsigned char[size];
        for (size_t i = 0; i < size; i++) {
            amount[i] = t;
        }
    }

    Money::Money(const initializer_list<unsigned char>& t) : size(t.size()) {
        amount = new unsigned char[size];
        size_t i = 0;
        for (const auto& digit : t) {
            amount[i++] = digit;
        }
    }

    Money::Money(const Money& other) : size(other.size) {
        amount = new unsigned char[size];
        for (size_t i = 0; i < size; i++) {
            amount[i] = other.amount[i];
        }
    }

    Money::Money(Money&& other) noexcept : amount(other.amount), size(other.size) {
        other.amount = nullptr;
        other.size = 0;
    }

    // Деструкторы


    Money::virtual ~Money() noexcept {
        delete[] amount;
    }

    // Методы 

    // Размер массива

    size_t Money::getSize() const {
        return size;
    }

    // Получение денежной суммы в виде строки

    Money::string toString() const {
        string result;
        for (size_t i {0}; i < size; ++i) {
            result += to_string(amount[i]);
        }
        return result;
    }

    // Оператор присваивания 

    Money & Money:: operator= (const Money& other) {
        if (this != &other) {
            delete[] amount;
            size = other.size;
            amount = new unsigned char[size];
            for (size_t i = 0; i < size; i++) {
                amount[i] = other.amount[i];
            }
        }
        return *this;
    }

    // Перегрузка оператора сложения
    Money Money:: operator+ (const Money& other) const {
        size_t maxSize = max(size, other.size);
        Money result(maxSize);
        unsigned char carry = 0;
        for (size_t i = 0; i < maxSize; i++) {
            unsigned char sum = carry;
            if (i < size) {
                sum += amount[i];
            }
            if (i < other.size) {
                sum += other.amount[i];
            }
            result.amount[i] = sum % 10;
            carry = sum / 10;
        }
        if (carry > 0) {
            result.size++;
            unsigned char* newAmount = new unsigned char[result.size];
            for (size_t i = 0; i < result.size - 1; i++) {
                newAmount[i] = result.amount[i];
            }
            newAmount[result.size - 1] = carry;
            delete[] result.amount;
            result.amount = newAmount;
        }
        return result;
    }

    // Перегрузка оператора вычитания
    Money Money::operator- (const Money& other) const {
        if (*this < other) {
            throw std::invalid_argument("Result is negative");
        }
        Money result(size);
        unsigned char borrow = 0;
        for (size_t i = 0; i < size; i++) {
            unsigned char diff = borrow + amount[i];
            if (i < other.size) {
                diff -= other.amount[i];
            }

            if (diff < 0) {
                diff += 10;
                borrow = 1;
            }
            else {
                borrow = 0;
            }
            result.amount[i] = diff;
        }
        return result;
    }

    // Перегрузка оператора сравнения "меньше"
    bool Money::operator< (const Money& other) const {
        if (size < other.size) {
            return true;
        }
        else if (size > other.size) {
            return false;
        } 
        else {
            for (size_t i = size - 1; i >= 0; i--) {
                if (amount[i] < other.amount[i]) {
                    return true;
                }
                else if (amount[i] > other.amount[i]) {
                    return false;
                }
            }
          return false;
        }
    }

    bool Money::operator> (const Money& other) const {
        return other < *this;
    }

    // Перегрузка оператора сравнения "равно"
    bool operator==(const Money& other) const {
        if (size != other.size) {
            return false;
        }
        for (size_t i = 0; i < size; i++) {
            if (amount[i] != other.amount[i]) {
                return false;
            }
        }
        return true;
    }

    
ostream &Money::print(std::ostream &os){
    if (Money.size == 0){
        os << '0';
        return os;
    }
    for ( size_t i{Money.size - 1}; i >= 0; --i){
        os << static_cast<int>(amount[i]);
        
    }
    return os;
}


ostream &operator <<(ostream& os, Money& other) {
    return other.print(os);
}



 Money::Money(Money &&other) noexcept {
    cout << "Move constructor" << "\n";
    size = other.size;
    array = other.array;

    other.size = 0;
    other.array = nullptr;
}


