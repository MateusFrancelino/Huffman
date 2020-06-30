#ifndef TXT_H
#define TXT_H
#include <iostream>
#include <fstream>
#include <ListaGenerica.h>
#include <Structs.h>
using namespace std;


void BinarioTexto (Node &freq,char letra,string cm=""){ // escreve o binario no txt
    if(freq.esquerda!=NULL){

        cm+="0";
        BinarioTexto(*freq.esquerda,letra,cm);
    }

    if(freq.direita!=NULL){

        string temp="";
        for(int i=0;i<cm.size()-1;i++){
            temp+=cm[i];
        }
        cm=temp;

        cm+="1";

        BinarioTexto(*freq.direita,letra,cm);
    }



    if(freq.letra==letra){
        string line;

        ifstream MyFile("Binario.txt");

        if(MyFile.is_open()){
            while (getline (MyFile,line)){


            }
            MyFile.close();
        }
        ofstream texto("Binario.txt");
        texto << line+cm;

        cout<<cm<<" ";
        texto.close();
        }
}


void BinarioLetra (string caminho,Node &freq,string cm=""){ // escreve a tabela no txt
    if(freq.esquerda!=NULL){

        cm+="0";
        BinarioLetra(caminho,*freq.esquerda,cm);
    }
    if(freq.direita!=NULL){

        string temp="";
        for(int i=0;i<cm.size()-1;i++){
            temp+=cm[i];
        }
        cm=temp;
        cm+="1";

        BinarioLetra(caminho,*freq.direita,cm);
    }
    if(freq.direita==NULL&&freq.esquerda==NULL){
        ListaEncadeada<string>linhas;
        inicializaListaEnc(linhas);

            string line;

            ifstream MyFile(caminho);

            if(MyFile.is_open()){
                while (getline (MyFile,line)){
                    InsereFimEnc(linhas,line+"\n");


                }
                MyFile.close();
            }
            string temp="="    ;
            InsereFimEnc(linhas,freq.letra+temp+cm);
            ofstream texto(caminho);
            ElementoEncadeado<string>*nav=linhas.inicio;
            while(nav!=NULL){
                texto<<nav->dado;
                nav=nav->proximo;
            }
            while(linhas.inicio!=NULL){
                ExcluiListaEnc(linhas);
            }

            texto.close();
        }

}


void Binarioacii (string caminho){ // escreve o binario traduzido para ascii no txt
        ListaEncadeada<string>linhas;
        inicializaListaEnc(linhas);

        int numero=0;

            string line;
            string textoascii="";

            ifstream MyFile("Binario.txt");

            if(MyFile.is_open()){
                getline (MyFile,line);
                for(int i=0;i<line.size();i++){
                    textoascii+=line[i];
                    if(textoascii.size()==8){
                        InsereFimEnc(linhas,textoascii);
                        textoascii="";
                    }
                }
                if(textoascii.size()<8){
                    while(textoascii.size()!=8){
                        textoascii+="0";
                    }
                }
                InsereFimEnc(linhas,textoascii);
                textoascii="";
                MyFile.close();
            }

            ofstream texto(caminho);
            ElementoEncadeado<string>*nav=linhas.inicio;
            while(nav!=NULL){

                numero=stoi(nav->dado,nullptr, 2);
                textoascii+=(char)numero;
                char x=numero;
                cout<<"letra : ";
                 cout<<x<<" ";
                cout<<nav->dado<<endl;

                nav=nav->proximo;
            }
            texto<<textoascii;
            while(linhas.inicio!=NULL){
                ExcluiListaEnc(linhas);
            }
            texto.close();

}


void textoDecodificado(char letra){// escreve no txt o texto decodificado
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










#endif // TXT_H
