#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include "identificador_incremento.h"

struct Produtos{
    std::string nome;
    std::string descricao;
    long int numero_serie;
    float valor_produto; 
    int quantidade;
};
struct Validacao_dados{
    std::string validacao_numero_serie;
    std::string validacao_valor_produto;
    std::string validacao_quantidade;
    std::string validacao_cadastra_novamente;
    bool entrada_valida;
};
void cadastro(){

    system("cls");

    std::fstream arquivo_estoque("estoque.txt",std::ios_base::app);
    int decisao,cadastra_novamente,armazenar_identificador;
    Produtos produto;
    Validacao_dados validacao;

    if(arquivo_estoque.is_open()){
        validacao.entrada_valida = false;

        std::cout << "\033[36m" << "**********************" << std::endl;
        std::cout << "*  Tela de cadastro  *" << std::endl;
        std::cout << "**********************" << std::endl;
        std::cout << "\033[33m" << "Deseja cadastrar algum item? '1' para sim ou '2' para sair" << std::endl;
        std::cin >> decisao;
        if(decisao == 1){
            do{    
                arquivo_estoque << "****************************************" << std::endl;  

                armazenar_identificador = identificador_incremento();                
                arquivo_estoque << "Numero de identificacao: " << armazenar_identificador << std::endl;
                
                std::cout << "\033[36m" << "**********************" << std::endl;
                std::cout << "\033[36m" << "Cadastre seu produto abaixo:" << std::endl;

                std::cout << "\033[33m" << "Nome: ";
                std::getline(std::cin >> std::ws,produto.nome);
                arquivo_estoque << "Nome: " << produto.nome << std::endl;
                
                do{
                    std::cout << "\033[33m" << "Numero de Serie: ";
                    std::cin >> validacao.validacao_numero_serie;
                    try{
                        produto.numero_serie = std::stoi(validacao.validacao_numero_serie);
                        arquivo_estoque << "Numero de Serie: " << produto.numero_serie << std::endl;
                        validacao.entrada_valida = true;
                    }catch (const std::exception& e){
                        std::cout << "\033[31m" << "Numero de serie invalido,digite denovo" << std::endl;
                    }
                }while(validacao.entrada_valida == false);
                
                validacao.entrada_valida = false;

                do{
                    std::cout << "\033[35m" << "Valor do produto: ";
                    std::getline(std::cin >> std::ws,validacao.validacao_valor_produto);
                    try{
                        produto.valor_produto = std::stoi(validacao.validacao_valor_produto);
                        arquivo_estoque << "Valor unitario do produto: R$" << std::fixed << std::setprecision(2) << produto.valor_produto <<    std::endl;
                        validacao.entrada_valida = true;
                    }catch(const std::exception& e){
                        std::cout << "\033[35m" << "Valor invalido, digite novamente." << std::endl;
                    }
                }while(produto.valor_produto <= 0 || validacao.entrada_valida == false);
                
                validacao.entrada_valida = false;

                do{
                    std::cout << "\033[34m" << "Quantidade: ";
                    std::getline(std::cin >> std::ws,validacao.validacao_quantidade);
                    try{
                        produto.quantidade = std::stoi(validacao.validacao_quantidade);
                        arquivo_estoque << "Quantidade de produtos: " << produto.quantidade << std::endl;
                        validacao.entrada_valida = true;
                    }catch(const std::exception& e){
                        std::cout << "\033[31m" << "Quantidade invalida, digite novamente." << std::endl;
                    }
                }while(produto.quantidade <= 0 || validacao.entrada_valida == false);

                arquivo_estoque << "Preco Total: R$"  << std::fixed << std::setprecision(2) << produto.valor_produto*produto.quantidade << std::endl;
    
                std::cout << "\033[34m" << "Descricao: ";
                std::getline(std::cin >> std::ws,produto.descricao);
                arquivo_estoque << "Descricao: " << produto.descricao << std::endl;
                arquivo_estoque << "****************************************" << std::endl;   
                
                validacao.entrada_valida = false;
                std::cout << "\033[36m" << "**********************" << std::endl;
                std::cout << "\033[32m" << "Produto cadastrado com sucesso" << std::endl;

                do{
                    std::cout << "\033[4m" << "\033[33m" "Deseja cadastrar mais algum produto? '1' para sim ou '2' para nao." << "\033[0m" << std::endl; 
                    std::getline(std::cin >> std::ws,validacao.validacao_cadastra_novamente);
                    try{
                        cadastra_novamente = std::stoi(validacao.validacao_cadastra_novamente);
                        validacao.entrada_valida = true;
                    }catch(const std::exception& e){
                        std::cout << "\033[31m" << "Decisao invalida, digite novamente" << std::endl;
                    }
                }while(validacao.entrada_valida == false);
            }while(cadastra_novamente == 1);
        }
    }
    arquivo_estoque.close();
    Sleep(1500);
    system("cls");
}