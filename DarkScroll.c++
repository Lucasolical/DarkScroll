#include<iostream>

using namespace std;

struct node{
    int info;
    node *dir, *esq;
};

class Arvore{
  
    public:
    node *raiz;
    Arvore(){
        raiz = nullptr;
    }
    node *inserir(node *raiz,int n);

};

node *Arvore::inserir(node *raiz,int n){
    if(raiz == nullptr){
        raiz = new node();
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
    Arvore arv;
    arv.raiz = arv.inserir(arv.raiz,5);
    arv.raiz = arv.inserir(arv.raiz,15);
    arv.raiz = arv.inserir(arv.raiz,20);
    arv.raiz = arv.inserir(arv.raiz,4);
    arv.raiz = arv.inserir(arv.raiz,1);
    arv.raiz = arv.inserir(arv.raiz,30);
    arv.raiz = arv.inserir(arv.raiz,25);
}