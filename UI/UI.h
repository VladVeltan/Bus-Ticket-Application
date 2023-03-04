//
// Created by 40742 on 27.04.2022.
//

#ifndef LAB910_UI_H
#define LAB910_UI_H
#include "../Service/Service.h"
#include "../Exceptions/MyException.h"
class UI {
private:
    Service serv;
public:
    UI();
    ~UI();
    UI(Service &ser);
    void addBiletUi();
    void deleteBiletUi();
    void listAllUi();
    void updateBiletUi();
    void buyBilet();
    void listTicketsByAGivenName();
    static void AdminOptions();
    static void UserOptions();
    void runMenu();
    void addMoneyUi();
    void deleteMoneyUi();
    void updateMoneyUi();
    void listAllMoney();
};


#endif //LAB910_UI_H
