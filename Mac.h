//
// Created by netadim on 23.12.2021.
//

#ifndef UNTITLED5_MAC_H
#define UNTITLED5_MAC_H

#include <string>
#include <iostream>
#include "Oyuncu.h"
#include "Takim.h"
#include "time.h"


using namespace std;

class Mac
{
public:
    Mac(Takim,Takim,int,int,int);
    Takim getEvSahibi();
    Takim getRakip();
    int getEvSahibiSkor();
    int getRakipSkor();
    int getMacID();
    void setEvSahibi(Takim);
    void setRakip(Takim);
    void setEvSahibiSkor(int);
    void setRakipSkor(int);
    void setskorHesaplama();
    void setMacID(int);

    int getMacId() const;

    void setMacId(int macId);


private:
    Takim evSahibi;
    Takim rakip;
    int evSahibiSkor;
    int rakipSkor;
    int macID;

    // validation daha yap�lmad� bak�lacak.
};



#endif //UNTITLED5_MAC_H
