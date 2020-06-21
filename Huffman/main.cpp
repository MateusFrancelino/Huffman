#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>

#include <ListaGenerica.h>
using namespace std;

struct frequenciador{
    char letra;
    int frequencia;
};

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
    novo->dado.letra=frequencia.letra;
    novo->dado.frequencia=frequencia.frequencia;

    if(palavras.inicio==NULL){

        palavras.inicio=novo;
     }else{
        ElementoEncadeado<frequenciador>*nav=palavras.inicio;
        ElementoEncadeado<frequenciador>*anterior;
        if(nav->dado.frequencia<frequencia.frequencia){
        while((nav->dado.frequencia<=frequencia.frequencia)){


            anterior=nav;
            nav=nav->proximo;
            if(nav==NULL){

            break;
            }

        }

      novo->proximo=anterior->proximo;
      anterior->proximo=novo;
        }else{

            novo->proximo=palavras.inicio;
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





int main()
{
    ListaEncadeada<frequenciador>palavras;
    inicializaListaEnc(palavras);


    string linha,palavratexto;
    char*palavra;
    char letra;
    ifstream texto;
    texto.open("frase.txt");
    if(texto.is_open()){
        cout<<"arquivo Aberto com sucesso"<<endl;
    }else {
        cout<<"erro ao abrir o arquivo"<<endl;
    }
    if(texto.is_open()){
        while(getline(texto,linha)){
            cout<<linha<<endl;

            for(int i=0;i<linha.size();i++){

               estabelecerFrequencia(palavras,linha[i],linha);



            }

        }
    }

    debug(palavras);

    return 0;
}
