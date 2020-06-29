#ifndef PROGRAMADECODIFICADOR_H
#define PROGRAMADECODIFICADOR_H
#include <iostream>
#include <fstream>
#include <ArvoreHuffman.h>


using namespace std;

void textoDecodificado(char letra){
cout<<letra;

    string line;

    ifstream MyFile("Textodecodificado.txt");

    if(MyFile.is_open()){
        while (getline (MyFile,line)){


        }
        MyFile.close();
    }





    ofstream texto("Textodecodificado.txt");
    texto << line+letra;


    texto.close();






}


void criaArvore(frequenciador *&node,string caminho,char letra){

    if(node==NULL){

        frequenciador *novo= new frequenciador;

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



void prepararArvore(Raiz &raiz,string dado){

    string delimitador="=";
    size_t pos =0;
    string token;
    while((pos = dado.find(delimitador)!= string::npos)){
        token = dado.substr(0,pos);
        dado.erase(0,pos+delimitador.length());
    }
    criaArvore(raiz.inicio,dado,token[0]);





}

bool decodificar(frequenciador node,string caminho){



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

    debug(*raiz.inicio);



    string binario="";
    bool decodificou=false;

    ofstream decod("Textodecodificado.txt");
    decod <<"";


    decod.close();

    for(int i=0;i<textocodificado.size();i++){

        binario+=textocodificado[i];




        if((decodificou=decodificar(*raiz.inicio,binario))==true){
            binario="";

        }

        }

}






#endif // PROGRAMADECODIFICADOR_H
