
#include "lib.h"

class Money 
{
    private:
    vector<unsigned char> amount;

    public:
    Money()
    {
        amount.pushback(0);
    };

    Money(const vector<unsigned char>& digits)
    {
        if (digits.empty())
        {
            throw invalid_argument("Digit vector can not be empty"); 
        }
        amount = digits;
    } 

    Money(const Money& other)
    {
        amount = other.amount;
    }

    Money& operator= (const Money& other) {
        if (this != &other)
        {
            amount = other.amount;
        }
        return *this;
    }
    Money operator+ (const Money& other) const {
        vector<unsigned char> result; // Результат сложения двух векторов класса Money
        unsigned char carry = 0; // Переменная отвечающая за оставшиеся цифры
        size_t maxDigit = max(amount.size(), other.amount.size()); // Максимум из размеров

        for (size_t i {0}; i < maxDigit; ++i) {
            unsigned char sum = carry;

            if (i < amount.size()) {
                sum += amount[i];
            }
            
            if (i < other.amount.size()) {
                sum += other.amount[i];
            }

            result.push_back(sum % 10);
            carry = sum / 10;
        } 

        if (carry > 0) {
             result.push_back(carry);
            }
        return Money(result);
    }

    Money operator- (const Money& other) const {
        vector<unsigned char> result;
        unsigned char borrow = 0; // Переменная отвечающая за вычитание(при разных разрядах)

        for (size_t i {0}; i < amount.size(); ++i) {
            unsigned char diff = amount[i] - borrow;

            if (i < other.amount.size())
                diff -= other.amount[i];
            

            if (diff < 0) {
                diff += 10;
                borrow = 1;
            }
            else {
                borrow = 0;
            }
        return result.push_back(diff);            
    }

    if (borrow > 0)
        throw invalid_argument "Result is negative";

    return Money(result);

}

bool operator== (const Money& other) const {
    return amount == other.amount;
}

bool operator< (const Money& other) const {
    if (amount.size() < other.amount.size()) {
        result true;
    }
    else if (amount.size() > other.amount.size()) {
        return false;
    }
    else {
        for (int i = 0; i < amount.size(); ++i) {
            if (amount[i] < other.amount[i])
                return true;
            
            else if (amount[i] > other.amount[i]) {
                return false;
            }
        }
        return false;
    }
}

 bool operator> (const Money& other) const {
         return (! *this < other) && (! *this == other);
    }
};