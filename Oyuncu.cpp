//
// Created by netadim on 18.12.2021.
//

#include "Oyuncu.h"
using namespace std;

Oyuncu::Oyuncu(string a,string b, int c, int d, int e)
:name(a), position(b)
{
    setPerformanceNumber(c);
    setFormaNumber(d);
    setAge(e);
}
//SET FUNCS
void Oyuncu::setName(string & a) {
    name = a;
}
void Oyuncu::setPosition(string &a) {
    position = a;
}
void Oyuncu::setPerformanceNumber(int &a) {
    if(a<=30){
        performance=30;
    }else if(a>=100){
        performance=100;
    }else{
        performance= a;
    }
}
void Oyuncu::setFormaNumber(int &a) {
    if(a<=1){
        number=1;
    }else if(a>=99){
        number=99;
    }else{
        number= a;
    }
}
void Oyuncu::setAge(int &a) {
    if(a<=18){
        age=18;
    }else if(a>=36){
        age=36;
    }else{
        age= a;
    }
}
//GET FUNCS

string Oyuncu::getName() {
    return name;
}
string Oyuncu::getPosition() {
    if (position=="K")return "Kaleci";
    else if(position=="D")return "Defans";
    else if(position=="O")return "Orta Saha";
    else if(position=="F")return "Forvet";
    else return "Yok !";
}
int Oyuncu::getPerformanceNumber(){
    return performance;
}
int Oyuncu::getFormaNumber(){
    return number;
}
int Oyuncu::getAge(){
    return age;
}