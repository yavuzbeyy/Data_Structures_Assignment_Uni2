/** 
* @file AgacDugumu kaynak dosyasi
* @description AgacDugumu kaynak dosyalarinin metodlarini barindirir.
* @course 1. OGRETIM
* @assignment 2. Odev
* @date  17.09.2022
* @author Yavuz Selim Sahin
*/


#include "AgacDugumu.hpp"
#include <cmath>

AgacDugumu::AgacDugumu(Kuyruk* veri, AgacDugumu *sol, AgacDugumu *sag) {
    data = veri->sumQueue();
    line = veri;
    left = sol;
    right = sag;
    height = 0;
}

AgacDugumu::AgacDugumu(Kuyruk* veri, AgacDugumu *sol) {
    data = veri->sumQueue();
    line = veri;
    left = sol;
    right = 0;
    height = 0;
}

AgacDugumu::AgacDugumu(Kuyruk* veri) {
    data = veri->sumQueue();
    line = veri;
    left = 0;
    right = 0;
    height = 0;
}
