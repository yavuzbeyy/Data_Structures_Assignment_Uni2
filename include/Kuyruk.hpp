/** 
* @file Kuyruk.Hpp header dosyasi
* @description Kuyruk islemlerini yapan classin dosyasidir..
* @course 1. OGRETIM B GRUBU
* @assignment 2. Odev
* @date  17.09.2022
* @author Yavuz Selim Sahin
*/

#ifndef KUYRUK_HPP
#define KUYRUK_HPP
#include "Dugum.hpp"

class Kuyruk {
private:
    Dugum *front;
    Dugum *back;
    int length;

    Dugum* previousMaxNode();
public:
    Kuyruk();
    
    int count()const;
    bool isEmpty()const;
    
    void enqueue(const int& item);
    void dequeue();
    void dequeueMax();
    void clear();
    
    int& peek()const;
    int& peekMax();
    int sumQueue();
    
    ~Kuyruk();
};


#endif 

