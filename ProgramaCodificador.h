#ifndef PROGRAMACODIFICADOR_H
#define PROGRAMACODIFICADOR_H
#include <iostream>
#include <fstream>
#include <ArvoreHuffman.h>
#include <TXT.h>
using namespace std;

void programa0(){
    ListaEncadeada<Node>palavras;
    inicializaListaEnc(palavras);


    string linha,palavratexto;

    ifstream texto;
    texto.open("frase.txt");

    ofstream ler("Binario.txt");
    ler << "";
    ler.close();

    if(texto.is_open()){
        cout<<"arquivo Aberto com sucesso"<<endl;
    }else {
        cout<<"erro ao abrir o arquivo"<<endl;
    }
    if(texto.is_open()){
        while(getline(texto,linha)){
            cout<<linha<<endl;

            for(int i=0;i<linha.size();i++){ // for para passar letra por letra da linha para montar a arvore

               estabelecerFrequencia(palavras,linha[i],linha);  // manda o char retirardo da linha e um lista encadeada



            }


        }
    }

    mostrarFrequencia(palavras);

    ElementoEncadeado<Node>*nav=palavras.inicio;
    while(nav->proximo!=NULL){
    criaArvore(palavras);     // ira criar a arvore apartir do elemento encadeado
    nav=palavras.inicio;
    }

    visualizarArvore(nav->dado);  // exibe a arvore para o usuario


    cout<<"Texto em Binario :";
    for(int i=0;i<linha.size();i++){
        BinarioTexto(nav->dado,linha[i]); //traduz o texto para binario e grava no txt

    }

    BinarioLetra("Binario.txt",nav->dado,"");  // escreve a tabela no txt

    cout<<endl;
    Binarioacii("textoascii.txt");   // traduz o binario para ascii

    BinarioLetra("textoascii.txt",nav->dado,"");  // escreve a tabalea no txt
    cout<<endl<<"Programa Finalizado"<<endl;



    Raiz raiz;
    raiz.inicio=&nav->dado;
    deletarArvore(raiz.inicio); //deleta a arvore completamente


}










#endif // PROGRAMACODIFICADOR_H
