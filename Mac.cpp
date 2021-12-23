//
// Created by netadim on 23.12.2021.
//

#include "Mac.h"
#include <random>
#include <string>
using namespace std;

Mac::Mac(Takim evSahibiTakim,Takim rakipTakim,
         int evSahibininSkoru,int rakibinSkoru,int macinID)
         : evSahibi(evSahibiTakim), rakip(rakipTakim),macID(macinID)
//evSahibi(evSahibiTakým),rakip(rakipTakým)
{
    setEvSahibiSkor(evSahibininSkoru);
    setRakipSkor(rakibinSkoru);
}
void Mac::setEvSahibi(Takim evSahibi){
    this->evSahibi = evSahibi;
}
void Mac::setRakip(Takim rakip){
    this->rakip = rakip;
}
void Mac::setEvSahibiSkor(int a){
    if(a<0){
        evSahibiSkor=0;
    }else{
        evSahibiSkor= a;
    }
}
void Mac::setRakipSkor(int a){
    if(a<0){
        rakipSkor=0;
    }else{
        rakipSkor= a;
    }
}
void Mac::setMacID(int macID){
    this->macID = macID;
}
Takim Mac::getEvSahibi(){
    return evSahibi;
}
Takim Mac::getRakip(){
    return rakip;
}
int Mac::getEvSahibiSkor(){
    return evSahibiSkor;
}
int Mac::getRakipSkor(){
    return rakipSkor;
}
int Mac::getMacID(){
    return macID;
}