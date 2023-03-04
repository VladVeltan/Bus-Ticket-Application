//
// Created by 40742 on 20.04.2022.
//

#include "RepoInMemory.h"

RepoInMemory::RepoInMemory() = default;

RepoInMemory::~RepoInMemory() = default;

void RepoInMemory::addBilet(const Bilet &p) {
    vect.push_back(p);

}

vector<Bilet> RepoInMemory::getAll() {
    return this->vect;
}

Bilet RepoInMemory::getById(int i) {
    for (int j = 0; j < vect.size(); j++)
        if (vect[j].getId() == i)
            return vect[j];
    throw std::runtime_error("No entity with specified id found");
}

void RepoInMemory::deleteBilet(int id) {
    for (int i = 0; i < vect.size(); i++)
        if (vect[i].getId() == id)
            for (int j = i; j < vect.size() - 1; j++)
                vect[j] = vect[j + 1];
    vect.pop_back();

}

void RepoInMemory::updateBilet(Bilet &new_bilet, Bilet &old_bilet) {
    for (auto &i: vect)
        if (i.getId() == old_bilet.getId())
            i = new_bilet;

}
