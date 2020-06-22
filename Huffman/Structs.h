#ifndef STRUCTS_H
#define STRUCTS_H



struct frequenciador{
    char letra;
    int frequencia;
    frequenciador *direita;
    frequenciador *esquerda;

};



#endif // STRUCTS_H
