#include <iomanip>
#include<iostream>
#include<queue>
#include<fstream>

class AVLAgaci {


	public:

		AVLAgaci();

		~AVLAgaci();
		bool varmi(int veri);
		Dugum* ekle(int veri , int index);
		void sil(int veri);
		friend ostream& operator<<(ostream& os,AVLAgaci& kuyruk);
		int yukseklik();

		Dugum* kok;

		int yukseklik(Dugum* aktifDugum);

		void preOrder();
		void postOrder();
		void inOrder();
		void boslukBirak(int adet);
	private:
		int dengesizlikYonu(Dugum* aktif);
		Dugum* solaDondur(Dugum* dugum);
		Dugum* sagaDondur(Dugum* dugum);
		int minDeger(Dugum* aktif);
		void levelOrder();
		void preOrder(Dugum* aktif);
		void postOrder(Dugum* index);
		void inOrder(Dugum* index);

		Dugum* ekle(int veri, int index, Dugum* aktifDugum);
		bool varmi(int aranan,Dugum* aktif);
		Dugum* sil(int veri,Dugum* aktif);
		int maxDeger(Dugum* aktif);

};
