#include <iostream>

int menu(){

    int opcao;
    std::string validar_opcao;
    bool opcao_valida = false;

    std::cout << "\033[32m" << "********************" << std::endl; 
    std::cout << "* Sistema Produtos *" << std::endl;
    std::cout << "********************" << std::endl; 
    std::cout << "\033[31m" << "O que deseja acessar(1-3)?" << std::endl;
    std::cout << "\033[34m" << "1.Cadastro" << std::endl;
    std::cout << "2.Exibicao" << std::endl;
    std::cout << "3.Sair" << "\033[0m" << std::endl;
    do{
        std::getline(std::cin >> std::ws,validar_opcao);
        try{
            opcao = std::stoi(validar_opcao);
            opcao_valida = true;
        }catch(const std::exception& e){
            std::cout << "Opcao invalida, tente novamente:" << std::endl;
        }
    }while(opcao_valida == false);

    return opcao;
}