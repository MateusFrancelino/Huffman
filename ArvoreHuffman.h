#ifndef ARVOREHUFFMAN_H
#define ARVOREHUFFMAN_H
#include <sstream>
#include <Insercao.h>
#include <ListaGenerica.h>

void exibirNode (Node &freq,string cm=""){// exibe o conteudo do node se existir



    if(freq.esquerda!=NULL){


        exibirNode(*freq.esquerda,cm+="0");



    }


    if(freq.direita!=NULL){

        string temp="";
        for(int i=0;i<cm.size()-1;i++){
            temp+=cm[i];
        }
        cm=temp;
        cm+="1";

        exibirNode(*freq.direita,cm);
    }


    if(freq.esquerda==NULL&&freq.direita==NULL){

        cout<<"letra :"<<freq.letra<<" "
        <<"frequencia"<<freq.frequencia<<endl;
        cout<<cm<<endl;
        cm="";

        cout<<endl<<endl;
        }

}


void visualizarArvore(Node node){// avisa que ira mostrar arvore

    cout<<"|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout<<"Motrando Arvore :"<<endl;
    exibirNode(node);


}


void criaArvore(ListaEncadeada<Node>&palavras){ // cria arvore sem recursividade para poder montar ela aparir da lista encadeada
   ElementoEncadeado<Node>*primeiro=palavras.inicio;
   ElementoEncadeado<Node>*segundo=primeiro->proximo;

   Node *esquerda=&primeiro->dado;
   Node *direita=&segundo->dado;

   for(int i=0;i<2;i++){
       ElementoEncadeado<Node>*excluir=palavras.inicio;
       palavras.inicio=excluir->proximo;


       if(excluir->dado.esquerda&&excluir->dado.direita==NULL){
           delete excluir;
           excluir=NULL;
       }
   }

   Node *novo=new Node;
   novo->frequencia=esquerda->frequencia+direita->frequencia;
   novo->esquerda=esquerda;
   novo->direita=direita;
   novo->letra=NULL;
   inserirFrequencia(palavras,*novo);

}



void criaArvore(Node *&node,string caminho,char letra){ // cria a arvore apartir do codigo binario

    if(node==NULL){

        Node *novo= new Node;

        novo->letra=NULL;
        novo->direita=NULL;
        novo->esquerda=NULL;
        novo->frequencia=0;

        node=novo;
        if(caminho.size()==0){

            novo->letra=letra;
        }

        else if(caminho[0]=='0'){
            caminho=caminho.erase(0,1);
            criaArvore(node->esquerda,caminho,letra);

        }
        else if(caminho[0]=='1'){
            caminho=caminho.erase(0,1);
            criaArvore(node->direita,caminho,letra);
        }


    }
    else{

        if(caminho[0]=='0'){
            caminho.erase(0,1);
            criaArvore(node->esquerda,caminho,letra);

        }else if(caminho[0]=='1'){
            caminho.erase(0,1);
            criaArvore(node->direita,caminho,letra);
        }else{
            cout<<"como chgou aqui?";
        }
    }
}


void prepararArvore(Raiz &raiz,string dado){// separa a string para termos a letra e o binario para criar a arvore

    string delimitador="=";
    size_t pos =0;
    string token;
    while((pos = dado.find(delimitador)!= string::npos)){
        token = dado.substr(0,pos);
        dado.erase(0,pos+delimitador.length());
    }
    criaArvore(raiz.inicio,dado,token[0]);

}


void deletarArvore(Node *&node){ // deleta a arvore

    if(node->esquerda!=NULL){


        deletarArvore(node->esquerda);



    }


    if(node->direita!=NULL){
        deletarArvore(node->direita);
    }


    if(node->esquerda==NULL&&node->direita==NULL){

        delete node;
        node=NULL;
        }








}





























#endif // ARVOREHUFFMAN_H
