/** 
* @file Dugum.cpp
* @description Dugum header dosyasina gelen veri atamalarini yapar.
* @course 1. OGRETIM
* @assignment 2. Odev
* @date  17.09.2022
* @author Yavuz Selim Sahin
*/#include "Dugum.hpp"

Dugum::Dugum(int item, Dugum *next) {
    this->item = item;
    this->next = next;
}
Dugum::Dugum(int item) {
    this->item = item;
    this->next = 0;
}

/*			Dugum* sagCocuk = donenDugum->sag;
			if(sagCocuk->yukariCiktiMi) {
				cout<<"yukari cikti mi ifin içinde "<<endl;
				int *silenecekArr = new int[100];
				silenecekArr= sortedListesi[sagCocuk->index];
				//sýralý dizide en küçük sayý en baþtadýr.
				for(int j = 0; j<100 ; j++) {
					if(silenecekArr[j]> 0) {
						cout <<"Yukari cikan dizide silinen deger: "<<	silenecekArr[j]<<endl;
						silenecekArr[j] = 0;

						break;
					}
				}

			} else if(sagCocuk->asagiIndiMi) {
				cout<<"sag cocuk asagi indi mi ifin içinde "<<endl;
				int *silenecekArr = new int[100];
				silenecekArr= sortedListesi[sagCocuk->index];
				for(int j = 99; j>=0 ; j--) {
					if(silenecekArr[j]> 0) {
						cout <<"Asagi inen dizide silinen deger: "<< silenecekArr[j]<<endl;
						silenecekArr[j] = 0;
						break;
					}
				}

			}
		} */
