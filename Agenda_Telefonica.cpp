#include <iostream>
#include <fstream>
using namespace std;
void inserir_contato(string nome, string numero);
void mostrar_contato();
string agenda[100][2], nome, numero, linha;
int cont=0;
fstream arq;

int main() {
    int infinito = 1,opcao;
    
     while (infinito != 0)
     {
            cout << "|------------Menu------------|" << endl;
            cout << "1 - Adcionar Contato" << endl;
            cout << "-----------------------------" << endl;
            cout << "2 - Listar todos os contatos" << endl;
            cout << "-----------------------------" << endl;
            cout << "3 - Procurar por nome" << endl;
            cout << "-----------------------------" << endl;
            cout << "4 - Procurar por número" << endl;
            cout << "-----------------------------" << endl;
            cout << "5 - Alterar contato" << endl;
            cout << "-----------------------------" << endl;
            cout << "6 - Quantidade de contatos" << endl;
            cout << "-----------------------------" << endl;
            cout << "7 - Excluir agenda" << endl;
            cout << "-----------------------------" << endl;
            cout << "8 - Sair" << endl;
            cin >> opcao;
            switch (opcao)
            {
                case 1:
                    cout << "Digite o nome e o número do contato que deseja cadastrar" << endl;
                    cin >> nome;
                    cin >> numero;
                    inserir_contato(nome,numero);
                break;
                case 2:
                    cout << "|-----Lista de contatos-----|" << endl;
                    mostrar_contato();
                break;
                case 3:
                    cout << "Digite o nome do contato" << endl;
                    cin >> nome;
                break;
                case 4:
                    cout << "Digite o numero do contato" << endl;
                    cin >> numero;
                break;
                case 5:
                    cout << "Digite o nome do contato que deseja alterar" << endl;
                    cin >> nome;
                break;
                case 6:
                    cout << "A quantidade de contatos cadastrados é ";
                break;
                case 7:
                    cout << "Deseja realmente excluir a agenda?" << endl;
                break;
                case 8:
                    infinito = 0;
                break;
                default:
                    cout << "Não tem essa opção" << endl;
                break;
            }
     }
     
    return 0;
}

void inserir_contato(string nome, string numero){
    arq.open("Agenda_Telefonica.txt", ios::out | ios::app);
    for (int i=0;i<1;i++){
        for (int j = 0; j < 2;j++){
            agenda [cont][j] = nome;
            arq << agenda [cont] [j] << ": ";
            j++;
            agenda [cont][j] = numero;
            arq << agenda [cont][j] << endl;
        }
        cont ++;
    }
    arq.close();
}
void mostrar_contato(){
    arq.open("Agenda_Telefonica.txt", ios::in);
    while (!arq.eof()){
        getline(arq, linha);
        cout << linha << endl;
    }
    arq.close();
}

void procurar_nome(string nome){
    // separar a string por o espaço para assim preencher a matriz;
    arq.open("Agenda_Telefonica.txt", ios::in);
    while (!arq.eof()){
        getline(arq, linha);
    }
    arq.close();
}