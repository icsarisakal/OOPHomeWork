

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <random>
#include <algorithm>
#include <chrono>
#include <ctime>
#include "Oyuncu.h"
#include "Takim.h"
#include "Mac.h"
 // #include "string"
using namespace std;

string strAd;
string strSoyad;
string strAdSoyad;
string str;
string vektorTakimAdii;
string vectorTeknikDirektorr;

vector<string>vectorAd;
vector<string>vectorSoyad;
vector<string>vectorAdSoyad;
vector<string>v;
vector<string>vectorTakimAdi;
vector<string>vectorTeknikDirektor;
vector<string>vectorTakma;

vector<Oyuncu> allPlayers;
vector<Takim> allTeams;
vector<Mac> allMatches;

vector<vector<Mac>> allWeeks;

void adDosyaOkuma(){
    ifstream adDosya("NewAd.txt");
    while(adDosya){
        getline(adDosya, strAd);
        vectorAd.push_back(strAd);
    }
}
void soyadDosyaOkuma(){
    ifstream soyadDosya("NewSoyad.txt");
    while(soyadDosya){
        getline(soyadDosya,strSoyad);
        vectorSoyad.push_back(strSoyad);
    }
}
void shuffleSoyadDosya(){
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine e(seed);
    shuffle(vectorSoyad.begin(), vectorSoyad.end(), e);
}
void adSoyadBirlestirme(){
    for(int i=0;i<vectorAd.size();i++){
        strAdSoyad=vectorAd[i]+" "+vectorSoyad[i];
        vectorAdSoyad.push_back(strAdSoyad);
    }
}
void superLigOkuma(){
    ifstream file("NewSuperLeague1.txt");
    while(file){
        getline(file, str);      // dosya okuma
        v.push_back(str);
    }
    v.erase(v.end());
}
void takimBilgiAyirma(){
    for(int i=0;i<v.size();i++){
        string s = v[i];
        string delimeter = "-";
        string tokenA = s.substr(0, s.find(delimeter));              // takım adı ve teknık dırector adı ayırma
        string tokenB = s.substr(s.find(delimeter)+1);
        vectorTakimAdi.push_back(tokenA);
        vectorTeknikDirektor.push_back(tokenB);
    }
}
void hataCozumleme(string& a, string& b){                                    // kısaltmaları değiştirme
    char c;
    int r;
    int seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    r = (e() % 26)+65;   // generate a random number
    a += r;            // Convert to a character from a-z

}
void kontrolPaneli(){                                                   // kısaltmaları kontrol etme
//    int i=0;
//    int a=0;
//    for(int c=0;c<vectorTakma.size();c++){
//        do {
//            if (vectorTakma[a].compare(vectorTakma[i + 1]) == 0) {   // hata (eşit)
//                hataCozumleme(vectorTakma[a], vectorTakma[i + 1]);         // hata çözümlemeye gitti
//            } else if (vectorTakma[a].compare(vectorTakma[i + 1]) != 0) {
//                i++;
//                if (i == vectorTakma.size()) {
//                    a++;
//                    i = a + 1;
//                } else if (a == vectorTakma.size()) {
//                    //                cout<<"Kısaltmada sorun yok!\n";
//                }
//
//
//            }
//        } while (!(i != vectorTakma.size() && a != vectorTakma.size()));
//
//    }
}
void takimKisaltmaOlusturma(){
    for(int i=0;i<vectorTakimAdi.size();i++){
        string p = vectorTakimAdi[i];                           // takma ad vectoru oluşturma
        string tokenC = p.substr(0, 2);
        vectorTakma.push_back(tokenC);

    }
    kontrolPaneli();
}

int main() {
    adDosyaOkuma();
    soyadDosyaOkuma();
    shuffleSoyadDosya();
    adSoyadBirlestirme();
    superLigOkuma();
    takimBilgiAyirma();
    takimKisaltmaOlusturma();


    int playerNum = 0;
    string mevkiArr[4] = {"K", "D", "O", "F"};
    string tempName;
    int tempPerf;
    int tempNum;
    int tempAge;

//OYUNCU OLUŞTURUCU
    for (int i = 0; i < vectorAdSoyad.size(); i++) {
        tempName = vectorAdSoyad[i];
        tempPerf = rand() % 101;
        tempNum = rand() % 100;
        tempAge = rand() % 36;
        Oyuncu oyuncu(tempName, mevkiArr[i % 4], tempPerf, tempNum, tempAge);
        allPlayers.push_back(oyuncu);
    }
//OYUNCU OLUŞTURUCU

//TAKIM OLUŞTURUCU
    for (int i = 0; i < vectorTakimAdi.size(); i++) {
        vector<Oyuncu> takimPlayers;
        for (int j = 0; j < 11; j++) {
            switch (i) {
                case 1:
                    allPlayers[playerNum].setPosition(mevkiArr[0]);
                    break;
                case 2:
                case 3:
                case 4:
                case 5:
                    allPlayers[playerNum].setPosition(mevkiArr[1]);
                    break;
                case 6:
                case 7:
                case 8:
                case 9:
                    allPlayers[playerNum].setPosition(mevkiArr[2]);
                    break;
                case 10:
                case 11:
                    allPlayers[playerNum].setPosition(mevkiArr[3]);
                    break;
            }
            takimPlayers.push_back(allPlayers[playerNum]);
            playerNum += 1;
        }
        Takim takim(vectorTakimAdi[i], vectorTakma[i], vectorTeknikDirektor[i]);
        takim.setPlayers(takimPlayers);
        allTeams.push_back(takim);
    }

// fill

    vector<Takim> birinciTakim(allTeams.begin(), allTeams.end() - 1);
    vector<Takim> ikinciTakim(allTeams.begin() + 1, allTeams.end());

    int macID = 1;
//FİKSTÜR OLUŞTURUCU

    for (int i = 0; i < birinciTakim.size(); i++) {
        for (int j = i; j < ikinciTakim.size(); j++) {
            Mac mac(birinciTakim[i], ikinciTakim[j], 0, 0, macID);
            allMatches.push_back(mac);
            macID++;
        }
    }
    int countMatchsperWeek;
    if (allTeams.size() % 2 == 1) {
        countMatchsperWeek = (allTeams.size() - 1) / 2;
    } else {
        countMatchsperWeek = allTeams.size() / 2;
    }

    vector<Mac> &cloneAllMatches = allMatches;
    vector<Mac> tempWeekMatches;
    vector<Takim> cloneAllTeams = allTeams;
    vector<Takim> aciktaKalanTakimlar;

    int countWeeks = allTeams.size() - 1;
    int countMatchonWeek=allTeams.size() / 2;

    if (cloneAllTeams.size()%2==0){
        for (int m = 0; m < countWeeks; m++) {
            for (int i = 0; i < countMatchonWeek; i++) {
                int macIndex=0;
                for (Mac& mac: cloneAllMatches) {
                    if(mac.getEvSahibi().getName()==cloneAllTeams.begin()->getName()){
                        tempWeekMatches.push_back(mac);
                        cloneAllTeams.erase(cloneAllTeams.begin());
                        int rakipIndex=0;
                        for (Takim& rakip:cloneAllTeams) {
                            if(rakip.getName()==mac.getRakip().getName()){
                                cloneAllTeams.erase(cloneAllTeams.begin()+rakipIndex);
                                break;
                            }else{
                                rakipIndex++;
                            }

                        }
                        cloneAllMatches.erase(cloneAllMatches.begin()+macIndex);

                    }
                    macIndex++;
                }
                if (tempWeekMatches.size()%9==0){
                    allWeeks.push_back(tempWeekMatches);
                    tempWeekMatches.clear();
                }
                cloneAllTeams=allTeams;
            }
        }
    }


//    cout<<"aciktaKalanTakimlar[10]"<<endl;

//    if (cloneAllTeams.size() % 2 == 0) {
//        for (int m = 0; m < allTeams.size() - 1; m++) {
//            for (int i = 0; i < allTeams.size() / 2; i++) {   //9 maça tamamlamasını sağlıyor
//                for (int j = 0; j < cloneAllMatches.size(); j++) {
//                    if (cloneAllMatches[j].getEvSahibi().getName() == cloneAllTeams.begin()->getName()) { // takımlardan ilkinin ev sahibi olduğu ilk maçı bulduk
//                        tempWeekMatches.push_back(cloneAllMatches[j]);//tempWeekMatches vectörüne attık
//                        cloneAllTeams.erase(cloneAllTeams.begin());//ev sahibimizi sildik
//                        for (int k = 0; k < cloneAllTeams.size(); k++) {
//                            if (cloneAllMatches[j].getRakip().getName() == cloneAllTeams[k].getName()) {//rakip takımı da sildik ki bir haftada 2 defa maç oynayamasın
//                                cloneAllTeams.erase(cloneAllTeams.begin() + k);//rakibi sildik
//                                break;
//                            }
//                        }
//                    cloneAllMatches.erase(cloneAllMatches.begin() + j);
//                }
//            }
//        }
//        allWeeks.push_back(tempWeekMatches);
//        cloneAllTeams = allTeams;
//        tempWeekMatches.clear();
//
//    }
//}
//    else{
//        for(int x = 0; x < allTeams.size(); x++){
//            for(int z = 0; z < allTeams.size();z++){
//                cloneAllTeams.begin();
//                for (int j = 0; j < cloneAllMatches.size(); j++) {
//                    if (cloneAllMatches[j].getEvSahibi().getName() == cloneAllTeams.begin()->getName()) { // takımlardan ilkinin ev sahibi olduğu ilk maçı bulduk
//                        tempWeekMatches.push_back(cloneAllMatches[j]);//tempWeekMatches vectörüne attık
//                        cloneAllTeams.erase(cloneAllTeams.begin());//ev sahibimizi sildik
//                        for (int k = 0; k < cloneAllTeams.size(); k++) {
//                            if (cloneAllMatches[j].getRakip().getName() == cloneAllTeams[k].getName()) {//rakip takımı da sildik ki bir haftada 2 defa maç oynayamasın
//                                cloneAllTeams.erase(cloneAllTeams.begin() + k);//rakibi sildik
//                                cloneAllMatches.erase(cloneAllMatches.begin() + j);
//                                break;
//                            }
//                        }
//                    }
//
//                }
//            }
//        }
//    }
    int anan =0;
    for (int asd = 0; asd < allWeeks.size(); asd++) {
        cout<<"======================== Week "<<asd+1<<endl;
        for (Mac& mac:allWeeks[asd]) {
            anan++;
            cout<<anan<<". Ev: "<<mac.getEvSahibi().getName()<<" - Rakip: "<<mac.getRakip().getName()<<endl;
        }
    }
//FİKSTÜR OLUŞTURUCU

    return 0;
}

