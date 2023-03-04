//
// Created by Vlad on 5/14/2022.
//

#ifndef LAB910_VALIDATORBILETE_H
#define LAB910_VALIDATORBILETE_H
#include "../Exceptions/MyException.h"
#include "../Bilet/Bilet.h"
class ValidatorBilete{
private:
    Bilet bilet;
public:
    ValidatorBilete();
    ~ValidatorBilete();
    void validate(const Bilet& bilet);


};
#endif //LAB910_VALIDATORBILETE_H
