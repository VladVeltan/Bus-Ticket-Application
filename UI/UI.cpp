//
// Created by 40742 on 27.04.2022.
//

#include "UI.h"
#include "../Money/Money.h"

using namespace std;

UI::UI() = default;

UI::~UI() = default;

void UI::addBiletUi() {
    try {
        int id;
        string cod;
        string zi;
        float pret;
        int stock;
        cout << "Enter id:" << endl;
        if(!(cin >> id))
        {   cin.clear();
            throw MyException("Id must be an integer!");
        }
        cout << "Enter ticket code:" << endl;
        cin >> cod;
        cout << "Enter ticket day:" << endl;
        cin >> zi;
        cout << "Enter the price of the ticket" << endl;
        if(!(cin >> pret))
        {   cin.clear();
            throw MyException("The price must be an float or integer!");
        }
        cout << "Enter the how many tickets for the ride" << endl;
        if(!(cin >> stock))
        {   cin.clear();
            throw MyException("Stock must be an integer!");
        }
        Bilet bilet(id, cod, zi, pret, stock);
        serv.addBiletS(bilet);
        cout << "Add complete!";
    }
    catch (MyException &e) { cout << e.what() << endl; }
}

void UI::deleteBiletUi() {
    try {
        cout << "Give the id of the ticket you want to delete:" << endl;
        int id;
        if(!(cin >> id))
        {   cin.clear();
            throw MyException("Id must be an integer!");
        }
        serv.deleteBiletS(id);
    }
    catch (exception &e) { cout << e.what() << endl; }
}

void UI::listAllUi() {
    vector<Bilet> v;
    v = serv.getAllS();
    for (auto &i: v)
        cout << i;

}

void UI::updateBiletUi() {
    try {
        int idvechi;
        string cod;
        string zi;
        float pret;
        int stock;
        cout << "Give the id for the ticket you want to update:" << endl;
        int id;
        if(!(cin >> idvechi))
        {   cin.clear();
            throw MyException("Id must be an integer!");
        };
        cout << "Enter new id:" << endl;
        if(!(cin >> id))
        {   cin.clear();
            throw MyException("Id must be an integer!");
        }
        cout << "Enter new ticket code:" << endl;
        cin >> cod;
        cout << "Enter new ticket day:" << endl;
        cin >> zi;
        cout << "Enter new the price of the ticket" << endl;
        if(!(cin >> pret))
        {   cin.clear();
            throw MyException("The price must be an float or integer!");
        }
        cout << "Enter the new number of tickets for the ride" << endl;
        if(!(cin >> stock))
        {   cin.clear();
            throw MyException("Stock must be an integer!");
        }
        Bilet bilet(id, cod, zi, pret, stock);
        for (auto &bil: serv.getAllS()) {
            if (idvechi == bil.getId()) {
                serv.updateBiletS(bilet, bil);
            }
        }
    }
    catch (exception &e) { cout << e.what() << endl; }

}

void UI::UserOptions() {
    cout << "1.Buy Ticket" << endl;
    cout << "2.Show all tickets" << endl;
    cout << "3.Show all money in the ticket jukebox" << endl;
    cout << "x.Exit" << endl;
}

void UI::AdminOptions() {
    cout << "1.Add Bilet" << endl;
    cout << "2.Delete Bilet" << endl;
    cout << "3.Update Bilet" << endl;
    cout << "4.Add Money " << endl;
    cout << "5.Delete Money" << endl;
    cout << "6.Update Money" << endl;
    cout << "7.List all Bilet" << endl;
    cout << "8.List all tickets by a given code " << endl;
    cout << "9.List all money" << endl;
    cout << "x.Exit" << endl;
}

void UI::runMenu() {
    char option, option2, option3;
    bool ok = true;
    vector<Bilet> v;
    while (ok) {
        cout << "a.Admin" << endl;
        cout << "u.User" << endl;
        cout << "x.Exit" << endl;
        cout << "Select between Admin or User" << endl;
        cin >> option;
        switch (option) {
            case 'a': {
                AdminOptions();
                cout << "Give the option you want: ";
                cin >> option2;
                switch (option2) {
                    case '1': {
                        addBiletUi();
                        break;
                    }
                    case '2': {
                        deleteBiletUi();
                        break;
                    }
                    case '3': {
                        updateBiletUi();
                        break;
                    }
                    case '4': {
                        addMoneyUi();
                        break;
                    }

                    case '5': {
                        deleteMoneyUi();
                        break;
                    }
                    case '6': {
                        updateMoneyUi();
                        break;
                    }
                    case '7': {
                        listAllUi();
                        break;
                    }
                    case '8': {
                        listTicketsByAGivenName();
                        break;
                    }
                    case '9': {
                        listAllMoney();
                        break;
                    }
                    case 'x': {
                        break;
                    }
                    default:
                        cout << "Wrong option! Try again!" << endl;
                }
                break;
            }
            case 'u': {
                UserOptions();
                cout << "Give the option you want: " << endl;
                cin >> option3;
                switch (option3) {
                    case '1': {
                        buyBilet();
                        break;
                    }
                    case '2': {
                        listAllUi();
                        break;
                    }
                    case '3': {
                        listAllMoney();
                        break;
                    }
                    case 'x': {
                        break;
                    }
                    default:
                        cout << "Wrong option! Try again!" << endl;
                        break;
                }
                break;
            }
            case 'x': {
                ok = false;
                break;
            }
            default:
                cout << "Wrong option! Try again!" << endl;
        }

    }

}


void UI::buyBilet() {
    try {
        int id;
        int amount;
        float billType;
        int number;
        int billCount;
        vector<float> v1;
        vector<int> v2;
        cout << "Enter the id of the ticket you want to buy:" << endl;
        if(!(cin >> id))
        {   cin.clear();
            throw MyException("Id must be an integer!");
        }
        cout << "Enter the amount of tickets you want to buy" << endl;
        if(!(cin >> amount))
        {   cin.clear();
            throw MyException("Amount must be an int!");
        }
        cout << "Enter how many bill notes you want to enter" << endl;
        if(!(cin >> number))
        {   cin.clear();
            throw MyException("Number must be an integer!");
        }
        for (int i = 0; i < number; i++) {
            cout << "Enter bill" << endl;
            if(!(cin >> billType))
            {   cin.clear();
                throw MyException("Bill Type must be an integer or float!");
            }
            v1.push_back(billType);
            cout << "Enter how many bill of that type you want to enter" << endl;
            if(!(cin >> billCount))
            {   cin.clear();
                throw MyException("Bill count must be an integer!");
            }
            v2.push_back(billCount);
        }
        serv.buyTicket(id, amount, v1, v2);
    }
    catch(MyException &e){cout<<e.what()<<endl;};
}

void UI::listTicketsByAGivenName() {
    cout << "Enter the code of the ticket you want to take:" << endl;
    string code;
    if(!(cin >> code))
    {   cin.clear();
        throw MyException("Thicket code must be a string!");
    }
    vector<Bilet> v;
    v = serv.listProductByaGivenCode(code);
    for (auto &b: v)
        cout << b;
}

UI::UI(Service &ser) {
    this->serv = ser;
}


void UI::listAllMoney() {
    vector<Money> v;
    v = serv.getAllMoneyS();
    for (auto &m: v)
        cout << m;

}

void UI::addMoneyUi() {
    try {
        float billType;
        int numberOfBills;
        int id;
        cout << "Enter the id of the money object: " << endl;
        if(!(cin >> id))
        {   cin.clear();
            throw MyException("Id must be an integer!");
        }
        cout << "Enter the bill type: " << endl;
        if(!(cin >> billType))
        {
            cin.clear();
            throw MyException("Bill type must be a float or int!");
        }
        cout << "Enter the number of bills: " << endl;
        if(!(cin >> numberOfBills))
        {
            cin.clear();
            throw MyException("Number of bills must be an int!");
        }
        Money m(id, billType, numberOfBills);
        serv.addMoneyS(m);
        cout << "Add complete" << endl;

    }
    catch (MyException &e) { cout << e.what() << endl; }
}

void UI::updateMoneyUi() {
    try{
        int idvechi,id,numberOfBills;
        float billType;
        cout<<"Enter the id of the money object you want to update: "<<endl;cin>>idvechi;
        cout << "Enter the id of the money object: " << endl;
        if(!(cin >> id))
        {   cin.clear();
            throw MyException("Id must be an integer!");
        }
        cout << "Enter the bill type: " << endl;
        if(!(cin >> billType))
        {
            cin.clear();
            throw MyException("Bill type must be a float or int!");
        }
        cout << "Enter the number of bills: " << endl;
        if(!(cin >> numberOfBills))
        {
            cin.clear();
            throw MyException("Number of bills must be an int!");
        }
        Money m(id, billType, numberOfBills);
        for(auto &m2:serv.getAllMoneyS())
            if(idvechi==m2.getId())
                serv.updateMoneyS(m,m2);

    }
    catch(MyException &e)
    {
        cout<<e.what()<<endl;
    }
}

void UI::deleteMoneyUi() {
    try {
        cout << "Give the id of the money object you want to delete:" << endl;
        int id;
        if(!(cin >> id))
        {   cin.clear();
            throw MyException("Id must be an integer!");
        }
        serv.deleteMoneyS(id);
    }
    catch (MyException &e) { cout << e.what() << endl; }
}

