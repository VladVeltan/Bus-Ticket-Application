//
// Created by Vlad on 5/14/2022.
//

#include "ValidatorMoney.h"

void ValidatorMoney::validate(const Money &money) {
    if (money.getId() <= 0) {
        throw MyException("Each money must have a unique id!");
    } else if (money.getNumberOfBills() < 0) {
        throw MyException("The number of bills or coins must be at least 1");
    } else if (checkDouble(money.getBillType(), 0.10) and checkDouble(money.getBillType(), 1) and
               checkDouble(money.getBillType(), 0.50) and checkDouble(money.getBillType(), 5) and
               checkDouble(money.getBillType(), 10) and checkDouble(money.getBillType(), 50) and
               checkDouble(money.getBillType(), 100)) {
        throw MyException("Each bill or note must have a value of 0.10,0.50,1,5,10,50,100 !");
    }

}
bool ValidatorMoney::checkDouble(float x, float y) {
    if (x - y < 1e-9 and x - y >= 0)
        return true;
    return false;
}
