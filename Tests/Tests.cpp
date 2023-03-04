//
// Created by 40742 on 20.04.2022.
//
#include "../Bilet/Bilet.h"
#include "../Repo/RepoInMemory.h"
#include <cassert>
#include <iostream>
#include "../Service/Service.h"
#include <fstream>
#include "../Repo/RepoMoney.h"
using namespace std;
void test_constructor(){
    Bilet p;
    assert(p.getId()==0);
    assert(p.getPret()==0);
    assert(p.getCod().empty());
    assert(p.getZi().empty());

}
void test_setters_getter()
{
    Bilet p;
    p.setId(1);
    p.setCod("SB-CJ");
    p.setZi("Marti");
    p.setPret(12);
    assert(p.getCod() == "SB-CJ");
    assert(p.getId()==1);
    assert(p.getPret()==12);
    assert(p.getZi()=="Marti");
}
void test_repo_add(){
    RepoInMemory repo;
    Bilet p1,p2,p3;
    p1.setId(1);
    p2.setId(2);
    p3.setId(3);
    p1.setCod("SB-CJ");
    p2.setCod("AB-CJ");
    p3.setCod("TM-CJ");
    p1.setPret(4);
    p2.setPret(6);
    p3.setPret(7);
    p1.setZi("Marti");
    p2.setZi("Marti");
    p3.setZi("Marti");
    repo.addBilet(p1);
    repo.addBilet(p2);
    repo.addBilet(p3);
    assert(repo.getAll().size()==3);

}
void test_repo_delete(){
    RepoInMemory repo;
    Bilet p1,p2,p3;
    p1.setId(1);
    p2.setId(2);
    p3.setId(3);
    p1.setCod("SB-CJ");
    p2.setCod("AB-CJ");
    p3.setCod("TM-CJ");
    p1.setPret(4);
    p2.setPret(6);
    p3.setPret(7);
    p1.setZi("Marti");
    p2.setZi("Marti");
    p3.setZi("Marti");
    repo.addBilet(p1);
    repo.addBilet(p2);
    repo.addBilet(p3);
    assert(repo.getAll().size()==3);
    repo.deleteBilet(1);
    assert(repo.getAll().size()==2);
}
void test_repo_update(){
    RepoInMemory repo;
    Bilet p1(1,"SB-CJ","Luni",12,2);
    Bilet p2(2,"AB-CJ","Vineri",10,4);
    Bilet p3(3,"ZL-TM","Marti",25,5);
    repo.addBilet(p1);
    repo.addBilet(p2);
    repo.updateBilet(p3,p1);
    assert(repo.getById(3)==p3);
}
void test_add_ser(){
    Bilet p1(1,"CJ-TM","Marti",23,3);
    Bilet p2(2,"CJ-TM","Marti",23,5);
    Service ser;
    ser.addBiletS(p1);
    ser.addBiletS(p2);
    assert(ser.getAllS().size()==2);

}

void test_delete_ser(){
    Bilet p1(1,"CJ-TM","Marti",23,5);
    Bilet p2(2,"CJ-TM","Marti",23,6);
    Service ser;
    ser.addBiletS(p1);
    ser.addBiletS(p2);
    assert(ser.getAllS().size()==2);
    ser.deleteBiletS(1);
    assert(ser.getAllS().size()==1);
}
void test_update_ser(){
    Bilet p1(1,"CJ-TM","Marti",23,6);
    Bilet p2(2,"ZL-BT","Joi",95,8);
    Bilet p3(3,"AB-VL","Luni",117,6);
    Service ser;
    ser.addBiletS(p1);
    ser.addBiletS(p2);
    ser.updateBiletS(p3,p1);
    assert(ser.getByIdS(3)==p3);
}


void test_list_tickets_by_a_given_code(){
    Bilet p1(1,"CJ-TM","Marti",23,4);
    Bilet p2(2,"ZL-BT","Joi",95,1);
    Bilet p3(3,"ZL-BT","Luni",120,3);
    Service ser;
    ser.addBiletS(p1);
    ser.addBiletS(p2);
    ser.addBiletS(p3);
    assert(ser.getAllS().size()==3);
    vector <Bilet> v;
    v=ser.listProductByaGivenCode("ZL-BT");
    assert(v[0].getId()==p2.getId());
    assert(v[1].getId()==p3.getId());


}

void test_repo_file(){
    remove("bileteee.txt");
    fstream f;
    f.open("bileteee.txt",ios::in);
    f.open("bileteee.txt",ios::out);
    RepoInFile repo("bileteee.txt");
    Bilet b1(1,"CJ-SJ","Luni",12,1);
    Bilet b2(2,"CJ-SB","Marti",43,5);
    Bilet b3(3,"BT-SJ","Joi",34,4);
    Bilet b4(4,"CJ-VL","Luni",27,3);
    repo.addBilet(b1);
    repo.addBilet(b2);
    repo.addBilet(b3);
    //cout<<repo.size_file()<<endl;
    assert(repo.size_file()==3);

}
void test_get_by_id(){
    Bilet b1(1,"CJ-SJ","Luni",12,1);
    Bilet b2(2,"CJ-SB","Marti",43,3);
    RepoInFile repo;
    repo.addBilet(b1);
    assert(repo.getById(1)==b1);

}

void test_money_repo(){
    RepoMoney repomoney("C:/Users/Vlad/CLionProjects/lab910/MoneyTest.txt");
    assert(repomoney.getAllMoney().size()==3);
}

void test_all(){
    test_constructor();
    test_setters_getter();
    test_repo_add();
    test_repo_delete();
    test_repo_update();
    test_get_by_id();
    test_add_ser();
    test_delete_ser();
    test_update_ser();
    test_list_tickets_by_a_given_code();
    test_repo_file();
    ///teste repo money
    test_money_repo();

}
