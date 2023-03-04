#include <iostream>
#include "Tests/Tests.h"
#include "UI/UI.h"
#include "Repo/RepoInFile.h"
#include "Repo/RepoInMemory.h"
#include "Repo/IRepo.h"
#include "Service/Service.h"
#include "Money/Money.h"
#include <fstream>
#include "Repo/RepoMoney.h"
using namespace std;
int main() {
    test_all();
    RepoInFile repo(R"(C:\Users\Vlad\CLionProjects\lab910\bilete1.txt)");
    RepoMoney repoMoney(R"(C:/Users/Vlad/CLionProjects/lab910/Money.txt)");
    ValidatorBilete validatorBilete;
    ValidatorMoney validatorMoney;
    //cout<<repoMoney.getAllMoney().size();
    Service service(repo,repoMoney,validatorBilete,validatorMoney);
    UI ui(service);
    ui.runMenu();




}