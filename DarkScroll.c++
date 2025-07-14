#include<iostream>
#include<fstream>

using namespace std;

struct nodeL{
    int info;
    string text;
    nodeL *prox;
};

struct nodeLD{
    string Player;
    int nJogos, wins, loses;
    nodeLD *prox, *ant;
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
    nodeA *inserirAr(nodeA *raiz,int n);
};



class ListaE{
    private:
     nodeL *inicio;
   public:
     ListaE(){
        inicio = nullptr;
     }
     int inserirHistL(int comecoL, int fimL, int n);
     void listar(int n);
};

void ListaE::listar(int n){
   nodeL *atual;
   atual = inicio;
   while(atual!=nullptr){
      cout<<atual->text<<"\n";
      system("pause");
      system("cls");
      cout<<atual->info<<"\n";
      atual = atual -> prox;
   }
   cout<<"\n";
 }

class ListaDE{
     private:
     nodeLD *inicio;
   public:
     ListaDE(){
        inicio = nullptr;
     }
     int criarHis(string &arq, int comecoL, int fimL);
};

void menu(){
    ifstream sinopse;
    ifstream regras;
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
            regras.open("regras.txt");
            if(regras.is_open()){
                while(getline(regras,linha)){
                    cout << linha << endl;
                }
                regras.close();
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
            sinopse.open("historiaMenu.txt");
            if(sinopse.is_open()){
                while(getline(sinopse,linha)){
                    cout << linha << endl;
                }
                sinopse.close();
                system("pause");
            }
            else{
                cout<<"erro na abertura do arquivo"<< endl;
                system("pause");
            }
            break;
    
        default:
            break;
        }
    }
}

nodeA *Arvore::inserirAr(nodeA *raiz,int n){
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
            raiz -> dir = inserirAr(raiz ->dir, n);
            return raiz;
        }
        else if(raiz -> info >= n){
            raiz -> esq = inserirAr(raiz->esq, n);
            return raiz;
        }
        else
            cout<< "esse valor ja existe na arvore";
                return raiz;
    }
}

int ListaE::inserirHistL(int comecoL, int fimL, int n){
    nodeL *novo = new nodeL();
    nodeL *atual;
    novo->info = n;
    ifstream arquivo("HistoriaJogo.txt");
    string linha;
    string bloco;
    int numeroLinha = 1;
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return 0;
    }

    while (getline(arquivo, linha)) {
        if (numeroLinha >= comecoL && numeroLinha <= fimL) {
            bloco += linha + "\n"; // Adiciona a linha e uma quebra de linha
        }
        numeroLinha++;
    }
    arquivo.close();
    if(inicio == nullptr){
        inicio = novo;
        novo->text = bloco;
        novo->prox = nullptr;
        return 0;
    }
    atual = inicio;
    while(atual->prox!= nullptr){
        atual = atual->prox;
    }
    atual->prox = novo;
    novo->text = bloco;
    novo->prox = nullptr;
    cout << "Bloco armazenado:\n" << bloco;
    return 0;

}

int main(){
    Arvore arv;
    ListaE lise;
    system("cls");
    lise.inserirHistL(1,1,5);
    lise.listar(4);
    //menu();
}