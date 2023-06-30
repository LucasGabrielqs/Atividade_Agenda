#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;
void inserir_contato(string nome, string numero);
void mostrar_contato();
void procurar_contato(string valor);
void preencher_matriz();
void alterar_contato(string valor);
void inserir_matriz_txt();
void excluir_agenda();
void quantidade_contatos();
string agenda[100][2], nome, numero, linha,valor;
int cont=0,cont_linhas = 0;
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
                    cin >> valor;
                    procurar_contato(valor);
                break;
                case 4:
                    cout << "Digite o numero do contato" << endl;
                    cin >> valor;
                    procurar_contato(valor);
                break;
                case 5:
                    cout << "Digite o nome ou numero do contato que deseja alterar"<<endl;
                    cin >> valor;
                    alterar_contato(valor);
                break;
                case 6:
                    quantidade_contatos();
                break;
                case 7:
                    excluir_agenda();   
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
            arq << agenda [cont] [j] << endl;
            j++;
            agenda [cont][j] = numero;
            arq << agenda [cont][j] << endl;
        }
        cont ++;
    }
    arq.close();
}
void mostrar_contato(){
    preencher_matriz();
    for (int i=0;i<cont_linhas;i++){
        for (int j=0;j<2;j++){
            cout << agenda[i][j] << " ";
        }
        cout << endl;
    }
}

void procurar_contato(string valor){
    bool verificacao = true, verificacao2 = false;
    preencher_matriz();
    for (int i=0;i<100;i++){
        if ((valor == agenda[i][0]) || (valor == agenda[i][1])){
            for (int j=0;j<2;j++){
                cout << agenda[i][j] << " ";
            }
            verificacao2 = true;
        } else {
            verificacao = false;
        }
    }
    if ((verificacao == false) && (verificacao2 == false)){
        cout << "Não Achou" << endl;
    }
    cout << endl;
}
void alterar_contato(string valor){
    // variaveis de verificação;
    bool verificacao = true, verificacao2 = false;
    preencher_matriz();
    // for que vai percorrer todas as linhas da matriz
    for (int i=0;i<100;i++){
        // enquanto percorre vai fazer uma verificação se o valor digitado é igual a algum valor da matriz
        if ((valor == agenda[i][0]) || (valor == agenda[i][1])){
            // se for ele recebe true
            verificacao2 = true;
            cout << "Contato Encontrado" <<endl;
            // contato é exibido
            for (int j=0;j<2;j++){
                cout << agenda[i][j] << " ";
            }
            cout << endl;
            cout << "Digite o novo nome e numero do contato"<<endl;
            cin >> nome >> numero;
            // nesse for o valor de nome e numero é substituido pelos novos valores
            for (int j=0;j<2;j++){
                agenda[i][j] = nome;
                j++;
                agenda[i][j] = numero;
            }
        } else {
            verificacao = false;
        }
    }
    // Aqui é feita uma verificação para caso não seja encontrado nenhum contato, exiba a mensagem não achou
    if ((verificacao == false) && (verificacao2 == false)){
        cout << "Não Achou" << endl;
    }
    // aqui o arquivo TXT gerado na primeira parte é excluido
    remove("Agenda_Telefonica.txt");
    // aqui é gerado um novo arquivo com a matriz que tem os contatos atualizados
    inserir_matriz_txt();
}     
void preencher_matriz(){
    int cont3=1, x=0;
    cont_linhas = 0;
    arq.open("Agenda_Telefonica.txt", ios::in);
    while (!arq.eof()){
        getline(arq, linha);
        cont3++;
        if (cont3 % 2 == 0){
            agenda[x][0] = linha; 
        } else {
            agenda[x][1] = linha;
            x++;
            cont_linhas++;
        }
    } 
    arq.close();
}
void inserir_matriz_txt(){
    arq.open("Agenda_Telefonica.txt", ios::out | ios::app);
    for (int i=0;i<cont_linhas;i++){
        for (int j=0;j<2;j++){
            arq << agenda[i][j] << endl;
            j++;
            arq << agenda[i][j] << endl;
        }
    }
    arq.close();
}
void excluir_agenda(){
    remove("Agenda_Telefonica.txt");
}
void quantidade_contatos(){
    preencher_matriz();
    cout << "A quantidade de contatos cadastrados é: "<< cont_linhas << endl;
}