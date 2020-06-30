#ifndef LISTAGENERICA_H
#define LISTAGENERICA_H

#include<iostream>
using namespace std;



#include<iostream>
using namespace std;



template <typename TIPO>
struct Titem{
    TIPO dado;
};

template <typename TIPO,int MAX>
struct ListaEstatica{

    Titem<TIPO>item[MAX];
    int qtd;

};

template <typename TIPO, int MAX>
void InserePListaEstatica(ListaEstatica<TIPO,MAX>&l,TIPO dado,int pos){

    l.item[pos].dado=dado;
    l.qtd++;
};

template<typename TIPO, int MAX>
TIPO obterItemLista(ListaEstatica<TIPO,MAX>&l,int pos){
    if(pos<MAX){
        return l.item[pos].dado;
    }
    throw "item nao existe";
}


template <typename TIPO,int MAX>
bool buscaItem(ListaEstatica<TIPO,MAX>&l,TIPO dado){

    return buscaItem(l,dado);


}

template <typename TIPO,int MAX>
int descobreIndiceLista(ListaEstatica<TIPO,MAX>&l,TIPO dado){

    return descobreIndiceLista(l,dado);

}
/*
=====================================================================================================================
*/




template <typename TIPO>
struct ElementoEncadeado{
    ElementoEncadeado<TIPO> *proximo;
    TIPO dado;
};

template<typename TIPO>
struct ListaEncadeada{
    ElementoEncadeado<TIPO> *inicio;
};


template<typename TIPO>
void inicializaListaEnc(ListaEncadeada<TIPO>&l){
    l.inicio=NULL;
}

template<typename TIPO>
void InsereFimEnc(ListaEncadeada<TIPO>&L,TIPO dado){
   ElementoEncadeado<TIPO>*novo=new ElementoEncadeado<TIPO>;
   novo->dado=dado;
   if(L.inicio == NULL){
       novo->proximo=NULL;
       L.inicio=novo;
   }else{
       ElementoEncadeado<TIPO>*nav=L.inicio;
       while(nav->proximo!=NULL){
           nav=nav->proximo;
       }
       nav->proximo=novo;
       novo->proximo=NULL;
   }
}

template <typename TIPO>
void ExcluiListaEnc(ListaEncadeada<TIPO>&l){
    ElementoEncadeado<TIPO>*excluir=l.inicio;
    ElementoEncadeado<TIPO>*nav;
while(l.inicio!=NULL){
    excluir=l.inicio;
    while(excluir->proximo!=NULL){
        nav=excluir;
        excluir=excluir->proximo;
    }

if(nav==l.inicio){
    delete nav;
    l.inicio=NULL;
    delete excluir;
}
else{
    nav->proximo=NULL;
    delete excluir;
}}}



template<typename TIPO>
void ExcluirPosicao(ListaEncadeada<TIPO>&l,int pos){
    if(l.inicio!=NULL){

        ElementoEncadeado<TIPO>*nav=l.inicio;
        ElementoEncadeado<TIPO>*anterior=l.inicio;
        for(int i=0;i<pos-1;i++){

            anterior=nav;
            nav=nav->proximo;

            if(nav==NULL){
                cout<<"Nao existe posicao"<<endl;
                break;
            }
        }
        if(pos==1){
            l.inicio=nav->proximo;
            delete nav;
            nav=NULL;
        }else{
            if(nav!=NULL){
              ElementoEncadeado<TIPO>*excluir=nav;

              anterior->proximo=excluir->proximo;
             delete excluir;
             excluir=NULL;
            }
        }
}
    }


template <typename TIPO>
void debug(ListaEncadeada<TIPO>&l){
    debug(l);
}

template<typename TIPO>
int contaColisaoEnc(ListaEncadeada<TIPO>&l){

    ElementoEncadeado<TIPO>*nav=l.inicio;
    int contagem=0;
    while (nav->proximo!=NULL) {
        contagem++;
        nav=nav->proximo;
    }
    return contagem;


}




/*
=====================================================================================================================
*/

template <typename TIPO>
struct ElementoDuplaEnc{
    ElementoDuplaEnc<TIPO> *proximo;
    ElementoDuplaEnc<TIPO> *anterior;
    TIPO dado;
};

template <typename TIPO>
struct ListaDuplaEnc{
    ElementoDuplaEnc<TIPO> *inicio;
    ElementoDuplaEnc<TIPO> *fim;

};

template<typename TIPO>
void inicializaListaDuplaEnc(ListaDuplaEnc<TIPO>&l){
    l.inicio=NULL;
    l.fim=NULL;
}

template <typename TIPO>
void InsereDuplaEncFim(ListaDuplaEnc<TIPO>&l,TIPO dado){
    ElementoDuplaEnc<TIPO> *novo=new ElementoDuplaEnc<TIPO>;
    novo->dado=dado;
    novo->proximo=NULL;
    novo->anterior=NULL;



    if(l.inicio==NULL && l.fim==NULL){
        l.inicio=novo;
        l.fim=novo;

    }else{
        ElementoDuplaEnc<TIPO> *nav=l.inicio;

        while(nav->proximo!=NULL){
            nav=nav->proximo;
        }
        nav->proximo = novo;
        novo->anterior = l.fim;

        l.fim = novo;
    }
}
template <typename TIPO>
void ExcluirListaDuplaEnc(ListaDuplaEnc<TIPO>&l){
    ElementoDuplaEnc<TIPO>*excluir=l.inicio;

    if(excluir->proximo==NULL){
        delete excluir;
        l.inicio=NULL;
        l.fim=NULL;
    }
    else{
        ElementoDuplaEnc<TIPO>*nav=excluir->proximo;
        l.inicio=nav;
        delete excluir;
      }}

template <typename TIPO>
void debug(ListaDuplaEnc<TIPO>&l){
    debug(l);
}

template <typename TIPO>
int contarListaDuplaEnc(ListaDuplaEnc<TIPO>l){
    ElementoDuplaEnc<TIPO>*nav=l.inicio;
    int contagem=0;
    while(nav!=NULL){
        contagem++;
        nav=nav->proximo;

    }
    return contagem;


}

/*
=====================================================================================================================
*/


template<typename TIPO>
struct ElementoCircular{
    ElementoCircular<TIPO> *proximo;
    TIPO dado;
};

template<typename TIPO>
struct ListaCircular{
  ElementoCircular<TIPO> *inicio;
};

template<typename TIPO>
void inicializaListaCircular(ListaCircular<TIPO>&l){
    l.inicio=NULL;
}

template <typename TIPO>
void InsereCicurlarFim(ListaCircular<TIPO>&l,TIPO dado){

    ElementoCircular<TIPO> *novo=new ElementoCircular<TIPO>;
    novo->dado=dado;
    if(l.inicio==NULL){
        novo->proximo=novo;
        l.inicio=novo;
        }
    else{
        ElementoCircular<TIPO>*nav=l.inicio;
        while(nav->proximo!=l.inicio){
            nav=nav->proximo;
        }
        nav->proximo=novo;
        novo->proximo=l.inicio;
    }
}


template <typename TIPO>
void debug(ListaCircular<TIPO>&l){
    debug(l);
}



#endif // LISTAGENERICA_H
