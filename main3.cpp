#include <iostream>
#include <fstream>
#include <locale.h>
#include <vector>
#include <string>
#include <iterator>
#include "time.h"
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
using namespace std;
ifstream file("C:\\Users\\btdha\\Desktop\\2.y�l\\oop\\proje\\NewSuperLig1.txt");
   vector<string>v;
   vector<string>vectorTakimAdi;
   vector<string>vectorTeknikDirektor;
   vector<string>vectorTakma;
   string str;
   string vektorTakimAdii;
   string vectorTeknikDirektorr;


   void hataCozumleme(string& a, string& b){                                    // k�saltmalar� de�i�tirme
    char c;
    int r;
    int seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    r = (e() % 26)+65;   // generate a random number
    a += r;            // Convert to a character from a-z
    void kontrolPaneli();

   }




void kontrolPaneli(){                                                   // k�saltmalar� kontrol etme
       int i=0;
       int a=0;
    for(int c=0;c<vectorTakma.size();c++){
        tekrar:
        if(vectorTakma[a].compare(vectorTakma[i+1]) == 0){   // hata (e�it)
            cout<<"Hata!!\a\n"<<"vector  "<<a<<"    ile     "<<i+1<< "   ayni !!"<< endl;
            hataCozumleme(vectorTakma[a],vectorTakma[i+1]);         // hata ��z�mlemeye gitti
        }

        else if(vectorTakma[a].compare(vectorTakma[i+1]) != 0){
            i++;
            if(i == vectorTakma.size()){
                a++;
                i=a+1;
            }
                else if(a == vectorTakma.size()){
                    cout<<"K�saltmada sorun yok!\n";
                }

            else if(i != vectorTakma.size() && a != vectorTakma.size()){
                goto tekrar;
            }


        }

}
    }



int main()
{


   while(file){
        getline(file, str);      // dosya okuma
    v.push_back(str);
   }

   v.pop_back();
   //copy(v.begin(),v.end(),ostream_iterator<string>(cout,"\n"));    // ��kt� ekran�

    /* for(int i=0;i<v.size();i++){
        cout<<v[i];
    } */

   for(int i=0;i<v.size();i++){
    string s = v[i];
    string delimeter = "-";
    string tokenA = s.substr(0, s.find(delimeter));              // tak�m ad� ve tekn�k d�rector ad� ay�rma
    string tokenB = s.substr(s.find(delimeter)+1);
    vectorTakimAdi.push_back(tokenA);
    vectorTeknikDirektor.push_back(tokenB);
   }

    for(int i=0;i<vectorTakimAdi.size();i++){
        string p = vectorTakimAdi[i];                           // takma ad vectoru olu�turma
        string tokenC = p.substr(0, 2);
        vectorTakma.push_back(tokenC);

    }

kontrolPaneli();


    for(int i=0;i<vectorTakma.size();i++){
        cout<<vectorTakma[i];                                        // k�saltmalar� bast�rma
        cout<<"\n";
    }

      // copy(v.begin(),v.end(),ostream_iterator<string>(cout,"\n"));
     //copy(v.begin(),v.end(),back_inserter(vector3));
}
