//
// Created by Vlad on 5/14/2022.
//
#include "ValidatorBilete.h"

ValidatorBilete::ValidatorBilete() = default;

ValidatorBilete::~ValidatorBilete() = default;

void ValidatorBilete::validate(const Bilet &bilet) {
    if (bilet.getId() <0) {
        throw MyException("Each ticket must have a positive id.");
    } else if (bilet.getStock() <0) {
        throw MyException("The stock for each ticket must be postitive");
    } else if (bilet.getPret() <0) {
        throw MyException("The price of each ticket must be positive");
    } else if (bilet.getZi() != "Luni" and bilet.getZi() != "Marti" and bilet.getZi() != "Miercuri" and
               bilet.getZi() != "Joi" and bilet.getZi() != "Vineri" and bilet.getZi() != "Sambata" and
               bilet.getZi() != "Duminica") {
        throw MyException(
                "The day of the ride must be one of the following : Luni , Marti ,Miercuri , Joi, Vineri , Sambata or Duminica");
    } else if ((bilet.getCod().size() < 4 or bilet.getCod().size() > 5)) {
        throw MyException("The code for the ticket must be of the: XX-XX or X-XX or XX-X type");
    }
}


