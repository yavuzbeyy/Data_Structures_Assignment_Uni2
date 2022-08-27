/** 
* @file AVLc.cpp 
* @description AVL agaci islemlerini barindirir swap-ekle-delete vb.
* @course 1. OGRETIM
* @assignment 2. Odev
* @date  17.09.2022
* @author Yavuz Selim Sahin
*/

#include "Avl.hpp"

AgacDugumu* AVL::SearchAndAdd(AgacDugumu *subNode, int item, Kuyruk *items) {

    if (subNode == NULL) subNode = new AgacDugumu(items);
    else if (item < subNode->data) {
        subNode->left = SearchAndAdd(subNode->left, item, items);

        if (Height(subNode->left) == Height(subNode->right) + 2) {
            if (item < subNode->left->data)

                subNode = SwapWithLeftChild(subNode);
            else {

                subNode->left = SwapWithRightChild(subNode->left);
                subNode = SwapWithLeftChild(subNode);
            }
        }
    } else if (item > subNode->data) {
        subNode->right = SearchAndAdd(subNode->right, item, items);

        if (Height(subNode->right) == Height(subNode->left) + 2) {
            if (item > subNode->right->data)

                subNode = SwapWithRightChild(subNode);
            else {

                subNode->right = SwapWithLeftChild(subNode->right);
                subNode = SwapWithRightChild(subNode);
            }
        }
    } else;

    subNode->height = Height(subNode);
    return subNode;
}

AgacDugumu* AVL::SwapWithLeftChild(AgacDugumu *subNode) {


    AgacDugumu *tmp = subNode->left;
    subNode->left = tmp->right;
    tmp->right = subNode;

    subNode->height = Height(subNode);
    tmp->height = 1 + max(Height(tmp->left), subNode->height);

    if (!subNode->line->isEmpty()) {
        subNode->line->dequeueMax();
    }
    postorderMaxDel(subNode->right);
    if (!tmp->line->isEmpty()) {
        tmp->line->dequeue();
    }
    postorderDel(tmp->left);
    return tmp;
}

AgacDugumu* AVL::SwapWithRightChild(AgacDugumu *subNode) {

    AgacDugumu *tmp = subNode->right;
    subNode->right = tmp->left;
    tmp->left = subNode;

    subNode->height = Height(subNode);
    tmp->height = 1 + max(Height(tmp->right), subNode->height);
    if (!subNode->line->isEmpty()) {
        subNode->line->dequeueMax();
    }
    postorderMaxDel(subNode->left);
    if (!tmp->line->isEmpty()) {
        tmp->line->dequeue();
    }
    postorderDel(tmp->right);
    return tmp;
}

bool AVL::DeleteNode(AgacDugumu *&subNode) {
    AgacDugumu *delNode = subNode;

    if (subNode->right == NULL) subNode = subNode->left;
    else if (subNode->left == NULL) subNode = subNode->right;
    else {
        delNode = subNode->left;
        AgacDugumu *parentNode = subNode;
        while (delNode->right != NULL) {
            parentNode = delNode;
            delNode = delNode->right;
        }
        subNode->data = delNode->data;
        if (parentNode == subNode) subNode->left = delNode->left;
        else parentNode->right = delNode->left;
    }
    delete delNode;
    return true;
}

void AVL::postorderMaxDel(AgacDugumu *subNode) {

    if (subNode != NULL) {

        postorderMaxDel(subNode->left);
        postorderMaxDel(subNode->right);
        if (!subNode->line->isEmpty()) {
            subNode->line->dequeueMax();
        }

    }
}

void AVL::postorderDel(AgacDugumu *subNode) {
    if (subNode != NULL) {

        postorderDel(subNode->left);
        postorderDel(subNode->right);
        if (!subNode->line->isEmpty()) {
            subNode->line->dequeue();
        }
    }
}

void AVL::preorder(AgacDugumu *subNode) {
    if (subNode != NULL) {
        cout << subNode->data << ": ";
        while (!subNode->line->isEmpty()) {

            int number = subNode->line->peek();
            std::cout << number << " ";
            subNode->line->dequeue();
        }
        cout << endl;
        preorder(subNode->left);
        preorder(subNode->right);
    }
}

int AVL::Height(AgacDugumu *subNode) {
    if (subNode == NULL) return -1;
    return 1 + max(Height(subNode->left), Height(subNode->right));
}

AVL::AVL() {
    kok = NULL;
}

bool AVL::isEmpty()const {
    return kok == NULL;
}

void AVL::Add(Kuyruk* item) {
    int num = item->sumQueue();
    kok = SearchAndAdd(kok, num, item);
}

void AVL::preorder() {
    preorder(kok);
}

int AVL::Height() {
    return Height(kok);
}

void AVL::Clear() {
    while (!isEmpty()) DeleteNode(kok);
}

AVL::~AVL() {
    Clear();
}
