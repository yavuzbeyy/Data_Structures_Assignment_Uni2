/** 
* @file Avl.hpp 
* @description Agacin classini ve metodlarini barindiran header dosyasi
* @course 1. OGRETIM
* @assignment 2. Odev
* @date  19.09.2022
* @author Yavuz Selim Sahin
*/

#include <cstdlib>
#ifndef AVL_HPP
#define AVL_HPP
#include <iostream>
#include "AgacDugumu.hpp"
#include "Kuyruk.hpp"

using namespace std;

class AVL {
	
public:
	

    AVL();
    ~AVL();	
    
    bool isEmpty()const;
    
    void Add(Kuyruk* item);
    void preorder();
    void Clear();
    
    int Height();
	
private:
	
    AgacDugumu *kok;
    AgacDugumu* SearchAndAdd(AgacDugumu *subNode, int item, Kuyruk *items);
    AgacDugumu* SwapWithLeftChild(AgacDugumu *subNode);
    AgacDugumu* SwapWithRightChild(AgacDugumu *subNode);
    
    bool DeleteNode(AgacDugumu *&subNode);
    
    void postorderMaxDel(AgacDugumu *subNode);
    void postorderDel(AgacDugumu *subNode);
    void preorder(AgacDugumu *subNode);
    
    int Height(AgacDugumu *subNode);


};


#endif 

