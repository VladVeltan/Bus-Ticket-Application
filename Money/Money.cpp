//
// Created by Vlad on 5/4/2022.
//

#include "Money.h"
#include <utility>

using namespace std;

Money::Money() {

}

Money::~Money() {


}

Money::Money(const Money &money) {
    this->id=money.id;
    this->billType = money.billType;
    this->numberOfBills = money.numberOfBills;
}

Money::Money(int id,float billType, int numberOfBills) {
    this->numberOfBills = numberOfBills;
    this->billType = billType;
    this->id = id;

}

void Money::setBillType(float billType) {
    this->billType = billType;
}

float Money::getBillType() const {
    return this->billType;
}

void Money::setNumberOfBills(int numberOfBills) {
    this->numberOfBills = numberOfBills;
}

int Money::getNumberOfBills() const {
    return this->numberOfBills;
}

float Money::howMuchMoney() const {
    return getBillType() * getNumberOfBills();
}

void Money::setId(int id) {
    this->id = id;
}

int Money::getId() const {
    return this->id;
}

bool Money::operator==(const Money &m) const {
    if ((this->billType - m.billType) < 1e-9 and this->numberOfBills == m.numberOfBills)
        return true;
    return false;
}

Money &Money::operator=(const Money &m) {
    this->setBillType(m.billType);
    this->setId(m.id);
    this->setNumberOfBills(m.numberOfBills);
    return *this;
}

ostream &operator<<(ostream &out, Money &m) {
    out << m.id << " ";
    out << m.billType << " ";
    out << m.numberOfBills;
    cout<<endl;
    return out;
}
