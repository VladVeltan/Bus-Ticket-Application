//
// Created by 40742 on 27.04.2022.
//

#ifndef LAB910_IREPO_H
#define LAB910_IREPO_H

#include <iostream>
#include <vector>
#include "../Bilet/Bilet.h"

class IRepo {
protected:
    vector<Bilet> vect;
public:
    virtual void addBilet(const Bilet &b) = 0;

    virtual vector<Bilet> getAll() = 0;

    virtual void deleteBilet(int id) = 0;

    virtual void updateBilet(Bilet &new_bilet, Bilet &old_bilet) = 0;

    virtual Bilet getById(int i) = 0;
};


#endif //LAB910_IREPO_H
