#ifndef INSERCAO_H
#define INSERCAO_H
#include <Structs.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <ListaGenerica.h>

bool verificaItemExiteLista(ListaEncadeada<frequenciador>&palavras,char dado){

    if(palavras.inicio!=NULL){
    ElementoEncadeado<frequenciador>*nav=palavras.inicio;

    while(nav!=NULL){
        if(nav->dado.letra==dado){


            return true;
        }


        nav=nav->proximo;
    }
    }


    return false;
}


void inserirFrequencia(ListaEncadeada<frequenciador>&palavras,frequenciador frequencia){

    ElementoEncadeado<frequenciador>*novo=new ElementoEncadeado<frequenciador>;
    novo->proximo=NULL;
    novo->dado=frequencia;
    if(palavras.inicio==NULL){

        palavras.inicio=novo;
     }else{
        ElementoEncadeado<frequenciador>*nav=palavras.inicio;
        ElementoEncadeado<frequenciador>*anterior;
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

void estabelecerFrequencia(ListaEncadeada<frequenciador>&palavras,char letra,string linha){

    if(!verificaItemExiteLista(palavras,letra)){
       int vezes=0;

       for(int i=0;i<linha.size();i++){
           if(linha[i]==letra){

               vezes++;
           }

       }
       frequenciador letsr;
       letsr.letra=letra;
       letsr.frequencia=vezes;
       letsr.direita=NULL;
       letsr.esquerda=NULL;


       inserirFrequencia(palavras,letsr);

    }

}


void debug(ListaEncadeada<frequenciador>&letras){
    ElementoEncadeado<frequenciador>*letra=letras.inicio;

    while(letra!=NULL){
        cout<<"Letra :"<<letra->dado.letra<<endl
            <<"Vezes que Repetiu :"<<letra->dado.frequencia<<endl
            <<"|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
        letra=letra->proximo;

    }
}





#endif // INSERCAO_H
