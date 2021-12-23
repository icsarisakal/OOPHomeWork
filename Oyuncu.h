//
// Created by netadim on 18.12.2021.
//

#ifndef UNTITLED5_OYUNCU_H
#define UNTITLED5_OYUNCU_H
#include "string"
using namespace std;

class Oyuncu {
public:
    Oyuncu(string ,string ,int ,int ,int);

//    SET FUNCS
    void setName(string&);
    void setPosition(string&);
    void setPerformanceNumber(int&);
    void setFormaNumber(int&);
    void setAge(int&);

//    GET FUNCS
    string getName();
    string getPosition();
    int getPerformanceNumber();
    int getFormaNumber();
    int getAge();

private:
    string name;
    string position;
    string team;
    int age;
    int performance;
    int number;
};


#endif //UNTITLED5_OYUNCU_H
