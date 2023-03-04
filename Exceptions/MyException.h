//
// Created by Vlad on 5/14/2022.
//

#ifndef LAB910_MYEXCEPTION_H
#define LAB910_MYEXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class MyException : public std::exception {
private:
    const char  *message;
public:

    MyException(const char *message){this->message=message;}
    const char *what() const noexcept override{ return message; }

};

#endif //LAB910_MYEXCEPTION_H
