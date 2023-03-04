//
// Created by Vlad on 5/14/2022.
//

#ifndef LAB910_VALIDATORMONEY_H
#define LAB910_VALIDATORMONEY_H
#include "../Exceptions/MyException.h"
#include "../Money/Money.h"

class ValidatorMoney {
private:
    Money money;
public:
    ValidatorMoney()=default;
    ~ValidatorMoney()=default;
    void validate(const Money &money);
    bool checkDouble(float x,float y);
};


#endif //LAB910_VALIDATORMONEY_H
