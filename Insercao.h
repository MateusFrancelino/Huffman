#ifndef INSERCAO_H
#define INSERCAO_H
#include <Structs.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <ListaGenerica.h>

bool verificaItemExiteLista(ListaEncadeada<Node>&palavras,char dado){ // verificação se existe a letra na lista

    if(palavras.inicio!=NULL){
    ElementoEncadeado<Node>*nav=palavras.inicio;

    while(nav!=NULL){
        if(nav->dado.letra==dado){


            return true;
        }


        nav=nav->proximo;
    }
    }


    return false;
}


void inserirFrequencia(ListaEncadeada<Node>&palavras,Node frequencia){ //cria o elemento encadeado ordenado por frequencia

    ElementoEncadeado<Node>*novo=new ElementoEncadeado<Node>;
    novo->proximo=NULL;
    novo->dado=frequencia;
    if(palavras.inicio==NULL){

        palavras.inicio=novo;
     }else{
        ElementoEncadeado<Node>*nav=palavras.inicio;
        ElementoEncadeado<Node>*anterior;
        if(nav->dado.frequencia<frequencia.frequencia){
        while(nav!=NULL && nav->dado.frequencia<=frequencia.frequencia){


            anterior=nav;
            nav=nav->proximo;
        }

      novo->proximo=anterior->proximo;
      anterior->proximo=novo;
        }else{

            novo->proximo=nav;
            palavras.inicio=novo;
        }

    }

}

void estabelecerFrequencia(ListaEncadeada<Node>&palavras,char letra,string linha){ // passa todo o texto e verifica quantas vezes a letra aparece
    if(!verificaItemExiteLista(palavras,letra)){// verifica se ja existe esta letra na lista
       int vezes=0;

       for(int i=0;i<linha.size();i++){
           if(linha[i]==letra){
               vezes++;
           }
       }
       Node letsr;
       letsr.letra=letra;
       letsr.frequencia=vezes;
       letsr.direita=NULL;
       letsr.esquerda=NULL;
       inserirFrequencia(palavras,letsr);
    }
}


void mostrarFrequencia(ListaEncadeada<Node>&letras){  // passa a lista e mostra a frequencia de cada letra
    ElementoEncadeado<Node>*letra=letras.inicio;

    while(letra!=NULL){
        cout<<"Letra :"<<letra->dado.letra<<endl
            <<"Vezes que Repetiu :"<<letra->dado.frequencia<<endl
            <<"|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
        letra=letra->proximo;
    }
}





#endif // INSERCAO_H
