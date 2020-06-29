#ifndef STRUCTS_H
#define STRUCTS_H
#include <iostream>


using namespace std;

struct frequenciador{
    char letra=NULL;
    int frequencia=0;
    frequenciador *direita=NULL;
    frequenciador *esquerda=NULL;


};

struct Raiz{
    frequenciador *inicio=NULL;
};




#endif // STRUCTS_H
