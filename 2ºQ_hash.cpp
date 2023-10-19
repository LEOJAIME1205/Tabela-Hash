#include <iostream>
#include <vector>
#include <list>

using std::make_pair;
using std::pair;
using std::vector;
using std::cout;
using std::list;
using std::endl;

const int primeiroNivel = 10;
const int segundoNivel = 10;

// func hash de nivel 1
int primeiroNivelHash(int key) {
    return key % primeiroNivel;
}

// func hash de nivel 2
int segundoNivelHash(int key) {
    return key % segundoNivel;
}

class TabelaHash {
private:
    vector < vector< list < pair< int, int>>> > tabela;

public:
    TabelaHash() {
        tabela.resize(primeiroNivel);
        for (int i = 0; i < primeiroNivel; i++) {
            tabela[i].resize(segundoNivel);
        }
    }

    // função de inserção
    void insert(int key, int value) {
        int primeiroIndex = primeiroNivelHash(key);
        int segundoIndex = segundoNivelHash(key);
        tabela[primeiroIndex][segundoIndex].push_back(make_pair(key, value));
    }

    // função de busca
    int find(int key) {
        int primeiroIndex = primeiroNivelHash(key);
        int segundoIndex = segundoNivelHash(key);

        for (const auto &item : tabela[primeiroIndex][segundoIndex]) {
            if (item.first == key) {
                return item.second;
            }
        }

        return -1;
    }
};

int main() {
    TabelaHash hashTable;

    // inserindo elementos
    hashTable.insert(1, 10);
    hashTable.insert(2, 20);
    hashTable.insert(3, 30);

    // recuperando elementos
    int valor1 = hashTable.find(1);
    int valor2 = hashTable.find(2);
    int valor4 = hashTable.find(4);

    if (valor1 != -1) {
        cout << "chave 1: " << valor1 << endl;
    } else {
        cout << "chave 1 não encontrada." << endl;
    }

    if (valor2 != -1) {
        cout << "chave 2: " << valor2 << endl;
    } else {
        cout << "chave 2 não encontrada." << endl;
    }

    if (valor4 != -1) {
        cout << "chave 4: " << valor4 << endl;
    } else {
        cout << "chave 4 não encontrada." << endl;
    }

    return 0;
}