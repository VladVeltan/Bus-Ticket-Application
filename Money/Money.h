//
// Created by Vlad on 5/4/2022.
//

#ifndef LAB910_MONEY_H
#define LAB910_MONEY_H
#include <iostream>

using namespace std;
class Money {
private:
    float billType;
    int numberOfBills;
    int id;
public:
    Money();
    Money(const Money &money);
    Money(int id,float billType,int numberOfBills);
    ~Money();
    void setBillType(float billType);
    void setNumberOfBills(int numberOfBills);
    float getBillType() const;
    int getNumberOfBills() const;
    float howMuchMoney() const;
    void setId(int id);
    int getId() const;
    bool operator==(const Money &m) const;
    Money &operator=(const Money &m);
    friend ostream &operator <<(ostream &out,Money &m);

};


#endif //LAB910_MONEY_H
