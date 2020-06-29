#ifndef PROGRAMACODIFICADOR_H
#define PROGRAMACODIFICADOR_H
#include <iostream>
#include <fstream>
#include <ArvoreHuffman.h>

using namespace std;


void BinarioTexto (frequenciador &freq,char letra,string cm=""){


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

void BinarioLetra (string caminho,frequenciador &freq,string cm=""){
    if(freq.esquerda!=NULL){
        //cout<<"pegou esquerda"<<endl;
        //cout<<freq.frequencia<<endl;
        cm+="0";
        BinarioLetra(caminho,*freq.esquerda,cm);
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



void Binarioacii (string caminho){


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
                        cout<<"binario: "<<textoascii<<endl;
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
                cout<<"letra";
                cout<<nav->dado<<endl;
                cout<<x<<endl;
                nav=nav->proximo;
            }
            texto<<textoascii;
            while(linhas.inicio!=NULL){
                ExcluiListaEnc(linhas);
            }
            texto.close();

}






void programa0(){
    ListaEncadeada<frequenciador>palavras;
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

            for(int i=0;i<linha.size();i++){

               estabelecerFrequencia(palavras,linha[i],linha);



            }


        }
    }

    debug(palavras);







    ElementoEncadeado<frequenciador>*nav=palavras.inicio;
    while(nav->proximo!=NULL){
    criaArvore(palavras);
    nav=palavras.inicio;
    }

     debug(nav->dado);


    for(int i=0;i<linha.size();i++){
        BinarioTexto(nav->dado,linha[i]);

    }
    BinarioLetra("Binario.txt",nav->dado,"");
    Binarioacii("textoascii.txt");
    BinarioLetra("textoascii.txt",nav->dado,"");
    cout<<endl<<"Programa Finalizado"<<endl;
    cout<<linha.size();


}










#endif // PROGRAMACODIFICADOR_H
