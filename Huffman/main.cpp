#include <iostream>


#include <ArvoreHuffman.h>

using namespace std;







int main()
{
    ListaEncadeada<frequenciador>palavras;
    inicializaListaEnc(palavras);


    string linha,palavratexto;

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

    //debug(palavras);

    ElementoEncadeado<frequenciador>*nav=palavras.inicio;
    while(nav->proximo!=NULL){
    criaArvore(palavras);
    nav=palavras.inicio;
    }

    debug(nav->dado);




































    cout<<endl<<"Programa Finalizado"<<endl;
coiso();
    return 0;
}
