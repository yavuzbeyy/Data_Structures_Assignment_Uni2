/** 
* @file Sirala.cpp 
* @description Dosya islemlerini yapan kaynak dosya
* @course 1. OGRETIM
* @assignment 2. Odev
* @date  19.09.2022
* @author Yavuz Selim Sahin
*/

#include "Sirala.hpp"


void sayilariSirala::readLine() {
    string api,str;
    ifstream file(this->dosya);
    int index = 0;
    while (getline(file, api)) {
        istringstream ss(api);

        while (getline(ss, str, ' ')) {
            this->lines[index]->enqueue(stoi(str));

        }
        index = index + 1;
    }
    file.close();
}

int sayilariSirala::satirSayisi() {
    int counter = 0;
    ifstream file(this->dosya);
    string unused;
    while (std::getline(file, unused))
        ++counter;

    file.close();
    return counter;
}


Kuyruk** sayilariSirala::sortFile() {
    readLine();
    int count = satirSayisi();
    for (int index = 0; index < count; index++) {
        Radix sort(lines[index]);
        Kuyruk *tmp = lines[index];
        lines[index] = sort.Sort();
        delete tmp;

    }
    return lines;
}


sayilariSirala::sayilariSirala(std::string dosya) {
    
	
	this->dosya = dosya;

    int numlines = satirSayisi();
    this->lines = new Kuyruk*[numlines];
    for (int i = 0; i < numlines; i++) {
        this->lines[i] = new Kuyruk();
    }
}

sayilariSirala::~sayilariSirala(){
	if(lines!=0){
		int count =satirSayisi();
		for (int i = 0; i < count; i++){
			if(lines[i]!=0) delete lines[i];
		}
		delete[] lines;
	}
	
}
