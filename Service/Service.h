//
// Created by 40742 on 25.04.2022.
//

#ifndef LAB910_SERVICE_H
#define LAB910_SERVICE_H
#include "../Repo/RepoInMemory.h"
#include "../Money/Money.h"
#include "../Repo/RepoInFile.h"
#include "../Repo/RepoMoney.h"
#include "../ValidatorBilete/ValidatorBilete.h"
#include "../Exceptions/MyException.h"
#include "../ValidatorMoney/ValidatorMoney.h"
class Service {
private:
    RepoInFile repo;
    RepoMoney repomoney;
    ValidatorBilete validatorBilete;
    ValidatorMoney validatorMoney;
public:
    Service();
    ~Service();
    Service(RepoInFile &r,RepoMoney &rm,const ValidatorBilete& validatorBilete,const ValidatorMoney& validatorMoney);
    void addBiletS(const Bilet &b);
    void deleteBiletS(int id);
    void updateBiletS(Bilet new_bilet,Bilet old_bilet);
    void addMoneyS(const Money &m);
    void deleteMoneyS(int id);
    void updateMoneyS(Money new_money,Money old_money);
    vector<Bilet> getAllS();
    Bilet getByIdS(int id);
    void buyTicket(int id,int amount,vector <float> v1, vector <int>v2);
    vector <Bilet> listProductByaGivenCode(const string& code);
    vector <Money> getAllMoneyS();
    bool idInRepoBilete(int id);
    bool idInRepoMoney(int id);


};


#endif //LAB910_SERVICE_H
