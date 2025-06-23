#include<iostream>
#include<fstream>

using namespace std;

struct nodeL{
    int info;
    nodeL *dir;
};

struct nodeA{
    int info;
    nodeA *dir, *esq;
};

class Arvore{
    public:
    nodeA *raiz;
    Arvore(){
        raiz = nullptr;
    }
    nodeA *inserir(nodeA *raiz,int n);
};

void menu(){
    ifstream menu;
    string linha;
    int n;
    bool continuar = true;
    
    while(continuar){
        system("cls");
        cout<<"              MENU"<<"\n";
        cout<<"1 jogar"<<"\n";
        cout<<"2 regras"<<"\n";
        cout<<"3 historia"<<"\n\n";
        cout << "escolha: ";
        while(true){
            cin >> n;
        if(n == 1 || n == 2 || n ==3){
            cout<<"valor valido";
            break;
        }
        else{
            system("cls");
            cout<<"valor invalido, tente outro: "<<"\n";
            cin>> n;
        }
        }
        
        switch (n)
        {
        case 1:
            system("cls");
            continuar = false;
            break;
        case 2:
            system("cls");
            menu.open("regras.txt");
            if(menu.is_open()){
                while(getline(menu,linha)){
                    cout << linha << endl;
                }
                menu.close();
                cout << "\n";
                system("pause");
                system("cls");
            }
            else{
                cout<<"erro na abertura do arquivo"<< endl;
                system("pause");
            }
            break;
        case 3: 
            system("cls");
            menu.open("historiaMenu.txt");
            if(menu.is_open()){
                while(getline(menu,linha)){
                    cout << linha << endl;
                }
                menu.close();
                system("pause");
            }
            else{
                cout<<"erro na abertura do arquivo"<< endl;
                system("pause");
            }
        /* code */
            break;
    
        default:
            break;
        }
    }
}

nodeA *Arvore::inserir(nodeA *raiz,int n){
    if(raiz == nullptr){
        raiz = new nodeA();
        if(raiz == nullptr)
            exit(1);
        raiz ->dir = nullptr;
        raiz ->esq = nullptr;
        raiz -> info = n;
        return raiz;
    }
    else{
        if(raiz -> info <= n){
            raiz -> dir = inserir(raiz ->dir, n);
            return raiz;
        }
        else if(raiz -> info >= n){
            raiz -> esq = inserir(raiz->esq, n);
            return raiz;
        }
        else
            cout<< "esse valor ja existe na arvore";
                return raiz;
    }
        

}

int main(){
    menu();
    Arvore arv;
    arv.raiz = arv.inserir(arv.raiz,5);
    arv.raiz = arv.inserir(arv.raiz,15);
    arv.raiz = arv.inserir(arv.raiz,20);
    arv.raiz = arv.inserir(arv.raiz,4);
    arv.raiz = arv.inserir(arv.raiz,1);
    arv.raiz = arv.inserir(arv.raiz,30);
    arv.raiz = arv.inserir(arv.raiz,25);
}