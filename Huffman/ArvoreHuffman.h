#ifndef ARVOREHUFFMAN_H
#define ARVOREHUFFMAN_H
#include <sstream>
#include <Insercao.h>
#include <ListaGenerica.h>
string cm2pika="";
void debug (frequenciador &freq,string cm=""){



    if(freq.esquerda!=NULL){
        //cout<<"pegou esquerda"<<endl;
        //cout<<freq.frequencia<<endl;
        cm+="0";
        debug(*freq.esquerda,cm);
    }


    if(freq.direita!=NULL){
        //cout<<"pegou direita"<<endl;
        cm+="1";
        //cout<<freq.frequencia<<endl;
        debug(*freq.direita,cm);
    }

    if(freq.direita==NULL&&freq.esquerda==NULL){
        cm2pika.append(cm);
        stringstream geek(cm2pika);
        int x=0;
        geek>>x;
        //cout<<"tudo nulo "<<endl
        cout<<"letra :"<<freq.letra<<endl;
        //<<"frequencia"<<freq.frequencia<<endl;
        cout<<"binario"<<cm<<endl;
        cout<<"binario"<<(char)x<<endl;


        }

}

void coiso(){
    cout<<cm2pika;

};

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
   cout<<".";


}


#endif // ARVOREHUFFMAN_H
