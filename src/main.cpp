/** 
* @file main dosyasi
* @description Programin baslatildigi yerdir. Dosya islemleri ve agac - kuyruk olusturma islemleri yapar
* @course 1. OGRETIM
* @assignment 2. Odev
* @date  16.09.2022
* @author Yavuz Selim Sahin
*/

#include<iostream>
#include "Radix.hpp"
#include "Sirala.hpp"
#include<fstream>
#include "Avl.hpp"
#include "kelimeleriAyir.cpp"

using namespace std;

 
/* int* kelimeAyir(string str) { // sayilarin arasinda bosluk varsa duzeltmek icin bu metod yazilmistir.
	string word = "";
	int count = 0;

	int *result = new int[100];

	for (auto x : str) {

		//boþluksa ya da satir sonuysa
		if (x == ' ' || x=='\n' ) {

			if (word != "" || word != " " ) {

				int sayi=stoi(word);
				result[count] =sayi;
				count++;
				word = "";

			}

		} else {
			word = word + x;
		}


	}
	if (word != "" || word != " " ) {

		int sayi=stoi(word);
		result[count] =sayi;
		count++;
		word = "";

	}
	//cout << word << endl;

	return result;
}*/



int main() {
	
	int satirSayac = 0;
	string satirlar;
	ifstream txtOkuma ;
	
	txtOkuma.open("Sayilar.txt",ios::in);

	while(getline(txtOkuma,satirlar)) { // sayilarin satir satir alinmasi

		satirSayac += 1; // bos olan satirlarla beraber satir sayisini verir.
	}
	txtOkuma.close();

	txtOkuma.open("Sayilar.txt",ios::in);

	cout <<	"Okunan metindeki Satir Sayisi : " << satirSayac<<endl;

    sayilariSirala *okunanSayilar = new sayilariSirala("Sayilar.txt");
    
	Kuyruk** kuyruklar = okunanSayilar->sortFile(); // Verilerin sort edilmesi
    
	AVL *Agac = new AVL(); // agacin olusturulmasi
    
	for (int index = 0; index < okunanSayilar->satirSayisi(); index++) {

     Agac ->Add(kuyruklar[index]);

    }
    
      /*  Dugum* donenDugum;
    
	for(int i = 0; i<satirSayac ; i++) {
         
		cout<<satirinToplamListesi[i]<<endl;

	   donenDugum = AVL.ekle(satirinToplamListesi[i], i);  //Sayilarin Toplamlarinin agaca eklenme islemi	
	    
	   if(AVL.kok->veri == satirinToplamListesi[0]){
	    	donenDugum = AVL.kok;
		}
		else if (AVL.kok->veri == satirinToplamListesi[1]){
			donenDugum = AVL.kok->sag;
		}
		else if (AVL.kok->veri == satirinToplamListesi[2]){
		donenDugum = AVL.kok->sag;
		} */
    
    txtOkuma.close();
    
	cout << "******Preorder Yazim********" << endl;
  
    Agac -> preorder();	

    return 0;
}

