/** 
* @file AgacDugumu.hpp 
* @description AgacDugumu header dosyasi. Class olusturma ve agacta olusturulacak dugumleri tanimlama 
* @course 1. OGRETIM
* @assignment 2. Odev
* @date  18.09.2022
* @author Yavuz Selim Sahin
*/

#ifndef AGACDUGUMU
#define AGACDUGUMU
#include "Kuyruk.hpp"

class AgacDugumu {
public:
    int data;
    Kuyruk* line;
    AgacDugumu *left;
    AgacDugumu *right;
    int height;

    AgacDugumu(Kuyruk* veri, AgacDugumu *sol, AgacDugumu *sag);
    AgacDugumu(Kuyruk* veri, AgacDugumu *sol);
    AgacDugumu(Kuyruk* veri);
};


#endif 

