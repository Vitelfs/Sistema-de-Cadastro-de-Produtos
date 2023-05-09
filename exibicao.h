#include <iostream>
#include <fstream>
#include <windows.h>

void exibicao(){

    system("cls");
    std::ifstream arquivo_estoque("estoque.txt");
    int decisao,proximas_linhas = 0;
    std::string linhas,numero_de_identificacao,decisao_to_num;

    if(arquivo_estoque.is_open()){
        if(arquivo_estoque.peek() == std::ifstream::traits_type::eof()){
            std::cout << "\033[33mNao temos nenhum produto cadastrado ;-;" << std::endl;
        }
        else{
            std::cout << "\033[33m" << "**************************\n" << std::endl;
            while(std::getline(arquivo_estoque,linhas)){
                if(linhas.substr(0,24) == "Numero de identificacao:"){
                    std::cout << "\033[31m" << linhas.substr(0) << std::endl;
                }
                if(linhas.substr(0,5) == "Nome:"){
                    std::cout << "\033[32m" << linhas.substr(0) << std::endl;
                }
                if(linhas.substr(0,16) == "Numero de Serie:"){
                    std::cout << "\033[34m" <<  linhas.substr(0) << "\n" << std::endl;
                }
                
            }
            std::cout << "\033[33m" << "**************************" << std::endl;
            arquivo_estoque.close();

            std::cout << "\033[36m" << "Deseja olhar algum item mais detalhadamente? '1' para sim ou '2' para nao" << std::endl;
            std::getline(std::cin >> std::ws,decisao_to_num);

            try{
                decisao = std::stoi(decisao_to_num);
            }catch (const std::exception& e){
                std::cout << "\033[31m" << "Entrada invalida" << std::endl;
            }

            if(decisao == 1){
                std::cout << "\033[33m" << "Digite o numero de idendificacao do produto: ";
                std::cin >> numero_de_identificacao;
                std::ifstream arquivo_estoque_pesquisa("estoque.txt");

                if(arquivo_estoque_pesquisa.is_open()){
                    bool encontrou_produto = false;
                    while(std::getline(arquivo_estoque_pesquisa,linhas)){
                        if(linhas.find("Numero de identificacao: "+numero_de_identificacao) != std::string::npos && encontrou_produto == false){
                            encontrou_produto = true;
                            std::cout << "\033[32m" << "\nProduto encontrado:" << std::endl;
                        }
                        if(encontrou_produto && proximas_linhas <= 6){
                            std::cout << "\033[0m" << linhas << std::endl;
                            proximas_linhas++;
                        }
                    }
                    if(encontrou_produto == false){
                        std::cout << "\033[31m" << "Produto nao encontrado." << std::endl;
                    }
                }
                arquivo_estoque_pesquisa.close();
            }
        }
    }   
    
    system("pause");
}