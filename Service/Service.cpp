//
// Created by 40742 on 25.04.2022.
//

#include "Service.h"

Service::Service() = default;

Service::~Service() = default;

Service::Service(RepoInFile &r, RepoMoney &rm,
                 const ValidatorBilete &validatorBilete,const ValidatorMoney& validatorMoney) {///:repo(repo) initalziron list construcor
    this->repo = r;
    this->repomoney = rm;
    this->validatorBilete = validatorBilete;
    this->validatorMoney=validatorMoney;
}

void Service::addBiletS(const Bilet &b) {
    validatorBilete.validate(b);
    repo.addBilet(b);

}

void Service::deleteBiletS(int id) {

    repo.deleteBilet(id);

}

vector<Bilet> Service::getAllS() {
    return repo.getAll();
}

void Service::updateBiletS(Bilet new_bilet, Bilet old_bilet) {

    validatorBilete.validate(new_bilet);
    repo.updateBilet(new_bilet, old_bilet);

}

Bilet Service::getByIdS(int id) {
    return repo.getById(id);
}

void
Service::buyTicket(int id, int amount, vector<float> v1, vector<int> v2) { ///ar trb sa primesc un vector de bancnote
    //nu este id-ul
    ///verifica daca is locuri in autobuz
    ///ar trb sa poti cumpara mai multe bilete pe o ruta
    ///trb sa fie si monede
    ///trb sa fie floaturi
    ///trb sa adaug banii de client in repo money
//    introducem banii clientului in repo money
//    parcurgem tot repo si verificam daca exista deja un obiect money cu billtype-ul introdus sau daca trb sa creem unul
    if(!idInRepoBilete(id))
        throw MyException("There is no ticket with this id");
    if(repo.getById(id).getStock()<amount)
        throw MyException("There aren't enough tickets for this ride!");

    repomoney.sortMVectD();///sortam repomoney
    vector<Money> undo;
    undo = repomoney.getAllMoney();
    vector<float> bancnoteRestClient;
    vector<int> nrBancnoteRestClient;
    float howMuchMoneyTheClientEntered = 0;
    for (int i = 0; i < v1.size(); i++) {
        howMuchMoneyTheClientEntered = howMuchMoneyTheClientEntered + v1[i] * float(v2[i]);//nr bancnote* val bancnote
        if (repomoney.verifyExistenceOfThisBill(v1[i]))///verific daca exista acest tip de moneda in repo
        {
            repomoney.increseBillCount(v2[i], repomoney.getByBillType(v1[i]).getId());///creste nr de bancnote in repo
        } else {
            if(v1[i]<=0)
            {
                throw MyException("Bills or coins entered must have one of the following values:0.10,0.50,1,5,10,50,100");
            }
            int random = 1+ (rand() % 100);
            int ok=1;
            while(ok)
            {
                if(idInRepoMoney(random))
                { random = 1+ (rand() % 100);}
                else{
                    ok=0;
                }
            }
            Money newm(random, v1[i], v2[i]);///cream enitate noua
            repomoney.addMoney(newm); ///adugam in mvect din repo
            repomoney.sortMVectD();///sortam iar vectorul
        }
    }
    float changeToGive;
    changeToGive = howMuchMoneyTheClientEntered - (repo.getById(id).getPret() * float(amount));//nr bilete * pret
    if (changeToGive == 0)
        cout << "Thanks for purchase, you don't have any change left!" << endl;
    if (changeToGive < 0)
        cout << "The bills you enter dont cover the price of the items" << endl;
    else {
        for (auto &m: repomoney.getAllMoney())///int i = int(repomoney.getAllMoney().size() - 1); i >= 0; i--
        {
            int nrbills = m.getNumberOfBills();
            float billType = m.getBillType();
            if (billType < changeToGive and nrbills > 0) {
                while (float(nrbills) * billType > changeToGive) { nrbills--; }
                changeToGive =
                        changeToGive - (float(nrbills) * billType); ///scad nr maxim de bancnote din rest (38-30);
                repomoney.decreseBillCount(nrbills, m.getId());///scad in repo nr de bancnote de un anumit fel
                bancnoteRestClient.push_back(billType);
                nrBancnoteRestClient.push_back(nrbills);
            }
            if (changeToGive == 0) { break; }
        }
        if (changeToGive > 0) {
            cout << "Sorry , we dont have enough money to give you change, try again later!";
            repomoney.useThisVector(undo);
        } else {//ar trb afisat ce bancnote primeste ca rest
            cout << "Thanks for buying!";
            for (int i = 0; i < nrBancnoteRestClient.size(); i++) {
                cout << "Your recevied " << nrBancnoteRestClient[i] << "bill notes of " << bancnoteRestClient[i]
                     << " as change! " << endl;

            }
            repo.decreseCount(id, amount);///scade stockul la bilete pt o anumita cursa
        }
    }
    repo.save();
    repomoney.LoadToFile();
    nrBancnoteRestClient.clear();
    bancnoteRestClient.clear();


}

vector<Bilet> Service::listProductByaGivenCode(const string &code) {
    vector<Bilet> ret;
    for (auto &b: repo.getAll())
        if (b.getCod() == code)
            ret.push_back(b);

    return ret;
}

vector<Money> Service::getAllMoneyS() {
    return repomoney.getAllMoney();
}

bool Service::idInRepoBilete(int id) {
    vector<Bilet> v;
    v = repo.getAll();
    for (auto &i: v)
        if (i.getId() == id)
            return true;
    return false;
}


void Service::addMoneyS(const Money &m) {
    validatorMoney.validate(m);
    repomoney.addMoney(m);

}

bool Service::idInRepoMoney(int id) {
    vector<Money> v;
    v = repomoney.getAllMoney();
    for (auto &i: v)
        if (i.getId() == id)
            return true;
    return false;
}

void Service::deleteMoneyS(int id) {
    repomoney.deleteMoney(id);
}

void Service::updateMoneyS(Money new_money, Money old_money) {
    validatorMoney.validate(new_money);
    repomoney.updateMoney(new_money, old_money);
}
