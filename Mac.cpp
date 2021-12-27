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
    setskorHesaplama();
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

void Mac::setskorHesaplama() {

    // Defans Average
    if (this->getEvSahibi().getPerformanceAvgD() > this->getRakip().getPerformanceAvgD()) {
        this->setRakipSkor(this->getRakipSkor() - 1);
    } else {
        this->setEvSahibiSkor(this->getEvSahibiSkor() - 1);
    }

    // Orta Saha Average
    if (this->getEvSahibi().getPerformanceAvgO() > this->getRakip().getPerformanceAvgO()) {
        this->setEvSahibiSkor(this->getEvSahibiSkor() + 1);
        this->setRakipSkor(this->getRakipSkor() - 1);
    } else {
        this->setEvSahibiSkor(this->getEvSahibiSkor() - 1);
        this->setRakipSkor(this->getRakipSkor() + 1);
    }

    //Forvet Average
    if (this->getEvSahibi().getPerformanceAvgF() > this->getRakip().getPerformanceAvgF()) {
        this->setEvSahibiSkor(this->getEvSahibiSkor() + 1);
    } else {
        this->setRakipSkor(this->getRakipSkor() + 1);
    }

    // Toplam Average
    if (this->getEvSahibi().getPerformanceAvgTeam() > this->getRakip().getPerformanceAvgTeam()) {
        srand(time(NULL));
        int durum1;
        for (int x = 0; x < 1; x++) {
            durum1 = rand() % 2;
        }


        if (durum1 == 0) {
            this->setEvSahibiSkor(this->getEvSahibiSkor() + 1);
        } else {
            this->setRakipSkor(this->getRakipSkor() - 1);
        }
    } else {
        srand(time(NULL));
        int durum2;
        for (int x = 0; x < 1; x++) {
            durum2 = rand() % 2;
        }


        if (durum2 == 0) {
            this->setRakipSkor(this->getRakipSkor() + 1);
        } else {
            this->setEvSahibiSkor(this->getEvSahibiSkor() - 1);
        }
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