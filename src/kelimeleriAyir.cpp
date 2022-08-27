/** 
* @file kelimeleriAyir.cpp 
* @description Sayilari elde etmek icin onceki yazilan kod
* @course 1. OGRETIM
* @assignment 2. Odev
* @date  17.09.2022
* @author Yavuz Selim Sahin
*/

#include<iostream>
#include<fstream>

using namespace std;
 
 int* kelimeAyir(string str) { // sayilarin arasinda bosluk varsa duzeltmek icin bu metod yazilmistir.
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
}
