#ifndef ARVOREHUFFMAN_H
#define ARVOREHUFFMAN_H
#include <sstream>
#include <Insercao.h>
#include <ListaGenerica.h>

void debug (frequenciador &freq,string cm=""){



    if(freq.esquerda!=NULL){
        //cout<<"pegou esquerda"<<endl;
        //cout<<freq.frequencia<<endl;

        debug(*freq.esquerda,cm+="0");



    }


    if(freq.direita!=NULL){
        //cout<<"pegou direita"<<endl;
        string temp="";
        for(int i=0;i<cm.size()-1;i++){
            temp+=cm[i];
        }
        cm=temp;

        cm+="1";
        //cout<<freq.frequencia<<endl;
        debug(*freq.direita,cm);
    }


    if(freq.esquerda==NULL&&freq.direita==NULL){



        //cout<<"tudo nulo "<<endl
        cout<<"letra :"<<freq.letra<<" "
        <<"frequencia"<<freq.frequencia<<endl;
        cout<<cm<<endl;
        cm="";

        cout<<endl<<endl;




        }

}



void criaArvore(ListaEncadeada<frequenciador>&palavras){
   ElementoEncadeado<frequenciador>*primeiro=palavras.inicio;
   ElementoEncadeado<frequenciador>*segundo=primeiro->proximo;

   frequenciador *esquerda=&primeiro->dado;
   frequenciador *direita=&segundo->dado;

   for(int i=0;i<2;i++){
       ElementoEncadeado<frequenciador>*excluir=palavras.inicio;
       palavras.inicio=excluir->proximo;


       if(excluir->dado.esquerda&&excluir->dado.direita==NULL){
           delete excluir;
           excluir=NULL;
       }
   }

   frequenciador *novo=new frequenciador;
   novo->frequencia=esquerda->frequencia+direita->frequencia;
   novo->esquerda=esquerda;
   novo->direita=direita;
   novo->letra=NULL;
   inserirFrequencia(palavras,*novo);
   cout<<"."<<endl;


}


#endif // ARVOREHUFFMAN_H
