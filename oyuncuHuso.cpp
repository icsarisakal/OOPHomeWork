#include <iostream>
#include <fstream>
#include <locale.h>
#include <vector>
#include <string>
#include <iterator>
#include "time.h"
#include <random>
#include <stdlib.h>
#include <algorithm>
#include <chrono>
#include <ctime>

using namespace std;
string strAd;
string strSoyad;
vector<string>vectorAd;
vector<string>vectorSoyad;
vector<int>vectorRandomSayi;
vector<string>vectorAdSoyad;
string strAdSoyad;
int randomSayi;

    void adDosyaOkuma(){ifstream adDosya("C:\\Users\\btdha\\Desktop\\2.yýl\\oop\\proje\\Ad.txt");
    while(adDosya){
        getline(adDosya, strAd);
        vectorAd.push_back(strAd);
    }
    }

    void adDosyaPrint(){
        for(int i=0;i<vectorAd.size();i++){
            cout<<vectorAd[i];
            cout<<"\n";
        }
    }

    void soyadDosyaOkuma(){
        ifstream soyadDosya("C:\\Users\\btdha\\Desktop\\2.yýl\\oop\\proje\\Soyad.txt");
        while(soyadDosya){
            getline(soyadDosya,strSoyad);
            vectorSoyad.push_back(strSoyad);
        }
    }

    void soyadDosyaPrint(){
        for(int i=0;i<vectorSoyad.size();i++){
            cout<<vectorSoyad[i];
            cout<<"\n";
        }
    }

    void shuffleSoyadDosya(){

        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine e(seed);
    shuffle(vectorSoyad.begin(), vectorSoyad.end(), e);
}

    void adSoyadBirlestirme(){
        //vectorAd;
        //vectorSoyad;
        for(int i=0;i<vectorAd.size();i++){

            strAdSoyad=vectorAd[i]+vectorSoyad[i];
            vectorAdSoyad.push_back(strAdSoyad);
    }
    }
    void adSoyadPrint(){
        for(int i=0;i<vectorAdSoyad.size();i++){
            cout<<vectorAdSoyad[i];
            cout<<"\n";
        }
    }
    void deneme(){
        cout<<vectorAd.at(0);
        //cout<<"vectorAd[0]: "<<vectorAd[0]<<"  vectorSoyad[0]: "<<vectorSoyad[0]<<endl;
    }

int main()
{
    adDosyaOkuma();
    //adDosyaPrint();
    soyadDosyaOkuma();
    shuffleSoyadDosya();
    adSoyadBirlestirme();
    adSoyadPrint();
    //cout << vectorAdSoyad.size();
    deneme();
    //soyadDosyaPrint();




    return 0;
}
