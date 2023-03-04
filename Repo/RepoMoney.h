//
// Created by Vlad on 5/6/2022.
//

#ifndef LAB910_REPOMONEY_H
#define LAB910_REPOMONEY_H
#include "../Money/Money.h"
#include <vector>
#include <string>
#include <fstream>

using namespace std;
class RepoMoney {
private:
    vector <Money> mvect;
    string namefile;
public:
    RepoMoney();
    ~RepoMoney();
    RepoMoney(const string &namefile);
    void LoadToFile();
    vector <Money> getAllMoney();
    Money getById(int id);
    void sortMVectD();
    void increseBillCount(int count,int id);
    void decreseBillCount(int count,int id);
    bool verifyExistenceOfThisBill(float billType);
    Money getByBillType(float billType);
    void addMoney(const Money &m);
    void deleteMoney(int id);
    void updateMoney(Money &new_money,Money &old_money);
    void useThisVector(vector <Money> &m);
    ///getByBillType
};


#endif //LAB910_REPOMONEY_H
