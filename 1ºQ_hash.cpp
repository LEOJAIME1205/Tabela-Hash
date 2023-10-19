#include <list>
#include <iostream>
#include <vector>

using std::endl;
using std::vector;
using std::list;
using std::cout;

const int primeiroNivel = 10;
const int segundoNivel = 10;

// função hash para 1º nivel
int primeiroNivelHash(int key) {
    return key % primeiroNivel;
}

// função hash para 2º nivel
int segundoNivelHash(int key) {
    return key % segundoNivel;
}

class TabelaHash {

    vector < vector < list<int>>> tabela; 

public:
    TabelaHash() {
        tabela.resize(primeiroNivel);
        for (int i = 0; i < primeiroNivel; i++) {
            tabela[i].resize(segundoNivel);
        }
    }

    //método para inserir
    void insert(int key, int value) {
        int primeiroIndex = primeiroNivelHash(key);
        int segundoIndex = segundoNivelHash(key);
        tabela[primeiroIndex][segundoIndex].push_back(value);
    }

    //método para encontrar
    bool find(int key, int value) {
        int primeiroIndex = primeiroNivelHash(key);
        int segundoIndex = segundoNivelHash(key);
        for (int item : tabela[primeiroIndex][segundoIndex]) {
            if (item == value) {
                return true;
            }
        }
        return false;
    }

    //método para remover
    void remove(int key, int value) {
        int primeiroIndex = primeiroNivelHash(key);
        int segundoIndex = segundoNivelHash(key);
        tabela[primeiroIndex][segundoIndex].remove(value);
    }
};

int main() {
    TabelaHash hash;

    // inserindo elementos
    hash.insert(1, 10);
    hash.insert(2, 20);
    hash.insert(3, 30);

    // verificando se um elemento esta na tabela
    cout << "encontrou 2: " << hash.find(2, 20) << endl;

    // removendo um elemento da tabela
    hash.remove(2, 20);
    cout << "encontrou 2 depois da remoção: " << hash.find(2, 20) << endl;

    return 0;
}