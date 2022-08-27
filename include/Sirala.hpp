
/** 
* @file Sirala.hpp  dosyasi
* @description Dosya islemlerini yapayan class ve metodlari
* @course 1. OGRETIM B GRUBU
* @assignment 2. Odev
* @date  20.09.2022
* @author Yavuz Selim Sahin
*/

using namespace std;

#ifndef SIRALA_HPP
#define SIRALA_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "Kuyruk.hpp"
#include "Radix.hpp"


class sayilariSirala {
private:

    string dosya;

public:

    sayilariSirala(string);
    ~sayilariSirala();
    Kuyruk** sortFile();
    int satirSayisi();

private:
    Kuyruk **lines;
    void readLine();


};



#endif

