//
// Created by 40742 on 20.04.2022.
//

#ifndef LAB9_10VLADVELTAN_REPO_H
#define LAB9_10VLADVELTAN_REPO_H

#include "../Bilet/Bilet.h"
#include <vector>
#include "IRepo.h"

using namespace std;

class RepoInMemory : public IRepo {
protected:
    vector<Bilet> vect;

public:
    RepoInMemory();

    ~RepoInMemory();

    void addBilet(const Bilet &b) override;

    vector<Bilet> getAll() override;

    void deleteBilet(int id) override;

    void updateBilet(Bilet &new_bilet, Bilet &old_bilet) override;

    Bilet getById(int i) override;

};


#endif //LAB9_10VLADVELTAN_REPO_H
