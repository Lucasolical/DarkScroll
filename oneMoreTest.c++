#include<iostream>
#include<fstream>
#include<windows.h>
#include <limits>
#include<locale.h>
#include<vector>
using namespace std;
//usado (historia)
struct nodeL{
    int info;
    string text;
    nodeL *prox;
};
//usado mas talvez errado (usuario)
struct nodeLD{
    string player;
    string titulos;
    int nJogos, wins, loses;
    nodeLD *prox, *ant;
};
//usado(no de arvore)
struct nodeA{
    int info;
    string fases;
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
     void listarTudo();
};

class ListaDE{
     private:
     nodeLD *inicio;
   public:
     ListaDE(){
        inicio = nullptr;
     }
     int inserirScorePlayer(ListaDE &lista, string nome, string titulo, int win, int lose, int qtdJogos);
     void carregarEstatisticasDeArquivo();
};

class Arvore{
    public:
    nodeA *raiz;
    Arvore(){
        raiz = nullptr;
    }
    nodeA *inserirAr(nodeA *raiz,int n, string fase);
    void criarArvore();
    void jogar(nodeA *raiz, ListaDE &listade, ListaE &lista, string nome, string titulo);
    nodeA *EmOr(nodeA *raiz);
};

// Dentro da classe ListaDE
void ListaDE::carregarEstatisticasDeArquivo() {
    ifstream arquivo("estatisticas.txt");
    if (!arquivo.is_open()) {
        cerr << "Arquivo de estatísticas não encontrado ou erro ao abrir." << endl;
        return;
    }

    string linha;
    string nome, titulo;
    int wins, loses, nJogos;

    // Limpar a lista atual antes de carregar
    nodeLD* atual = inicio;
    while (atual != nullptr) {
        nodeLD* temp = atual;
        atual = atual->prox;
        delete temp;
    }
    inicio = nullptr;

    while (getline(arquivo, nome)) { // Lê o nome
        getline(arquivo, titulo); // Lê o título
        arquivo >> linha >> wins; // Lê "Wins: " e o número
        arquivo.ignore(); // Ignora o newline
        arquivo >> linha >> loses; // Lê "Loses: " e o número
        arquivo.ignore(); // Ignora o newline
        arquivo >> linha >> linha >> nJogos; // Lê "Total de jogos: " e o número
        arquivo.ignore(); // Ignora o newline, se houver um

        // Cria e insere o novo nó na lista
        nodeLD* novo = new nodeLD();
        novo->player = nome;
        novo->titulos = titulo;
        novo->wins = wins;
        novo->loses = loses;
        novo->nJogos = nJogos;
        novo->prox = nullptr;
        novo->ant = nullptr;

        if (inicio == nullptr) {
            inicio = novo;
        } else {
            nodeLD* ultimo = inicio;
            while (ultimo->prox != nullptr) {
                ultimo = ultimo->prox;
            }
            ultimo->prox = novo;
            novo->ant = ultimo;
        }
    }
    arquivo.close();
}

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
//cria arvore pré-definida
void Arvore::criarArvore(){
    
    raiz = inserirAr(raiz, 200, "inicio de tudo");
    raiz = inserirAr(raiz, 300, "a voz misteriosa");
    raiz = inserirAr(raiz, 350, "o inicio do fim");
    raiz = inserirAr(raiz, 250,"o purificador arcano");
    raiz = inserirAr(raiz, 260, "a visão da morte");
    raiz = inserirAr(raiz, 220, "a aceitação");
    raiz = inserirAr(raiz, 320,"O escolhido das trevas");
    raiz = inserirAr(raiz, 360, "corte do mal pela raiz");
    raiz = inserirAr(raiz, 218, "Aquele que um dia destruiu");
    raiz = inserirAr(raiz, 230, "Destruição do passado");
    raiz = inserirAr(raiz, 315, "a destruição dos reinos");//fim rota 2 final ruim
    raiz = inserirAr(raiz, 330, "lembranças de um amigo");//fim rota 2 final redenção
    raiz = inserirAr(raiz, 216,"um por todos e todos por um");
    raiz = inserirAr(raiz, 219,"a batalha perdida");
    raiz = inserirAr(raiz, 215, "a redenção do ceifador");//fim rota 2 final bom
    raiz = inserirAr(raiz, 217, "O Heroi desconhecido");//fim rota 2 final +- bom
    raiz = inserirAr(raiz, 100,"Um outro caminho");
    raiz = inserirAr(raiz, 150, "curiosidade matou o gato");
    raiz = inserirAr(raiz, 50, "nadador nato");
    raiz = inserirAr(raiz, 25,"Aceitando doces de estranhos");
    raiz = inserirAr(raiz, 75,"Quem avisa amigo é");
    raiz = inserirAr(raiz, 20, "escondendo a desconfiança");
    raiz = inserirAr(raiz, 27, "pega fujão");
    raiz = inserirAr(raiz, 18, "pacificamente");
    raiz = inserirAr(raiz, 22, "luta em vão");
    raiz = inserirAr(raiz, 16, "uma nova aliança");
    raiz = inserirAr(raiz, 19, "nada feito");
    raiz = inserirAr(raiz, 14, "missão suicida");
    raiz = inserirAr(raiz, 17, "na porta da execução");
    raiz = inserirAr(raiz, 12, "stealth total");
    raiz = inserirAr(raiz, 15, "imprudência na missão");
    raiz = inserirAr(raiz, 10, "o plano da comandante");
    raiz = inserirAr(raiz, 13, "nada de plano");
    raiz = inserirAr(raiz, 8, "magia proibida");
    raiz = inserirAr(raiz, 11, "nada a derruba");
    raiz = inserirAr(raiz, 6, "A força de talian");
    raiz = inserirAr(raiz, 9, "Senhor das feras");
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
    inserirHistL(28,31,20);
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

int ListaDE::inserirScorePlayer(ListaDE &lista, string nome, string titulo, int win, int lose, int qtdJogos){
    nodeLD *novo;
    nodeLD *atual;
    vector<string>linhas;
    string linha;

    // Primeiro, tenta encontrar o jogador na lista EM MEMÓRIA
    atual = inicio;
    while (atual != nullptr) {
        if (atual->player == nome) {
            // Jogador encontrado: atualiza as estatísticas na memória
            atual->wins += win;
            atual->loses += lose;
            atual->nJogos += qtdJogos;
            atual->titulos = titulo; // Atualiza o título se necessário

            // Agora, atualiza o arquivo
            ifstream seeplayers("estatisticas.txt");
            if (!seeplayers.is_open()) {
                cerr << "Erro ao abrir o arquivo para leitura!" << endl;
                return 0; // Ou outro código de erro apropriado
            }
            while (getline(seeplayers, linha)) {
                linhas.push_back(linha);
            }
            seeplayers.close();

            for (size_t i = 0; i < linhas.size(); i++) {
                if (linhas[i] == nome) {
                    if (i + 4 < linhas.size()) {
                        linhas[i+1] = titulo; // Atualiza o título
                        linhas[i+2] = "Wins: " + to_string(atual->wins);
                        linhas[i+3] = "Loses: " + to_string(atual->loses);
                        linhas[i+4] = "Total de jogos: " + to_string(atual->nJogos);
                    } else {
                        cerr << "Erro: formato de arquivo inesperado para o jogador " << nome << endl;
                        return 2;
                    }
                    break;
                }
            }

            ofstream saida("estatisticas.txt");
            if (!saida.is_open()) {
                cerr << "Erro ao abrir arquivo para escrita!" << endl;
                return 3;
            }
            for (const string& l : linhas) {
                saida << l << endl;
            }
            saida.close();
            cout << "Estatisticas atualizadas." << endl;
            return 0; // Jogador atualizado com sucesso
        }
        atual = atual->prox;
    }

    // Se o jogador NÃO foi encontrado na lista em memória, é um novo jogador
    novo = new nodeLD();
    novo->player = nome;
    novo->titulos = titulo;
    novo->wins = win;
    novo->loses = lose;
    novo->nJogos = qtdJogos;
    novo->prox = nullptr;
    novo->ant = nullptr; // Importante inicializar o 'ant'

    // Adiciona o novo nó ao final da lista duplamente encadeada EM MEMÓRIA
    if (inicio == nullptr) {
        inicio = novo;
    } else {
        atual = inicio;
        while (atual->prox != nullptr) {
            atual = atual->prox;
        }
        atual->prox = novo;
        novo->ant = atual;
    }

    // Adiciona o novo jogador ao final do arquivo
    ofstream players("estatisticas.txt", ios::app);
    if (!players.is_open()) {
        cerr << "Erro ao abrir o arquivo para escrita!" << endl;
        // Se falhar ao escrever, podemos querer remover o nó da lista em memória, dependendo da estratégia de tratamento de erro.
        // Por simplicidade, vamos apenas retornar 0 e manter na memória por enquanto.
        return 0;
    }
    players << nome << "\n";
    players << titulo << "\n";
    players << "Wins: " << win << "\n";
    players << "Loses: " << lose << "\n";
    players << "Total de jogos: " << qtdJogos << "\n";
    players.close();
    cout << "Novo jogador adicionado." << endl;
    return 1; // Novo jogador adicionado com sucesso
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

void ListaE::listarTudo(){
   nodeL *atual;
   atual = inicio;
   while(atual!=nullptr){
      cout<<atual->info<<"\n";
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
    int tec;
    bool continuar = true;
    lisDE.carregarEstatisticasDeArquivo();
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
                arv.jogar(arv.raiz, lisDE, lis, playerName,"o desconhecido");
                while(true){
                    cout<<"1-Jogar novamente: \n";
                    cout<<"2-informações tecnicas: \n";
                    cout<<"3-sair: \n";
                    cin>>again;
                    if(again == 1){
                        arv.jogar(arv.raiz, lisDE, lis, playerName,"o desconhecido");
                    }
                    else if(again == 3){
                        exit(1);
                    }
                    else if(again == 2){
                        while(true){
                            system("cls");
                            cout<<"1-Lista Simples-Origem-Arvore: \n";
                            cout<<"2-Listar a arvore: \n";
                            cout<<"3-Voltar \n";
                            cin>>tec;
                            if(tec == 1){
                                lis.listarTudo();
                                system("pause");
                                cin.clear();
                                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                            }
                            else if(tec == 2){
                                arv.EmOr(arv.raiz);
                                system("pause");
                                cin.clear();
                                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                            }
                            else if(tec == 3){
                                break;
                            }
                            else{
                                cout<<"opção invalida\n";
                                cin.clear();
                                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                            }
                        }
                    }
                    else{
                        cout<<"opção invalida\n";
                        cin.clear();
                        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
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

nodeA *Arvore::inserirAr(nodeA *raiz,int n, string fase){
    if(raiz == nullptr){
        raiz = new nodeA();
        if(raiz == nullptr)
            exit(1);
        raiz ->dir = nullptr;
        raiz ->esq = nullptr;
        raiz -> info = n;
        raiz->fases = fase;
        return raiz;
    }
    else{
        if(raiz -> info < n){
            raiz -> dir = inserirAr(raiz ->dir, n, fase);
            return raiz;
        }
        else if(raiz -> info > n){
            raiz -> esq = inserirAr(raiz->esq, n, fase);
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
    int op;
    //nós que geram titulos
    if(raiz->info == 200 || raiz->info == 18 ||raiz->info == 14 ||raiz->info == 9 ||raiz->info == 6 ||raiz->info == 300 ||raiz->info == 250 ||raiz->info == 220 ||raiz->info == 218 ||raiz->info == 216 ||raiz->info == 217 ||raiz->info == 215 ||raiz->info == 350 ||raiz->info == 320 ||raiz->info == 315){
        cout << "Salvando estatísticas de " << nome << "...\n";
        titulo = gerarTitulo(raiz-> info);  
    }
    lista.listar(raiz->info);

    if(raiz->info == 150||raiz->info == 75|| raiz->info == 27|| raiz->info == 22|| raiz->info == 19|| raiz->info == 17|| raiz->info == 15|| raiz->info == 13|| raiz->info == 11|| raiz->info == 9|| raiz->info == 260 || raiz->info == 230 || raiz->info == 219 || raiz->info == 360 || raiz->info == 330){
        cout<<"Game over";
        listade.inserirScorePlayer(listade, nome, titulo, 0, 1, 1);
        return;
    }
    else if(raiz->info == 6||raiz->info == 215|| raiz->info == 217|| raiz->info == 315){
        
        cout<<"FIM\n\n"<<"E assim surge a lenda do "<<titulo;
        listade.inserirScorePlayer(listade, nome, titulo, 1, 0, 1);
        return;
    }
    //nós que leval ao game over
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

nodeA *Arvore::EmOr(nodeA *raiz){
    if(raiz == nullptr)
        return raiz;
    else{
        EmOr(raiz->esq);
        cout<<raiz->fases<<"\n";
        EmOr(raiz->dir);
        return raiz;
    }
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    Arvore arv;
    ListaE lise;
    ListaDE players;
    lise.criarListaE();
    arv.criarArvore();
    menu(arv, lise, players);
    //arv.jogar(arv.raiz, players, lise, nome, titulo);

    return 1;
}


//criar lista Dupla com informações do player, passar para jogo