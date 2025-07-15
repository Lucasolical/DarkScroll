#include<iostream>
#include<fstream>
#include<windows.h>
#include <locale.h>
using namespace std;
//usado 
struct nodeL{
    int info;
    string text;
    nodeL *prox;
};
//usado mas talvez errado
struct nodeLD{
    string player;
    string titulos;
    int nJogos, wins, loses;
    nodeLD *prox, *ant;
};
//usado
struct nodeA{
    int info;
    nodeA *dir, *esq;
};

class ListaE{
    public:
     nodeL *inicio;
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
     int inserirScorePlayer(ListaDE &lista, string nome, string titulo, int win, int lose);
};

class Arvore{
    public:
    nodeA *raiz;
    Arvore(){
        raiz = nullptr;
    }
    nodeA *inserirAr(nodeA *raiz,int n);
    void criarArvore();
    void jogar(nodeA *raiz, ListaDE &listade, ListaE &lista, string nome, string titulo);
};



string gerarTitulo(int n){
    string titulo;
    if(n == 200)
        titulo = "individuo esquecido";
    else if(n == 18)
        titulo = "Ex comandante carmesin";
    else if(n == 14)
        titulo = "traidor elfico";
    else if(n == 9)
        titulo = "senhor das feras";
    else if(n == 6)
        titulo = "Aquele Que Recusou o Poder";
    else if(n == 300)
        titulo = "O homem da Profecia";
    else if(n == 250)
        titulo = "Guardião Verdejante";
    else if(n == 220)
        titulo = "Portador da Lembrança";
    else if(n == 218)
        titulo = "Guardião da Alma Dividida";
    else if(n == 216)
        titulo = "Guardião da Esperança";
    else if(n == 217)
        titulo = "Salvador Desconhecido";
    else if(n == 215)
        titulo = "Pilar da Paz";
    else if(n == 350)
        titulo = "Executor da Ordem natural";
    else if(n == 320)
        titulo = "O vazio Enraizado";
    else if(n == 315)
        titulo = "A ruina dos 3 reinos";
    return titulo;
}

void Arvore::criarArvore(){
    
    raiz = inserirAr(raiz, 200);
    raiz = inserirAr(raiz, 300);
    raiz = inserirAr(raiz, 350);
    raiz = inserirAr(raiz, 250);
    raiz = inserirAr(raiz, 260);
    raiz = inserirAr(raiz, 220);
    raiz = inserirAr(raiz, 320);
    raiz = inserirAr(raiz, 360);
    raiz = inserirAr(raiz, 218);
    raiz = inserirAr(raiz, 230);
    raiz = inserirAr(raiz, 315);
    raiz = inserirAr(raiz, 330);
    raiz = inserirAr(raiz, 216);
    raiz = inserirAr(raiz, 219);
    raiz = inserirAr(raiz, 215);
    raiz = inserirAr(raiz, 217);
    raiz = inserirAr(raiz, 100);
    raiz = inserirAr(raiz, 150);
    raiz = inserirAr(raiz, 50);
    raiz = inserirAr(raiz, 25);
    raiz = inserirAr(raiz, 75);
    raiz = inserirAr(raiz, 20);
    raiz = inserirAr(raiz, 27);
    raiz = inserirAr(raiz, 18);
    raiz = inserirAr(raiz, 22);
    raiz = inserirAr(raiz, 16);
    raiz = inserirAr(raiz, 19);
    raiz = inserirAr(raiz, 14);
    raiz = inserirAr(raiz, 17);
    raiz = inserirAr(raiz, 12);
    raiz = inserirAr(raiz, 15);
    raiz = inserirAr(raiz, 10);
    raiz = inserirAr(raiz, 13);
    raiz = inserirAr(raiz, 8);
    raiz = inserirAr(raiz, 11);
    raiz = inserirAr(raiz, 6);
    raiz = inserirAr(raiz, 9);
}

void ListaE::criarListaE(){
    inserirHistL(1,4,200);//ponto de convergencia//titulo (individuo esquecido)
    //1°rota
    inserirHistL(6,9,100);
    inserirHistL(11,11,150);//game over
    inserirHistL(13,16,50);
    inserirHistL(18,18,75);//game over
    inserirHistL(20,24,25);
    inserirHistL(26,26,27);//game over
    inserirHistL(28,21,20);
    inserirHistL(33,33,22);//game over
    inserirHistL(35,48,18);//titulo (Ex comandante carmesin)
    inserirHistL(50,50,19);//game over
    inserirHistL(51,57,16);
    inserirHistL(59,59,17);//game over
    inserirHistL(61,68,14);//titulo (traidor elfico)
    inserirHistL(70,70,15);//game over
    inserirHistL(72,75,12);
    inserirHistL(77,77,13);//game over
    inserirHistL(78,82,10);
    inserirHistL(84,84,11);//game over
    inserirHistL(85,98,8);
    inserirHistL(100,111,9);//final mal (senhor das feras)
    inserirHistL(113,128,6);//final bom(Aquele Que Recusou o Poder)
    //2°rota
    inserirHistL(131,173,300);//titulo(O homem da Profecia)convergencia bom/mal
    //bom
    inserirHistL(175,203,250);//titulo (Guardião Verdejante)
    inserirHistL(205,211,260);//game over
    inserirHistL(213,244,220);//titulo (Portador da Lembrança)
    inserirHistL(246,254,230);//game over
    inserirHistL(256,288,218);//titulo (Guardião da Alma Dividida)
    inserirHistL(290,297,219);//game over
    inserirHistL(299,334,216);//titulo (Guardião da Esperança)
    inserirHistL(336,342,217);//final-titulo (Salvador Desconhecido)
    inserirHistL(344,349,215);//final-titulo (Pilar da Paz)
    //mal
    inserirHistL(357,389,350);//titulo (Executor da Ordem natural)
    inserirHistL(391,393,360);//game over
    inserirHistL(395,450,320);//titulo (O vazio Enraizado)
    inserirHistL(453,454,330);//game over
    inserirHistL(456,480,315);//final-titulo (A ruina dos 3 reinos)
}

int ListaDE::inserirScorePlayer(ListaDE &lista, string nome, string titulo, int win, int lose){
    nodeLD *novo;
    nodeLD *atual;
    //sem jogador na lista
    if(inicio == nullptr){
        novo = new nodeLD();
        novo->player = nome;
        novo->ant = nullptr;
        novo->prox = nullptr;
        novo->loses = lose;
        novo->nJogos = 1;
        novo->titulos = titulo;
        novo->wins = win;
        inicio = novo;
        return 1;
    }
    atual = inicio;
    while(atual != nullptr){
        //jogador ja na lista
        if(atual->player == nome){
            atual->loses += lose;
            atual->nJogos += 1;
            atual->wins += win;
            atual->titulos = titulo;
            return 1;
        }

        if(atual->prox == nullptr)
            break;
        atual = atual->prox;
    }
    //novo jogador na lista
    novo = new nodeLD();
    novo->ant = atual;
    novo->prox = nullptr;
    novo->loses = lose;
    novo->wins = win;
    novo->nJogos = 1;
    novo->player = nome;
    novo->titulos = titulo;
    atual->prox = novo;
    return 1;
}

void ListaE::listar(int n){
    nodeL *atual;
    atual = inicio;
    while(atual!=nullptr){
        if(atual->info == n){
            cout<<atual->text<<"\n";
            break;
        }
        atual = atual -> prox;
   }
   cout<<"\n";
 }

void menu(Arvore &arv, ListaE &lis, ListaDE &lisDE){
    ifstream sinopse;
    ifstream regras;
    string linha;
    string playerName;
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
        //jogar
        case 1:
            system("cls");
            int again;
            cout<<"digite o nome do jogador: \n";
            cin>>playerName;
            while(true){
                arv.jogar(arv.raiz, lis, playerName,"o desconhecido");
                while(true){
                    cout<<"Jogar novamente? 1-sim 2-não: ";
                    cin>>again;
                    if(again == 1 || again == 2){
                        break;
                    }
                    else{
                        cout<<"opção invalida\n";
                    }
                }
                
            }
            
            break;
        //regras
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
        //hitoria
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

void Arvore::jogar(nodeA *raiz, ListaDE &listade, ListaE &lista, string nome, string titulo){
    system("cls");
    lista.listar(raiz->info);
    int op;
    if(raiz->info == 200 || raiz->info == 18 ||raiz->info == 14 ||raiz->info == 9 ||raiz->info == 6 ||raiz->info == 300 ||raiz->info == 250 ||raiz->info == 220 ||raiz->info == 218 ||raiz->info == 216 ||raiz->info == 217 ||raiz->info == 215 ||raiz->info == 350 ||raiz->info == 320 ||raiz->info == 315){
        titulo = gerarTitulo(raiz-> info);
    }

    if(raiz == nullptr){
        cout<<"FIM\n\n"<<"E assim surge a lenda do "<<titulo;
        listade.inserirScorePlayer(listade, nome, titulo, 1, 0);
        return;
    }
    else if(raiz->info == 150||raiz->info == 75|| raiz->info == 27|| raiz->info == 22|| raiz->info == 19|| raiz->info == 17|| raiz->info == 15|| raiz->info == 13|| raiz->info == 11|| raiz->info == 9){
        cout<<"Game over";
        listade.inserirScorePlayer(listade, nome, titulo, 0, 1);
        return;
    }
    else{
        while(true){
            cout<<"faça sua escolha: ";
            cin>>op;
            if(op == 1 || op == 2){
                system("cls");
                break;
            }
            else{
                cout<<"opção invalida, tente outra: \n";
            }
        }
        if(op == 1){
            jogar(raiz->esq, listade, lista, nome, titulo);
        }
        else
            jogar(raiz->dir, listade, lista, nome, titulo);
        
    }
    return;
        
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    string titulo = "rei delas";
    string nome = "tatu";
    Arvore arv;
    ListaE lise;
    ListaDE players;
    lise.criarListaE();
    arv.criarArvore();
    //menu(arv, lise);
    arv.jogar(arv.raiz, players, lise, nome, titulo);
    system("cls");
}


//criar lista Dupla com informações do player, passar para jogo