#ifndef PROGRAMADECODIFICADOR_H
#define PROGRAMADECODIFICADOR_H
#include <iostream>
#include <fstream>
#include <ArvoreHuffman.h>
#include <TXT.h>


using namespace std;



bool decodificar(Node node,string caminho){

    if(caminho.size()==0&&node.esquerda==NULL&&node.direita==NULL){

        textoDecodificado(node.letra);
        return true;

    }
     else if(caminho[0]=='0'){
        caminho=caminho.erase(0,1);
        return decodificar(*node.esquerda,caminho);

    }
    else if(caminho[0]=='1'){
        caminho=caminho.erase(0,1);
        return decodificar(*node.direita,caminho);
    }else{

         return false;
     }

    return false;

}




void decodificador(string textocodificado,Raiz raiz){

    string binario="";
    bool decodificou=false;

    ofstream decod("Textodecodificado.txt");
    decod <<"";


    decod.close();
    cout<<"Texto decodificado : ";

    for(int i=0;i<textocodificado.size();i++){

        binario+=textocodificado[i];

        if((decodificou=decodificar(*raiz.inicio,binario))==true){
            binario="";

        }

        }

}




void programa1(){
    Raiz raiz;
    raiz.inicio=NULL;
    string textocodificado="";

    string linha,palavratexto;

    ifstream texto;
    texto.open("Binario.txt");

    if(texto.is_open()){
        cout<<"arquivo Aberto com sucesso"<<endl;
    }else {
        cout<<"erro ao abrir o arquivo"<<endl;
    }
    if(texto.is_open()){
        while(getline(texto,linha)){
            if(textocodificado==""){

                textocodificado=linha;

            }
            else{

                prepararArvore(raiz,linha);

            }
            }
        }

    visualizarArvore(*raiz.inicio);


    decodificador(textocodificado,raiz);


    deletarArvore(raiz.inicio);





}






#endif // PROGRAMADECODIFICADOR_H
