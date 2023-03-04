//
// Created by 40742 on 20.04.2022.
//

#include "Bilet.h"
#include <utility>

using namespace std;

int Bilet::getId() const {
    return id;
}

void Bilet::setId(int id) {
    Bilet::id = id;
}

string Bilet::getCod() const {
    return cod;
}

void Bilet::setCod(string cod) {
    Bilet::cod = std::move(cod);
}

float Bilet::getPret() const {
    return pret;
}

void Bilet::setPret(float pret) {
    Bilet::pret = pret;
}

Bilet::Bilet() {
    this->id = 0;
    this->pret = 0;
    this->cod = "";
    this->zi = "";
    this->stock = 0;

}

Bilet::~Bilet() = default;

Bilet::Bilet(const Bilet &p) {
    this->id = p.id;
    this->cod = p.cod;
    this->pret = p.pret;
    this->zi = p.zi;
    this->stock = p.stock;
}

void Bilet::setZi(string zi) {
    this->zi = std::move(zi);

}

string Bilet::getZi() const {
    return this->zi;
}

Bilet::Bilet(int id, string cod, string zi, float pret, int stock) {
    this->id = id;
    this->cod = std::move(cod);
    this->pret = pret;
    this->zi = std::move(zi);
    this->stock = stock;
}

bool Bilet::operator==(const Bilet &b) const {
    if (this->cod == b.cod and this->zi == b.zi and (this->pret - b.pret) < 1e-9 and this->stock == b.stock)
        return true;
    return false;
}

Bilet &Bilet::operator=(const Bilet &b) {
    this->setZi(b.zi);
    this->setPret(b.pret);
    this->setId(b.id);
    this->setCod(b.cod);
    this->setStock(b.stock);
    return *this;
}

ostream &operator<<(ostream &out, Bilet &e) {
    out << "id: " << e.id << " ";
    out << "cod: " << e.cod << " ";
    out << "pret: " << e.pret << " ";
    out << "zi: " << e.zi << " ";
    out << "stock:" << e.stock;
    out << endl;
    return out;
}

void Bilet::setStock(int stock) {
    this->stock = stock;

}

int Bilet::getStock() const {
    return this->stock;
}


