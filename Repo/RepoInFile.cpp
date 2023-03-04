//
// Created by 40742 on 27.04.2022.
//

#include "RepoInFile.h"
#include <fstream>
#include "../ValidatorBilete/ValidatorBilete.h"

RepoInFile::RepoInFile() {

}


RepoInFile::~RepoInFile() {
    fstream f(filename);
    if (f.is_open())
        f.close();
}

void RepoInFile::addBilet(const Bilet &b) {
    if (b.getId() == 0)
        throw MyException("The id must not be 0!");
    int ok = 0;
    for (auto &bilete: vect) {
        if (b.getId() == bilete.getId()) {
            ok = 1;
            break;
        }
    }
    if (ok == 1)
        throw MyException("This id already exists!");
    this->vect.push_back(b);
    this->save();
}

vector<Bilet> RepoInFile::getAll() {
    return vect;
}

void RepoInFile::deleteBilet(int id) {
    int ok = 0;
    for (int i = 0; i < vect.size(); i++)
        if (vect[i].getId() == id) {
            ok = 1;
            for (int j = i; j < vect.size() - 1; j++)
                vect[j] = vect[j + 1];
        }
    if (ok == 0)
        throw MyException("There is no ticket with this id!");
    this->vect.pop_back();
    this->save();
}

void RepoInFile::updateBilet(Bilet &new_bilet, Bilet &old_bilet) {
    int ok = 0;
    for (auto &i: vect)
        if (i.getId() == old_bilet.getId()) {
            ok = 1;
            i = new_bilet;
        }
    if (ok == 0)
        throw MyException("There is ticket with this id!");
    this->save();
}

Bilet RepoInFile::getById(int i) {
    for (int j = 0; j < vect.size(); j++)
        if (vect[j].getId() == i)
            return vect[j];
    throw std::runtime_error("No entity with specified id found");

}

RepoInFile::RepoInFile(const string &f_name) {
    try{
        this->filename = f_name;
        ifstream f(f_name);
        while (f.is_open()) {
            int id;
            string cod;
            string zi;
            float pret;
            int stock;
            f >> id >> cod >> zi >> pret >> stock;
//            if(id==0)
//                throw MyException("The id mush be different from 0");
            Bilet e(id, cod, zi, pret, stock);
            ValidatorBilete vb;
            vb.validate(e);
            this->vect.push_back(e);
            if (f.eof())
                f.close();
        }
    }
    catch(MyException &e){cout<<e.what()<<endl;}


}

void RepoInFile::save() {
    ofstream g(this->filename);
    int count = 0;
    for (Bilet b: vect) {
        if (count == vect.size() - 1)
            g << b.getId() << " " << b.getCod() << " " << b.getZi() << " " << b.getPret() << " " << b.getStock();
        else {
            g << b.getId() << " " << b.getCod() << " " << b.getZi() << " " << b.getPret() << " " << b.getStock()
              << endl;
            count++;
        }
    }
    g.close();

}

int RepoInFile::size_file() {
    return (int) vect.size();
}

void RepoInFile::decreseCount(int id, int amount) {
    for (auto &b: vect)
        if (b.getId() == id)
            b.setStock(b.getStock() - amount);
}


