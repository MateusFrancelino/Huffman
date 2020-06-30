#ifndef STRUCTS_H
#define STRUCTS_H
#include <iostream>


using namespace std;

struct Node{
    char letra=NULL;
    int frequencia=0;
    Node *direita=NULL;
    Node *esquerda=NULL;


};

struct Raiz{  //
    Node *inicio=NULL;
};




#endif // STRUCTS_H
