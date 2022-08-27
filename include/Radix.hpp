/** 
* @file Radix.Hpp header dosyasi
* @description Radix islemlerini yapan classin dosyasidir..
* @course 1. OGRETIM B GRUBU
* @assignment 2. Odev
* @date  18.09.2022
* @author Yavuz Selim Sahin
*/


#ifndef RADIX_HPP
#define RADIX_HPP

#include "Kuyruk.hpp"
#include <math.h>

class Radix {
private:
    int* numbers;
    int length,maxStep;
    int MaxStepNumber();
    int StepCount(int);
    Kuyruk **queues;
public:
    Radix(Kuyruk*);
    Kuyruk* Sort();
    ~Radix();
};


#endif 

