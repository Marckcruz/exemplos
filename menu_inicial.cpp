#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct Cliente {
    string CPF;
    string Nome;
    string DtNascimento;
    string CNH;

    Cliente(string CPF, string Nome, string DtNascimento, string CNH) {
        this->CPF = CPF;
        this->Nome = Nome;
        this->DtNascimento = DtNascimento;
        this->CNH = CNH;
    }
    
};

struct Veiculo {
    string Renavam;
    string Placa_do_Veiculo;
    string Data_Hora_Retirada;
    string Data_Hora_Entrega;
    string Loja_Retirada;

    Veiculo(string Renavam, string Placa_do_Veiculo, string Data_Hora_Retirada, string Data_Hora_Entrega, string Loja_Retirada) {
        this->Renavam = Renavam;
        this->Placa_do_Veiculo = Placa_do_Veiculo;
        this->Data_Hora_Retirada = Data_Hora_Retirada;
        this->Data_Hora_Entrega = Data_Hora_Entrega;
        this->Loja_Retirada = Loja_Retirada;
    }
};

struct Locacao {
    string CNH;
    string placaVeiculo;
    string dataRetirada;
    bool retiradaRealizada;
    
};

struct Ocorrencia {
    string CPF;
    string placaVeiculo;
    string descricao;
    string data;
    string apolice;
    
};

vector<Cliente> clientes;
vector<Veiculo> veiculos;
vector<Locacao> locacoes;
vector<Ocorrencia> ocorrencias;



bool verificarCNH(string CNH) {
    for (const Cliente& cliente : clientes) {
        if (cliente.CNH == CNH) {
            return true;
        }
    }
    return false;
}

bool verificarCPF(string CPF) {
    for (const Cliente& cliente : clientes) {
        if (cliente.CPF == CPF) {
            return true;
        }
    }
    return false;
}

bool verificarPlaca(string Placa_do_Veiculo) {
    for (const Veiculo& veiculo : veiculos) {
        if (veiculo.Placa_do_Veiculo == Placa_do_Veiculo) {
            return true;
        }
    }
    return false;
}


// 1 - GESTÃO DE CLIENTES
// Funções para gestão de clientes
void incluirCliente() {

    string CPF, Nome, DtNascimento, CNH;

    cout << "   GESTÃO DE CLIENTE   " << endl;
    cout << "_______________________" << endl;
    cout << " " << endl;

    cout << "Incluir Cliente:" << endl;
    cout << " " << endl;
    
    cout << "Digite o CPF do cliente: ";
    cin >> CPF;
    cout << "Digite o nome do cliente: ";
    cin.ignore();
    getline(cin, Nome);
    cout << "Digite a data de nascimento do cliente (dd/mm/yyyy): ";
    cin >> DtNascimento;
    cout << "Digite o numero da CNH do cliente: ";
    cin >> CNH;

    Cliente cliente(CPF, Nome, DtNascimento, CNH);
    clientes.push_back(cliente);

    cout << " " << endl;
    
    cout << "Cliente adicionado com sucesso!" << endl;
    cout << " " << endl;
     
}

void excluirCliente() {
    
    string CPF;

    cout << "   GESTÃO DE CLIENTE   " << endl;
    cout << "_______________________" << endl;
    cout << " " << endl;

    cout << "Excluir Cliente:" << endl;
    cout << " " << endl;

    cout << "Digite o CPF do cliente a ser excluído: ";
    cin >> CPF;
    cout << " " << endl;

    for (int i = 0; i < clientes.size(); i++) {
        if (clientes[i].CPF == CPF) {
            clientes.erase(clientes.begin() + i);
            cout << "Cliente removido com sucesso!" << endl;
            cout << " " << endl;

            return;
        }
    }

    cout << "Cliente não encontrado." << endl;
    cout << " " << endl;
        
}

void alterarCliente() {
    
    string CPF;

    cout << "   GESTÃO DE CLIENTE   " << endl;
    cout << "_______________________" << endl;
    cout << " " << endl;

    cout << "Alterar Cliente:" << endl;
    cout << " " << endl;

    cout << "Digite o CPF do cliente a ser alterado: ";
    cin >> CPF;
    cout << " " << endl;

    for (int i = 0; i < clientes.size(); i++) {
        if (clientes[i].CPF == CPF) {
            
            cout << "Dados do cliente:" << endl;
            cout << " " << endl;

            cout << "CPF: " << clientes[i].CPF << endl;
            cout << "Nome: " << clientes[i].Nome << endl;
            cout << "Data de Nascimento: " << clientes[i].DtNascimento << endl;
            cout << "Numero CNH: " << clientes[i].CNH << endl;
            cout << " " << endl;

            cout << "Deseja alterar o Nome? (S/N): ";
            char opcao;
            cin >> opcao;
            if (opcao == 'S' || opcao == 's') {
                cout << "Digite o novo nome: ";
                cin.ignore();
                getline(cin, clientes[i].Nome);
            }

            cout << "Deseja alterar a Data de Nascimento? (S/N): ";
            cin >> opcao;
            if (opcao == 'S' || opcao == 's') {
                cout << "Digite a nova Data de Nascimento: ";
                cin >> clientes[i].DtNascimento;
            }

            cout << "Deseja alterar o número da CNH? (S/N): ";
            cin >> opcao;
            if (opcao == 'S' || opcao == 's') {
                cout << "Digite o novo CNH: ";
                cin >> clientes[i].CNH;
            }

            cout << "Cliente alterado com sucesso!" << endl;
            cout << " " << endl;
            
            return;
        }
    }

    cout << "Cliente não encontrado." << endl;
    cout << " " << endl;
    
}

void listarClientes() {
    
    cout << "   GESTÃO DE CLIENTE   " << endl;
    cout << "_______________________" << endl;
    cout << " " << endl;

    cout << "Lista de Clientes:" << endl;
    cout << " " << endl;

    for (const Cliente& cliente : clientes) {
        cout << "CPF: " << cliente.CPF << endl; 
        cout << ". Nome: " << cliente.Nome << endl; 
        cout << ". Data de Nascimento: " << cliente.DtNascimento << endl; 
        cout << ". CNH: " << cliente.CNH << endl;
        cout << " " << endl;
    }
    
    
}

void localizarCliente() {
    
    string CPF;

    cout << "   GESTÃO DE CLIENTE   " << endl;
    cout << "_______________________" << endl;
    cout << " " << endl;
    
    cout << "Localizar Cliente:" << endl;
    cout << " " << endl;

    cout << "Digite o CPF do cliente a ser localizado: ";
    cin >> CPF;
    cout << " " << endl;

    for (const Cliente& cliente : clientes) {
        if (cliente.CPF == CPF) {
            cout << "Dados do cliente encontrado:" << endl;
            cout << " " << endl;

            cout << "CPF: " << cliente.CPF << endl; 
            cout << ". Nome: " << cliente.Nome << endl; 
            cout << ". Data de Nascimento: " << cliente.DtNascimento << endl; 
            cout << ". CNH: " << cliente.CNH << endl;
            cout << " " << endl;
            
            return;
        }
    }

    cout << "Cliente não encontrado." << endl;
    cout << " " << endl;
        
}


// 2 - GESTÃO DE VEICULOS
// Funções para gestão de veículos
void incluirVeiculo() {
    string Renavam, Placa_do_Veiculo, Data_Hora_Retirada, Data_Hora_Entrega, Loja_Retirada;

    cout << "   GESTÃO DE VEÍCULO   " << endl;
    cout << "_______________________" << endl;
    cout << " " << endl;

    cout << "Incluir Veiculo:" << endl;
    cout << " " << endl;
    
    cout << "Digite o Renavam do veiculo: ";
    cin >> Renavam;
    cout << "Digite a Placa do veiculo: ";
    cin.ignore();
    getline(cin, Placa_do_Veiculo);
    cout << "Digite a Data e Hora para retirada do veiculo: ";
    cin >> Data_Hora_Retirada;
    cout << "Digite a Data e Hora para entrega do veiculo: ";
    cin >> Data_Hora_Entrega;
    cout << "Digite Loja de Retirada do veiculo: ";
    cin >> Loja_Retirada;

    Veiculo veiculo(Renavam, Placa_do_Veiculo, Data_Hora_Retirada, Data_Hora_Entrega, Loja_Retirada);
    veiculos.push_back(veiculo);

    cout << "Veiculo adicionado com sucesso!" << endl;
    cout << " " << endl;
}

void excluirVeiculo() {
    string Placa_do_Veiculo;

    cout << "   GESTÃO DE VEÍCULO   " << endl;
    cout << "_______________________" << endl;
    cout << " " << endl;

    cout << "Excluir Veiculo:" << endl;
    cout << " " << endl;

    cout << "Digite a Placa do veiculo a ser excluído: ";
    cin >> Placa_do_Veiculo;
    cout << " " << endl;

    for (int i = 0; i < veiculos.size(); i++) {
        if (veiculos[i].Placa_do_Veiculo == Placa_do_Veiculo) {
            veiculos.erase(veiculos.begin() + i);
            cout << "Veiculo removido com sucesso!" << endl;
            cout << " " << endl;

            return;
        }
    }

    cout << "Veiculo não encontrado." << endl;
    cout << " " << endl;

}

void alterarVeiculo() {
    string Placa_do_Veiculo;

    cout << "   GESTÃO DE VEÍCULO   " << endl;
    cout << "_______________________" << endl;
    cout << " " << endl;
    
    cout << "Alterar Veiculo:" << endl;
    cout << " " << endl;

    cout << "Digite a Placa do veiculo a ser alterado: ";
    cin >> Placa_do_Veiculo;
    cout << " " << endl;

    for (int i = 0; i < veiculos.size(); i++) {
        if (veiculos[i].Placa_do_Veiculo == Placa_do_Veiculo) {
            
            cout << "Dados do veiculo:" << endl;
            cout << " " << endl;

            cout << "Renavam: " << veiculos[i].Renavam << endl;
            cout << "Placa do Veiculo: " << veiculos[i].Placa_do_Veiculo << endl;
            cout << "Data e Hora da Retirada: " << veiculos[i].Data_Hora_Retirada << endl;
            cout << "Data e Hora da Entrega: " << veiculos[i].Data_Hora_Entrega<< endl;
            cout << "Loja de Retirada: " << veiculos[i].Loja_Retirada << endl;
            cout << " " << endl;

            cout << "Deseja alterar o Renavam do Veiculo? (S/N): ";
            char opcao;
            cin >> opcao;
            if (opcao == 'S' || opcao == 's') {
                cout << "Digite o novo Renavam: ";
                cin.ignore();
                getline(cin, veiculos[i].Renavam);
            }

            cout << "Deseja alterar data e hora da retirada do veículo ? (S/N): ";
            cin >> opcao;
            if (opcao == 'S' || opcao == 's') {
                cout << "Digite a nova data e hora da retirada: ";
                cin >> veiculos[i].Data_Hora_Retirada;
            }

            cout << "Deseja alterar a data e hora da entrega do veículo? (S/N): ";
            cin >> opcao;
            if (opcao == 'S' || opcao == 's') {
                cout << "Digite o nova data e hora da entrega: ";
                cin >> veiculos[i].Data_Hora_Entrega;
            }

            cout << "Deseja alterar o local da retirada do veículo? (S/N): ";
            cin >> opcao;
            if (opcao == 'S' || opcao == 's') {
                cout << "Digite o novo local da retira: ";
                cin >> veiculos[i].Data_Hora_Entrega;
            }

            cout << " " << endl;
            cout << "Veiculo alterado com sucesso!" << endl;
            cout << " " << endl;
            
            return;
        }
    }

    cout << "Veiculo não encontrado." << endl;
    cout << " " << endl;

}

void listarVeiculos() {

    cout << "   GESTÃO DE VEÍCULO   " << endl;
    cout << "_______________________" << endl;
    cout << " " << endl;

    cout << "Lista de veiculos:" << endl;
    cout << " " << endl;

    for (const Veiculo& veiculo : veiculos) {
        
        cout << "Renavam: " << veiculo.Renavam << endl;
        cout << "Placa do Veiculo: " << veiculo.Placa_do_Veiculo << endl;
        cout << "Data e Hora da Retirada: " << veiculo.Data_Hora_Retirada << endl;
        cout << "Data e Hora da Entrega: " << veiculo.Data_Hora_Entrega<< endl;
        cout << "Loja de Retirada: " << veiculo.Loja_Retirada << endl;
        cout << " " << endl;
    }
}

void localizarVeiculo() {
    string Placa_do_Veiculo;

    cout << "   GESTÃO DE VEÍCULO   " << endl;
    cout << "_______________________" << endl;
    cout << " " << endl;

    cout << "Localizar Veiculo:" << endl;
    cout << " " << endl;

    cout << "Digite a Placa do veiculo a ser localizado: ";
    cin >> Placa_do_Veiculo;
    cout << " " << endl;

    for (const Veiculo& veiculo : veiculos) {
        if (veiculo.Placa_do_Veiculo == Placa_do_Veiculo) {
            cout << "Dados do veiculo encontrado:" << endl;
            cout << " " << endl;

            cout << "Renavam: " << veiculo.Renavam << endl;
            cout << "Placa do Veiculo: " << veiculo.Placa_do_Veiculo << endl;
            cout << "Data e Hora da Retirada: " << veiculo.Data_Hora_Retirada << endl;
            cout << "Data e Hora da Entrega: " << veiculo.Data_Hora_Entrega<< endl;
            cout << "Loja de Retirada: " << veiculo.Loja_Retirada << endl;
            cout << " " << endl;
            
            return;
        }
    }

    cout << "Veiculo não encontrado." << endl;
    cout << " " << endl;

}


// 3 - GESTÃO DE LOCAÇÕES
// Funções para gestão de locações
void incluirLocacao() {
    
    string CNH, placaVeiculo, dataRetirada;
    bool retiradaRealizada;

    cout << "   Empresa de locação de veículos LocaFINA S/A." << endl;
    cout << "___________________________________________________" << endl;
    cout << " " << endl;

    cout << "Incluir Locação de Veículo" << endl;
    cout << " " << endl;

    cout << "Informe o CNH do cliente: ";
    cin >> CNH;
    cout << " " << endl;
    

    if (!verificarCNH(CNH)) {
        cout << "Erro: CNH não cadastrado." << endl;
        cout << " " << endl;
        cout << " " << endl;
        cout << " " << endl;
        cout << " " << endl;
        return;
    }

    cout << "Informe a Placa do veículo: ";
    cin >> placaVeiculo;

    if (!verificarPlaca(placaVeiculo)) {
        cout << "Erro: Placa de veículo não cadastrada." << endl;
        return;
    }

    cout << "Informe a Data real da Retirada: ";
    cin >> dataRetirada;

    cout << "A Retirada já aconteceu? (1 - Sim, 0 - Não): ";
    cin >> retiradaRealizada;

    Locacao locacao;
    locacao.CNH = CNH;
    locacao.placaVeiculo = placaVeiculo;
    locacao.dataRetirada = dataRetirada;
    locacao.retiradaRealizada = retiradaRealizada;

    locacoes.push_back(locacao);

    cout << "Locação registrada com sucesso." << endl;

}

void excluirLocacao() {
    
    string placaVeiculo, CNH;

    cout << "   Empresa de locação de veículos LocaFINA S/A." << endl;
    cout << "___________________________________________________" << endl;
    cout << " " << endl;

    cout << "Excluir Locação de Veículo" << endl;
    cout << " " << endl;

    cout << "Informe a Placa do veículo: ";
    cin >> placaVeiculo;

    cout << "Lista de locações para o veículo " << placaVeiculo << ":" << endl;

    for (size_t i = 0; i < locacoes.size(); i++) {
        if (locacoes[i].placaVeiculo == placaVeiculo) {
            cout << i + 1 << ". CNH: " << locacoes[i].CNH << ", Data Retirada: " << locacoes[i].dataRetirada << endl;
        }
    }

    cout << "Informe o CNH do cliente que não realizará a locação: ";
    cin >> CNH;

    for (size_t i = 0; i < locacoes.size(); i++) {
        if (locacoes[i].placaVeiculo == placaVeiculo && locacoes[i].CNH == CNH) {
            locacoes.erase(locacoes.begin() + i);
            cout << "Locação excluída com sucesso." << endl;
            return;
        }
    }

    cout << "Erro: Locação não encontrada." << endl;
        
}

void alterarLocacao() {
    
    string placaVeiculo, CNH, dataEntrega;

    cout << "   Empresa de locação de veículos LocaFINA S/A." << endl;
    cout << "___________________________________________________" << endl;
    cout << " " << endl;

    cout << "Alterar Locação de Veículo" << endl;
    cout << " " << endl;

    cout << "Informe a Placa do veículo: ";
    cin >> placaVeiculo;

    cout << "Lista de passageiros com locações para o veículo " << placaVeiculo << ":" << endl;

    for (size_t i = 0; i < locacoes.size(); i++) {
        if (locacoes[i].placaVeiculo == placaVeiculo) {
            cout << i + 1 << ". CNH: " << locacoes[i].CNH << ", Data Retirada: " << locacoes[i].dataRetirada << endl;
        }
    }

    cout << "Informe o CNH do cliente: ";
    cin >> CNH;

    for (size_t i = 0; i < locacoes.size(); i++) {
        if (locacoes[i].placaVeiculo == placaVeiculo && locacoes[i].CNH == CNH) {
            cout << "Informe a Data/Hora real de entrega: ";
            cin >> dataEntrega;
            locacoes[i].dataRetirada = dataEntrega;
            cout << "Locação alterada com sucesso." << endl;
            return;
        }
    }

    cout << "Erro: Locação não encontrada." << endl;


}

void listarLocacoes() {
    
    cout << "Lista de todas as locações:" << endl;

    cout << "   Empresa de locação de veículos LocaFINA S/A." << endl;
    cout << "___________________________________________________" << endl;
    cout << " " << endl;

    cout << "Listar Locação de Veículo" << endl;
    cout << " " << endl;

    for (const Locacao& locacao : locacoes) {
        cout << "CNH: " << locacao.CNH << ", Placa do Veículo: " << locacao.placaVeiculo
             << ", Data Retirada: " << locacao.dataRetirada;
        if (locacao.retiradaRealizada) {
            cout << " (Retirada realizada)";
        } else {
            cout << " (Retirada não realizada)";
        }
        cout << endl;
    }

}


// 4 - GESTÃO DE OCORRÊNCIAS
// Funções para gestão de ocorrências
void incluirOcorrencia() {
    
    // Implemente a exclusão de ocorrências aqui
   

}

void excluirOcorrencia() {
    // Implemente a exclusão de ocorrências aqui
}

void alterarOcorrencia() {
    // Implemente a alteração de ocorrências aqui
}

void listarOcorrenciasPorCliente() {
    // Implemente a listagem de ocorrências por cliente aqui
}

void listarOcorrenciasPorVeiculo() {
    // Implemente a listagem de ocorrências por veículo aqui
}

int main() {
    while (true) {

        cout << "   Empresa de locação de veículos LocaFINA S/A." << endl;
        cout << "___________________________________________________" << endl;
        cout << " " << endl;

        cout << "Menu Inicial:" << endl;
        cout << " " << endl;
        cout << "1. Gestão de Clientes." << endl;
        cout << "2. Gestão de Veículos." << endl;
        cout << "3. Gestão de Locações." << endl;
        cout << "4. Gestão de Ocorrências." << endl;
        cout << "0. Sair do Programa." << endl;

        cout << " " << endl;
        cout << "Escolha uma opção: ";

        int opcao;
        cin >> opcao;

        system ("clear");

        switch (opcao) {
            case 1:
                // Menu de gestão de clientes
                while (true) {
                    
                    cout << "   Empresa de locação de veículos LocaFINA S/A." << endl;
                    cout << "___________________________________________________" << endl;
                    cout << " " << endl;

                    cout << "Menu de Gestão de Clientes:" << endl;
                    cout << " " << endl;
                    cout << "1. Incluir." << endl;
                    cout << "2. Excluir." << endl;
                    cout << "3. Alterar." << endl;
                    cout << "4. Listar." << endl;
                    cout << "5. Localizar." << endl;
                    cout << "0. Voltar para o Menu Inicial." << endl;

                    cout << " " << endl;
                    cout << "Escolha uma opção: ";

                    int opcao_cliente;
                    cin >> opcao_cliente;

                    system ("clear");

                    switch (opcao_cliente) {
                        case 1:
                            incluirCliente();
                            break;
                        case 2:
                            excluirCliente();
                            break;
                        case 3:
                            alterarCliente();
                            break;
                        case 4:
                            listarClientes();
                            break;
                        case 5:
                            localizarCliente();
                            break;
                        case 0:
                            // Voltar para o Menu Inicial
                            break;
                        default:
                            cout << "Opção inválida." << endl;
                            break;
                    }

                    if (opcao_cliente == 0) {
                        break;
                    }
                }
                break;
            case 2:
                // Menu de gestão de veículos
                while (true) {

                    cout << "   Empresa de locação de veículos LocaFINA S/A." << endl;
                    cout << "___________________________________________________" << endl;
                    cout << " " << endl;


                    cout << "Menu de Gestão de Veículos:" << endl;
                    cout << " " << endl;

                    cout << "1. Incluir." << endl;
                    cout << "2. Excluir." << endl;
                    cout << "3. Alterar." << endl;
                    cout << "4. Listar." << endl;
                    cout << "5. Localizar." << endl;
                    cout << "0. Voltar para o Menu Inicial." << endl;

                    cout << " " << endl;
                    cout << "Escolha uma opção: ";

                    int opcao_veiculo;
                    cin >> opcao_veiculo;
                    

                    system ("clear");

                    switch (opcao_veiculo) {
                        case 1:
                            incluirVeiculo();
                            break;
                        case 2:
                            excluirVeiculo();
                            break;
                        case 3:
                            alterarVeiculo();
                            break;
                        case 4:
                            listarVeiculos();
                            break;
                        case 5:
                            localizarVeiculo();
                            break;
                        case 0:
                            // Voltar para o Menu Inicial
                            break;
                        default:
                            cout << "Opção inválida." << endl;
                            break;
                    }

                    if (opcao_veiculo == 0) {
                        break;
                    }
                }
                break;
            case 3:
                // Menu de gestão de locações
                while (true) {

                    cout << "   Empresa de locação de veículos LocaFINA S/A." << endl;
                    cout << "___________________________________________________" << endl;
                    cout << " " << endl;

                    cout << "Menu de Gestão de Locações:" << endl;
                    cout << " " << endl;

                    cout << "1. Incluir Locação." << endl;
                    cout << "2. Excluir Locação." << endl;
                    cout << "3. Alterar Locação." << endl;
                    cout << "4. Listar Locações." << endl;
                    cout << "0. Voltar para o Menu Inicial." << endl;

                    cout << " " << endl;
                    cout << "Escolha uma opção: ";

                    int opcao_locacao;
                    cin >> opcao_locacao;

                    system ("clear");

                    switch (opcao_locacao) {
                        case 1:
                            incluirLocacao();
                            break;
                        case 2:
                            excluirLocacao();
                            break;
                        case 3:
                            alterarLocacao();
                            break;
                        case 4:
                            listarLocacoes();
                            break;
                        case 0:
                            // Voltar para o Menu Inicial
                            break;
                        default:
                            cout << "Opção inválida." << endl;
                            break;
                    }

                    if (opcao_locacao == 0) {
                        break;
                    }
                }
                break;
            case 4:
                // Menu de gestão de ocorrências
                while (true) {

                    cout << "   Empresa de locação de veículos LocaFINA S/A." << endl;
                    cout << "___________________________________________________" << endl;
                    cout << " " << endl;

                    cout << "Menu de Gestão de Ocorrências:" << endl;
                    cout << " " << endl;

                    cout << "1. Incluir uma ocorrência." << endl;
                    cout << "2. Excluir uma ocorrência." << endl;
                    cout << "3. Alterar uma ocorrência." << endl;
                    cout << "4. Listar todas as ocorrências por cliente." << endl;
                    cout << "5. Listar todas as ocorrências por veículo." << endl;
                    cout << "0. Voltar para o Menu Inicial." << endl;

                    cout << " " << endl;
                    cout << "Escolha uma opção: ";

                    int opcao_ocorrencia;
                    cin >> opcao_ocorrencia;

                    system ("clear");

                    switch (opcao_ocorrencia) {
                        case 1:
                            incluirOcorrencia();
                            break;
                        case 2:
                            excluirOcorrencia();
                            break;
                        case 3:
                            alterarOcorrencia();
                            break;
                        case 4:
                            listarOcorrenciasPorCliente();
                            break;
                        case 5:
                            listarOcorrenciasPorVeiculo();
                            break;
                        case 0:
                            // Voltar para o Menu Inicial
                            break;
                        default:
                            cout << "Opção inválida." << endl;
                            break;
                    }

                    if (opcao_ocorrencia == 0) {
                        break;
                    }
                }
                break;
            case 0:
                cout << "Encerrando o programa." << endl;
                return 0;
            default:
                cout << "Opção inválida." << endl;
                break;
        }
    }

    return 0;
}
