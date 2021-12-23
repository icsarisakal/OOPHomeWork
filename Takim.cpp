//
// Created by netadim on 18.12.2021.
//

#include "Takim.h"
using namespace std;
Takim::Takim(string a, string b, string c)
        :name(a),abbr(b),coach(c)
{
}

//SET FUNCS
void Takim::setName(string & a) {
    name = a;
}

void Takim::setAbbr(string &a) {
    abbr = a;
}

void Takim::setCoach(string &a) {
    coach = a;
}
void Takim::setPlayers(vector<Oyuncu>& a){
    players= a;
}

//GET FUNCS
string Takim::getName() {
    return name;
}
string Takim::getAbbr() {
    return abbr;
}
string Takim::getCoach() {
    return coach;
}
int Takim::getPerformanceAvgTeam() const {
    return avgPerformanceK+avgPerformanceD+avgPerformanceO+avgPerformanceF;
}
int Takim::getPerformanceAvgK() const {
    return avgPerformanceK;
}
int Takim::getPerformanceAvgD() const {
    return avgPerformanceD;
}
int Takim::getPerformanceAvgO() const {
    return avgPerformanceO;
}
int Takim::getPerformanceAvgF() const {
    return avgPerformanceF;
}
int Takim::calcAvgK() {
    return avgPerformanceF;
}
int Takim::calcAvgD() {
    return avgPerformanceF;
}
int Takim::calcAvgO() {
    return avgPerformanceF;
}
int Takim::calcAvgF() {
    return avgPerformanceF;
}

vector<Oyuncu> Takim::getPlayers(){
    return players;
}