/** 
* @file Kuyruk.cpp kaynak dosyasi
* @description Kuyruk.hpp dosyasinin kaynak dosyasidir , metodlarini barindirir.
* @course 1. OGRETIM
* @assignment 2. Odev
* @date  20.09.2022
* @author Yavuz Selim Sahin
*/

#include "Kuyruk.hpp"

Dugum* Kuyruk::previousMaxNode() {
    Dugum *prev = 0;
    Dugum *tmp = front;
    int max = front->item;
    while (tmp->next != 0) {
        if (tmp->next->item > max) {
            max = tmp->next->item;
            prev = tmp;
        }
        tmp = tmp->next;
    }
    return prev;
}

Kuyruk::Kuyruk() {
    front = back = 0;
    length = 0;
}

int Kuyruk::count()const {
    return length;
}

bool Kuyruk::isEmpty()const {
    return length == 0;
}

void Kuyruk::enqueue(const int& item) {
    Dugum *last = new Dugum(item);
    if (isEmpty()) front = back = last;
    else {
        back->next = last;
        back = back->next;
    }
    length++;
}

void Kuyruk::dequeue() {
    if (isEmpty()) throw "Kuyruk Bos";
    Dugum *tmp = front;
    front = front->next;
    delete tmp;
    length--;
}

void Kuyruk::dequeueMax() {
    if (isEmpty()) throw "Kuyruk Bos";
    Dugum *prev = previousMaxNode();
    Dugum *tmp;
    if (prev == 0) dequeue();
    else {
        if (prev->next == back) back = prev;
        tmp = prev->next;
        prev->next = prev->next->next;
        delete tmp;
        length--;
    }
}

void Kuyruk::clear() {
    while (!isEmpty())dequeue();
}

int& Kuyruk::peek()const {
    if (isEmpty()) throw "Kuyruk Bos";
    return front->item;
}

int& Kuyruk::peekMax() {
    if (isEmpty()) throw "Kuyruk Bos";
    Dugum *prev = previousMaxNode();
    if (prev == 0) return peek();
    return prev->next->item;
}

int Kuyruk::sumQueue() {
    if (front == 0) throw "Kuyruk Bos";
    if (front->next == 0) return front->item;
    Dugum * tmp = front;
    int total = 0;
    while (tmp != 0) {
        total += tmp->item;
        tmp = tmp->next;
    }
    return total;
}

Kuyruk::~Kuyruk() {
    clear();
}
