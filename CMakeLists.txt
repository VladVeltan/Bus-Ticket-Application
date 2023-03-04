cmake_minimum_required(VERSION 3.21)
project(lab910)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab910 main.cpp Bilet/Bilet.cpp Bilet/Bilet.h Tests/Tests.cpp Tests/Tests.h Repo/RepoInMemory.cpp Repo/RepoInMemory.h Service/Service.cpp Service/Service.h UI/UI.cpp UI/UI.h Repo/IRepo.cpp Repo/IRepo.h Repo/RepoInFile.cpp Repo/RepoInFile.h Money/Money.cpp Money/Money.h Repo/RepoMoney.cpp Repo/RepoMoney.h Exceptions/MyException.h ValidatorBilete/ValidatorBilete.h ValidatorBilete/ValidatorBilete.cpp ValidatorMoney/ValidatorMoney.cpp ValidatorMoney/ValidatorMoney.h)
