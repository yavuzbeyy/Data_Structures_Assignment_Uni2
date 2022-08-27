/** 
* @file Dugum.Hpp header dosyasi
* @description Dugum classini barindirir.
* @course 1. OGRETIM B GRUBU
* @assignment 2. Odev
* @date  18.09.2022
* @author Yavuz Selim Sahin
*/


#ifndef DUGUM_HPP
#define DUGUM_HPP


class Dugum {
public:
    int item;
    Dugum *next;
    Dugum(int item);
    Dugum(int, Dugum*);
};


#endif 

