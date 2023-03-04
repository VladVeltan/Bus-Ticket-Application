//
// Created by 40742 on 20.04.2022.
//

#ifndef LAB9_10VLADVELTAN_PRODUS_H
#define LAB9_10VLADVELTAN_PRODUS_H

#include <string>
#include <iostream>
using namespace std;

class Bilet {
private:
    int id;
    string cod;
    string zi;
    float pret;
    int stock;
public:
    Bilet();

    ~Bilet();

    Bilet(const Bilet &p);

    Bilet(int id, string cod, string zi, float pret,int stock);

    int getId() const;

    void setId(int id);

    string getCod() const;

    void setCod(string cod);

    float getPret() const;

    void setPret(float pret);

    void setZi(string zi);
    void setStock(int stock);
    int getStock() const;

    string getZi() const;

    bool operator==(const Bilet &b) const;

    Bilet &operator=(const Bilet &b);

    friend ostream &operator<<(ostream &out, Bilet &b);

};


#endif //LAB9_10VLADVELTAN_PRODUS_H
