//
// Created by 40742 on 27.04.2022.
//

#ifndef LAB910_REPOINFILE_H
#define LAB910_REPOINFILE_H

#include "IRepo.h"
#include "../Bilet/Bilet.h"
#include <vector>
#include <iostream>

class RepoInFile : public IRepo {
private:
    string filename;
public:
    RepoInFile();

    ~RepoInFile();

    RepoInFile(const string &f_name);

    void addBilet(const Bilet &b) override;

    vector<Bilet> getAll() override;

    void deleteBilet(int id) override;

    void updateBilet(Bilet &new_bilet, Bilet &old_bilet) override;

    Bilet getById(int i) override;
    int size_file();
    void decreseCount(int id,int amount);
    void save();
};


#endif //LAB910_REPOINFILE_H
