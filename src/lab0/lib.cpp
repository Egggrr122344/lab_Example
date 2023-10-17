
#include "lib.h"
#include <exception>
#include <stdexcept>

  Money::Money() {
    size = 1;
    amount = new unsigned char[size];
    amount[0] = 0;
}

// Конструктор с параметром
Money::Money(const size_t& size, unsigned char t) {
    if (size == 0) {
        throw invalid_argument("Size must be greater than 0");
    }
    this->size = size;
    amount = new unsigned char[size];
    for (size_t i = 0; i < size; i++) {
        amount[i] = t;
    }
}

// Конструктор с использованием initializer_list
Money::Money(const initializer_list<unsigned char>& t) {
    if (t.size() == 0) {
        throw invalid_argument("Initializer list must not be empty");
    }
    size = t.size();
    amount = new unsigned char[size];
    size_t i = 0;
    for (const auto& digit : t) {
        amount[i] = digit;
        i++;
    }
}

// Конструктор копирования
Money::Money(const Money& other) {
    size = other.size;
    amount = new unsigned char[size];
    for (size_t i = 0; i < size; i++) {
        amount[i] = other.amount[i];
    }
}

// Конструктор перемещения
Money::Money(Money&& other) noexcept {
    size = other.size;
    amount = other.amount;
    other.amount = nullptr;
}

// Деструктор
Money::~Money() {
    delete[] amount;
}

// Метод для установки значения денежной суммы с использованием initializer_list
void Money::setAmount(const initializer_list<unsigned char>& t) {
    if (t.size() == 0) {
        throw invalid_argument("Initializer list must not be empty");
    }
    delete[] amount;
    size = t.size();
    amount = new unsigned char[size];
    size_t i = 0;
    for (const auto& digit : t) {
        amount[i] = digit;
        i++;
    }
}

// Метод для вывода значения денежной суммы
void Money::printAmount() const {
    cout << "Money: ";
    for (size_t i = size - 1; i < size; i--) {
            cout << static_cast<int>(amount[i]);
        if (i == 2) {
            cout << ".";
        }
    }
    cout << endl;
}

// Перегрузка оператора сложения
Money Money::operator+(const Money& other) const {
    size_t maxSize = max(size, other.size);
    size_t minSize = min(size, other.size);
    Money result(maxSize);
    unsigned char carry = 0;
    for (size_t i = 0; i < minSize; i++) {
        unsigned char sum = amount[i] + other.amount[i] + carry;
        result.amount[i] = sum % 10;
        carry = sum / 10;
    }
    for (size_t i = minSize; i < maxSize; i++) {
        unsigned char sum = amount[i] + carry;
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

// Перегрузка оператора присваивания

 Money& Money::operator=(const Money& other) {
        if (this != &other) {
            Money value(other.size);
        
        for (size_t i {0}; i < other.size; i ++) {
            value.amount[i] = other.amount[i];
        }

        }
        return *this;
    }


// Перегрузка оператора вычитания
Money Money::operator-(const Money& other) const {
    if (*this < other) {
        throw invalid_argument("Subtraction result is negative");
    }
    size_t maxSize = max(size, other.size);
    size_t minSize = min(size, other.size);
    Money result(maxSize);
    unsigned char borrow = 0;
    for (size_t i = 0; i < minSize; i++) {
        unsigned char diff = amount[i] - other.amount[i] - borrow;
        if (diff >= 0) {
            result.amount[i] = diff;
            borrow = 0;
        } 
        else {
            result.amount[i] = diff + 10;
            borrow = 1;
        }
    }
    for (size_t i = minSize; i < maxSize; i++) {
        unsigned char diff = amount[i] - borrow;
        if (diff >= 0) {
            result.amount[i] = diff;
            borrow = 0;
        } 
        else {
            result.amount[i] = diff + 10;
            borrow = 1;
        }
    }
    return result;
}

// Перегрузка оператора больше
bool Money::operator>(const Money& other) const {
    if (size > other.size) {
        return true;
    } 
    else if (size < other.size) {
        return false;
    } 
    else {
        for (size_t i = size - 1; i < size; i--) {
            if (amount[i] > other.amount[i]) {
                return true;
            } else if (amount[i] < other.amount[i]) {
                return false;
            }
        }
        return false;
    }
}

// Перегрузка оператора меньше
bool Money::operator<(const Money& other) const {
    if (size < other.size) {
        return true;
    }
    else if (size > other.size) {
        return false;
    } 
    else {
        for (size_t i = size - 1; i < size; i--) {
            if (amount[i] < other.amount[i]) {
                return true;
            } else if (amount[i] > other.amount[i]) {
                return false;
            }
        }
        return false;
    }
}

// Перегрузка оператора равно
bool Money::operator==(const Money& other) const {
    if (size != other.size) {
        return false;
    } 
    else {
        for (size_t i = 0; i < size; i++) {
            if (amount[i] != other.amount[i]) {
                return false;
            }
        }
        return true;
    }
}

size_t Money::getSize() {
    return size;
}

unsigned char* Money::getArray() {
    return amount;
}
   