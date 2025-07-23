#include<iostream>
#include<fstream>
#include<windows.h>
#include<limits>
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
     int inserirScorePlayer(string nome, string titulo, int win, int lose, int qtdJogos);
     void carregarEstatisticasDeArquivo();
     void listarDE();
     void encontrarPlayer();
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
//carregar arquivo score dentro da lista dupla;
void ListaDE::carregarEstatisticasDeArquivo() {
    ifstream arquivo("estatisticas.txt");
    if (!arquivo.is_open()) {
        cerr << "Arquivo de estatísticas não encontrado ou erro ao abrir." << endl;
        return;
    }
    string nome, titulo;
    string linha;
    int wins, loses, nJogos;
    // Limpar a lista atual (para diferenciar a lista de inicio para a de final de jogo)
    nodeLD* atual = inicio;
    while (atual != nullptr) {
        nodeLD* temp = atual;
        atual = atual->prox;
        delete temp;
    }
    inicio = nullptr;
    //while para caminhar pelo arquivo
    while (getline(arquivo, nome)) {
        //!getline serve para caso ele não consiga ler ele quebra o loop
        if (!getline(arquivo, titulo)) break;
        if (!getline(arquivo, linha)) break;
        // Pega a substring que vem depois dos dois pontos e converte para inteiro
        wins = stoi(linha.substr(linha.find(":") + 1));
        if (!getline(arquivo, linha)) break;
        loses = stoi(linha.substr(linha.find(":") + 1));
        if (!getline(arquivo, linha)) break;
        nJogos = stoi(linha.substr(linha.find(":") + 1));

        // Criar novo nó
        nodeLD* novo = new nodeLD();
        novo->player = nome;
        novo->titulos = titulo;
        novo->wins = wins;
        novo->loses = loses;
        novo->nJogos = nJogos;
        novo->prox = nullptr;
        novo->ant = nullptr;

        //primeiro nó
        if (inicio == nullptr) {
            inicio = novo;
        } 
        else if (novo->wins > inicio->wins) {
            // Inserir no início
            novo->prox = inicio;
            inicio->ant = novo;
            inicio = novo;
        } 
        else {
            nodeLD* atual = inicio;
            while (atual->prox != nullptr && atual->prox->wins >= novo->wins) {
                atual = atual->prox;
            }
            // Inserir após 'atual'
            novo->prox = atual->prox;
            novo->ant = atual;
            if (atual->prox != nullptr) {
                atual->prox->ant = novo;
            }
            atual->prox = novo;
        }
    }

    arquivo.close();
}
//gera um titulo se baseando no info do nó que o jogador esta (chamado em Jogar)
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
//cria lista com os trechos da historia
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
//procura player na lista dupla depois de usar carregarEstatisticasDeArquivo e insere novo ou atualiza a depender do caso
int ListaDE::inserirScorePlayer(string nome, string titulo, int win, int lose, int qtdJogos){
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
                atual->nJogos = atual->loses +atual->wins;
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

        // Se o jogador não foi encontrado na lista, cria um novo jogador
        novo = new nodeLD();
        novo->player = nome;
        novo->titulos = titulo;
        novo->wins = win;
        novo->loses = lose;
        novo->nJogos = qtdJogos;
        novo->prox = nullptr;
        novo->ant = nullptr;

        // Adiciona o novo nó ao final da lista duplamente encadeada
        if (inicio == nullptr) {
            inicio = novo;
        } 
        else {
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
            return 0;
        }
        players << nome << "\n";
        players << titulo << "\n";
        players << "Wins: " << win << "\n";
        players << "Loses: " << lose << "\n";
        players << "Total de jogos: " << qtdJogos << "\n";
        players.close();
        cout << "Novo jogador adicionado." << endl;
        return 1;
}
//mostra todos os saves
void ListaDE::listarDE(){
   nodeLD *atual;
   atual = inicio;
   while(atual!=nullptr){
      cout<<"Nome: "<<atual->player<<"\n"; 
      cout<<"Titulo: "<<atual->titulos<<"\n";
      cout<<"Vitorias: "<<atual->wins<<"\n";
      cout<<"Derrotas: "<<atual->loses<<"\n";
      cout<<"Jogos Totais: "<<atual->nJogos<<"\n\n";
      atual = atual -> prox;
   }
   cout<<"\n";
}
//buscar players a partir da estatistica escolhida (nome, wins, loses, jogos totais)
void ListaDE::encontrarPlayer(){
    nodeLD *atual;
    string nNome;
    int nWins, nLoses, nQtdJogos;
    atual = inicio;
    int status = 0;
    int n;
    while(true){
        while(true){
            cout<<"Você deseja buscar como?\n\n";
            cout<<"1 - por nome\n";
            cout<<"2 - por wins\n";
            cout<<"3 - por loses\n";
            cout<<"4 - por jogos totais\n\n";
            cout<<"escolha: ";
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cin>>n;
            system("cls");
            if(n == 1 || n == 2 || n == 3 || n == 4){
                break;
            }
            else{
                cout<<"numero invalido, digite outro \n";
                cin.clear();
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        switch(n){
            case 1:
                cin.clear();
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                cout<<"digite o nome do player: ";
                cin>>nNome;
                cout<<"\n";
                while(atual!=nullptr){
                    if(atual->player == nNome){
                        cout<<"Nome: "<<atual->player<<"\n";
                        cout<<"Titulo: "<<atual->titulos<<"\n";
                        cout<<"Vitorias: "<<atual->wins<<"\n";
                        cout<<"Derrotas: "<<atual->loses<<"\n";
                        cout<<"Total de jogos: "<<atual->nJogos<<"\n";
                        status = 1;
                    }
                    atual = atual -> prox;
                }
                cout<<"\n";
                if(status == 0)
                    cout<<"essa estatistica não existe nos saves\n\n";
                cin.clear();
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                system("pause");
                break;
            case 2:
                cin.clear();
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                cout<<"digite o n° de vitorias: ";
                cin>>nWins;
                cout<<"\n";
                while(atual!=nullptr){
                    if(atual->wins == nWins){
                        cout<<"Nome: "<<atual->player<<"\n";
                        cout<<"Titulo: "<<atual->titulos<<"\n";
                        cout<<"Vitorias: "<<atual->wins<<"\n";
                        cout<<"Derrotas: "<<atual->loses<<"\n";
                        cout<<"Total de jogos: "<<atual->nJogos<<"\n";
                        status = 1;
                    }
                    atual = atual -> prox;
                }
                cout<<"\n";
                if(status == 0)
                    cout<<"essa estatistica não existe nos saves\n\n";
                cin.clear();
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                system("pause");
                break;
            case 3:
                cin.clear();
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                cout<<"digite o n° de loses: ";
                cin>>nLoses;
                cout<<"\n";
                while(atual!=nullptr){
                    if(atual->loses == nLoses){
                        cout<<"Nome: "<<atual->player<<"\n";
                        cout<<"Titulo: "<<atual->titulos<<"\n";
                        cout<<"Vitorias: "<<atual->wins<<"\n";
                        cout<<"Derrotas: "<<atual->loses<<"\n";
                        cout<<"Total de jogos: "<<atual->nJogos<<"\n";
                        status = 1;
                    }
                    atual = atual -> prox;
                }
                cout<<"\n";
                if(status == 0)
                    cout<<"essa estatistica não existe nos saves\n\n";
                cin.clear();
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                system("pause");
                break;
            case 4:
                cin.clear();
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                cout<<"digite o n° de jogos: ";
                cin>>nQtdJogos;
                cout<<"\n";
                while(atual!=nullptr){
                    if(atual->nJogos == nQtdJogos){
                        cout<<"Nome: "<<atual->player<<"\n";
                        cout<<"Titulo: "<<atual->titulos<<"\n";
                        cout<<"Vitorias: "<<atual->wins<<"\n";
                        cout<<"Derrotas: "<<atual->loses<<"\n";
                        cout<<"Total de jogos: "<<atual->nJogos<<"\n";
                        status = 1;
                    }
                    atual = atual -> prox;
                }
                cout<<"\n";
                if(status == 0)
                    cout<<"essa estatistica não existe nos saves\n\n";
                cin.clear();
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                system("pause");
                break;
        }
        if(status == 1)
            break;
    }
}
//leitura que é chamada em cada nó da arvore para mostrar o conteudo com base no n (n seria o raiz->info que seria passado como parametro )
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
//printa a lista toda, mostrando seus os infos de cada nó (não sabia o que era pra printar exatamente, então coloquei o info)
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
        cout<<"3 historia"<<"\n";
        cout<<"4 Score do jogo"<<"\n";
        cout<<"5 sair"<<"\n\n";
        cout << "escolha: ";
        while(true){
            cin >> n;
            if(n == 1 || n == 2 || n ==3 || n == 4 || n == 5){
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
                    system("cls");
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
                            cout<<"3-buscar jogadores: \n";
                            cout<<"4-Voltar \n";
                            cin>>tec;
                            system("cls");
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
                                lisDE.encontrarPlayer();
                            }
                            else if(tec == 4){
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
        case 4:
                system("cls");
                cout<<"Score do Jogo: \n\n";
                lisDE.carregarEstatisticasDeArquivo();
                lisDE.listarDE();
                system("pause");
                break;
        case 5:
                system("cls");
                exit(1);
        default:
            break;
        }
    }
}
//Cria a arvore; inicialmente coloquei o string fase para identificar se os nós estavamna ordem certa. Depois achei bom deixar, para a hora de printar a arvore toda, so mostrar o nome da fase em vez do texto todo (ia ficar muito poluido o terminal)
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
//cria a lista simples da historia, passando linha de inicio do trecho, final e o n para identificar na arvore
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
    //caso o jogador chegue em algum desses infos significa game over
    if(raiz->info == 150||raiz->info == 75|| raiz->info == 27|| raiz->info == 22|| raiz->info == 19|| raiz->info == 17|| raiz->info == 15|| raiz->info == 13|| raiz->info == 11|| raiz->info == 9|| raiz->info == 260 || raiz->info == 230 || raiz->info == 219 || raiz->info == 360 || raiz->info == 330){
        cout<<"Game over\n\n";
        system("pause");
        system("cls");
        listade.inserirScorePlayer(nome, titulo, 0, 1, 1);
        return;
    }
    //nós da vitoria 
    else if(raiz->info == 6||raiz->info == 215|| raiz->info == 217|| raiz->info == 315){
        
        cout<<"FIM\n\n"<<"E assim surge a lenda do "<<titulo;
        cout<<"\n";
        system("pause");
        system("cls");
        listade.inserirScorePlayer(nome, titulo, 1, 0, 1);
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
        //escolha de caminho
        if(op == 1){
            jogar(raiz->esq, listade, lista, nome, titulo);
        }
        else
            jogar(raiz->dir, listade, lista, nome, titulo);
        
    }
    return;    
}
//printa a arvore em ordem de nome de fase(caso queira printar os infos, em vez de fases, so trocar em cout que funciona, escolhi essa forma para printar algo diferente da lista)
nodeA *Arvore::EmOr(nodeA *raiz){
    if(raiz == nullptr)
        return raiz;
    else{
        EmOr(raiz->esq);
        cout<<raiz->fases<<"\n\n";
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
    return 1;
}
