//
// Created by netadim on 18.12.2021.
//

#ifndef UNTITLED5_TAKIM_H
#define UNTITLED5_TAKIM_H
#include "string"
#include "vector"
#include "Oyuncu.h"
using namespace std;

class Takim {
public:
    Takim(string , string , string );

//    SET FUNCS
    void setName(string&);
    void setAbbr(string&);
    void setCoach(string&);
    void setPlayers(vector<Oyuncu>&);

//    GET FUNCS
    string getName();
    string getAbbr();
    string getCoach();

    int getPerformanceAvgTeam() const;
    int getPerformanceAvgK() const;
    int getPerformanceAvgD() const;
    int getPerformanceAvgO() const;
    int getPerformanceAvgF() const;
    vector<Oyuncu> getPlayers();

private:
//    FUNCS
    void calcAvgK();
    void calcAvgD();
    void calcAvgO();
    void calcAvgF();
//    PROPS
    string name;
    string abbr;
    string coach;
    int avgPerformanceK=0;
    int avgPerformanceD=0;
    int avgPerformanceO=0;
    int avgPerformanceF=0;
    vector<Oyuncu> players;
};


#endif //UNTITLED5_TAKIM_H
