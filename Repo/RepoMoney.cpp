//
// Created by Vlad on 5/6/2022.
//

#include "RepoMoney.h"
#include <iostream>

#include "../ValidatorMoney/ValidatorMoney.h"
#include <fstream>

using namespace std;

RepoMoney::RepoMoney() = default;

RepoMoney::~RepoMoney() {
    fstream f(namefile);
    if (f.is_open())
        f.close();
}

RepoMoney::RepoMoney(const string &namefile) {
    try {
        this->namefile = namefile;
        ifstream f(namefile);
        int id;
        float billType;
        int numberOfBills;
        while (f.is_open()) {
            f >> id >> billType >> numberOfBills;
            if(id==0)
                throw MyException("Id must be different from 0");
            Money m(id, billType, numberOfBills);
            ValidatorMoney vm;
            vm.validate(m);
            mvect.push_back(m);
            if (f.eof())
                f.close();
        }
    }
    catch (exception &e) { cout << e.what() << endl; }
}

void RepoMoney::LoadToFile() {

    ofstream g(this->namefile);
    int count = 0;
    for (Money mo: mvect) {
        if (count == mvect.size() - 1)
            g << mo.getId() << " " << mo.getBillType() << " " << mo.getNumberOfBills();
        else {
            g << mo.getId() << " " << mo.getBillType() << " " << mo.getNumberOfBills() << endl;
            count++;
        }

    }
    g.close();
}


vector<Money> RepoMoney::getAllMoney() {
    return mvect;
}

Money RepoMoney::getById(int id) {
    for (auto &i: mvect)
        if (i.getId() == id)
            return i;

}

void RepoMoney::sortMVectD() {
    Money aux;
    for (int i = 0; i < mvect.size() - 1; i++)
        for (int j = i + 1; j < mvect.size(); j++) {
            if (mvect[i].getBillType() < mvect[j].getBillType()) {
                aux = mvect[i];
                mvect[i] = mvect[j];
                mvect[j] = aux;
            }
        }

}

void RepoMoney::increseBillCount(int count, int id) {
    for (auto &m: mvect)
        if (m.getId() == id)
            m.setNumberOfBills(m.getNumberOfBills() + count);
}


void RepoMoney::decreseBillCount(int count, int id) {
    for (auto &m: mvect)
        if (m.getId() == id)
            m.setNumberOfBills(m.getNumberOfBills() - count);
}

bool RepoMoney::verifyExistenceOfThisBill(float billType) {
    for (auto &i: mvect)
        if (i.getBillType() - billType < 1e-9 and i.getBillType() - billType >= 0) ///50-100
            return true;
    return false;
}

Money RepoMoney::getByBillType(float billType) {
    for (auto &i: mvect)
        if (i.getBillType() - billType < 1e-9)
            return i;

}

void RepoMoney::    addMoney(const Money &m) {
    if(m.getId()==0)
        throw MyException("The id must not be 0!");
    int ok=0;
    for(auto &money:mvect)
    {
        if(m.getId()==money.getId())
        {ok=1;break;}
    }
    if(ok==1)
        throw MyException("This id already exists!");
    this->mvect.push_back(m);
    this->LoadToFile();
}

void RepoMoney::useThisVector(vector<Money> &m) {

    for (int i = 0; i < mvect.size(); i++) {///repository money primeste acelasi bancnote pe care le avea inital
        mvect[i] = m[i];
    }
    LoadToFile();
}

void RepoMoney::deleteMoney(int id) {
    int ok = 0;
    for (int i = 0; i < mvect.size(); i++)
        if (mvect[i].getId() == id) {
            ok = 1;
            for (int j = i; j < mvect.size() - 1; j++)
                mvect[j] = mvect[j + 1];
        }
    if (ok == 0)
        throw MyException("There is no money with this id!");
    this->mvect.pop_back();
    this->LoadToFile();
}

void RepoMoney::updateMoney(Money &new_money, Money &old_money) {
    int ok = 0;
    for (auto &i: mvect)
        if (i.getId() == old_money.getId()) {
            ok = 1;
            i = new_money;
        }
    if (ok == 0)
        throw MyException("There is no money with this id!");
    this->LoadToFile();
}

