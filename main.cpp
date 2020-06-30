#include <ProgramaDecodificador.h>
#include <ProgramaCodificador.h>


int main()
{   int escolha=0;
    bool continuar=true;

    while(continuar){

    cout<<"digite sua escolha"<<endl;
    cout<<"para codificar digite 0"<<endl;
    cout<<"para decodificar digite 1"<<endl;
    cin>>escolha;
    if(escolha==0){

     programa0();         //inicia o programa que codifica o txt


    }else if(escolha==1){
       programa1();      // inicia o programa que decodifica o txt

    }else{
        cout<<"numero invalido";
    }


    cout<<endl;
    cout<<"digite sua escolha"<<endl;
    cout<<"para continuar 0"<<endl;
    cout<<"para sair 1"<<endl;
    cin>>escolha;
    if(escolha==1){
        continuar=false;            // false = encerrar programa
    }else{
        system("cls");
    }

}
    return 0;
}
