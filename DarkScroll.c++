#include<iostream>
#include<fstream>

using namespace std;

struct nodeL{
    int info;
    string text;
    nodeL *prox;
};

struct nodeLD{
    string player;
    string titulo;
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
    void criarArvore();
    void jogar(nodeA *raiz, string nome, string titulo);
};

class ListaE{
    private:
     nodeL *inicio;
   public:
     ListaE(){
        inicio = nullptr;
     }
     int inserirHistL(int comecoL, int fimL, int n);
     void criarListaE();
     void listar(int n);
};

class ListaDE{
     private:
     nodeLD *inicio;
   public:
     ListaDE(){
        inicio = nullptr;
     }
     int addPlayer(string nome, string titulo, int nJogos, int win, int loses);
};

void Arvore::criarArvore(){
    Arvore arv;
    arv.raiz = inserirAr(arv.raiz, 200);
    arv.raiz = inserirAr(arv.raiz, 300);
    arv.raiz = inserirAr(arv.raiz, 350);
    arv.raiz = inserirAr(arv.raiz, 250);
    arv.raiz = inserirAr(arv.raiz, 260);
    arv.raiz = inserirAr(arv.raiz, 220);
    arv.raiz = inserirAr(arv.raiz, 320);
    arv.raiz = inserirAr(arv.raiz, 360);
    arv.raiz = inserirAr(arv.raiz, 218);
    arv.raiz = inserirAr(arv.raiz, 230);
    arv.raiz = inserirAr(arv.raiz, 315);
    arv.raiz = inserirAr(arv.raiz, 330);
    arv.raiz = inserirAr(arv.raiz, 216);
    arv.raiz = inserirAr(arv.raiz, 219);
    arv.raiz = inserirAr(arv.raiz, 215);
    arv.raiz = inserirAr(arv.raiz, 217);
    arv.raiz = inserirAr(arv.raiz, 100);
    arv.raiz = inserirAr(arv.raiz, 150);
    arv.raiz = inserirAr(arv.raiz, 50);
    arv.raiz = inserirAr(arv.raiz, 25);
    arv.raiz = inserirAr(arv.raiz, 75);
    arv.raiz = inserirAr(arv.raiz, 20);
    arv.raiz = inserirAr(arv.raiz, 27);
    arv.raiz = inserirAr(arv.raiz, 18);
    arv.raiz = inserirAr(arv.raiz, 22);
    arv.raiz = inserirAr(arv.raiz, 16);
    arv.raiz = inserirAr(arv.raiz, 19);
    arv.raiz = inserirAr(arv.raiz, 14);
    arv.raiz = inserirAr(arv.raiz, 17);
    arv.raiz = inserirAr(arv.raiz, 12);
    arv.raiz = inserirAr(arv.raiz, 15);
    arv.raiz = inserirAr(arv.raiz, 10);
    arv.raiz = inserirAr(arv.raiz, 13);
    arv.raiz = inserirAr(arv.raiz, 8);
    arv.raiz = inserirAr(arv.raiz, 11);
    arv.raiz = inserirAr(arv.raiz, 6);
    arv.raiz = inserirAr(arv.raiz, 9);
}

void ListaE::criarListaE(){
    ListaE listaE;
    
    listaE.inserirHistL(1,4,200);//ponto de convergencia
    //1°rota
    listaE.inserirHistL(6,9,100);//titulo (individuo esquecido)
    listaE.inserirHistL(11,11,150);//game over
    listaE.inserirHistL(13,16,50);//titulo (individuo esquecido)
    listaE.inserirHistL(18,18,75);//game over
    listaE.inserirHistL(20,24,25);
    listaE.inserirHistL(26,26,27);//game over
    listaE.inserirHistL(28,21,20);
    listaE.inserirHistL(33,33,22);//game over
    listaE.inserirHistL(35,48,18);//titulo (Ex comandante carmesin)
    listaE.inserirHistL(50,50,19);//game over
    listaE.inserirHistL(51,57,16);
    listaE.inserirHistL(59,59,17);//game over
    listaE.inserirHistL(61,68,14);//titulo (traidor elfico)
    listaE.inserirHistL(70,70,15);//game over
    listaE.inserirHistL(72,75,12);
    listaE.inserirHistL(77,77,13);//game over
    listaE.inserirHistL(78,82,10);
    listaE.inserirHistL(84,84,11);//game over
    listaE.inserirHistL(85,98,8);
    listaE.inserirHistL(100,111,9);//final mal (senhor das feras)
    listaE.inserirHistL(113,128,6);//final bom(Aquele Que Recusou o Poder)
    //2°rota
    listaE.inserirHistL(131,173,300);//titulo(O homem da Profecia)convergencia bom/mal
    //bom
    listaE.inserirHistL(175,203,250);//titulo (Guardião Verdejante)
    listaE.inserirHistL(205,211,260);//game over
    listaE.inserirHistL(213,244,220);//titulo (Portador da Lembrança)
    listaE.inserirHistL(246,254,230);//game over
    listaE.inserirHistL(256,288,218);//titulo (Guardião da Alma Dividida)
    listaE.inserirHistL(290,297,219);//game over
    listaE.inserirHistL(299,334,216);//titulo (Guardião da Esperança)
    listaE.inserirHistL(336,342,217);//final-titulo (Salvador Desconhecido)
    listaE.inserirHistL(344,349,215);//final-titulo (Pilar da Paz)
    //mal
    listaE.inserirHistL(357,389,350);//titulo (Executor da Ordem natural)
    listaE.inserirHistL(391,393,360);//game over
    listaE.inserirHistL(395,450,320);//titulo (O vazio Enraizado)
    listaE.inserirHistL(453,454,330);//game over
    listaE.inserirHistL(456,480,315);//final-titulo (A ruina dos 3 reinos)
}

void ListaE::listar(int n){
    nodeL *atual;
    atual = inicio;
    while(atual!=nullptr){
        if(atual->info == n){
            cout<<atual->text<<"\n";
            system("pause");
            system("cls");
            cout<<atual->info<<"\n";
            break;
        }
        atual = atual -> prox;
   }
   cout<<"\n";
 }

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
        if(raiz -> info < n){
            raiz -> dir = inserirAr(raiz ->dir, n);
            return raiz;
        }
        else if(raiz -> info > n){
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
    return 0;

}

void Arvore::jogar(nodeA *raiz, string nome, string titulo){
    int op;
    if(raiz = nullptr){
        return;
    }
    else{
        while(true){
            cin>>op;
            if(op == 1 || op == 2){
                break;
            }
            else{
                cout<<"opção invalida, tente outra: \n";
            }
        }
        if(op == 1){
            jogar(raiz->esq, nome, titulo);
        }
        else
            jogar(raiz->dir, nome, titulo);
        
    }
        
}

int main(){
    Arvore arv;
    ListaE lise;
    arv.criarArvore();
    system("cls");
    lise.inserirHistL(1,4,200);
    lise.inserirHistL(5,9,100);
    lise.listar(200);
    lise.listar(100);
    
}