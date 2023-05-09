#include <iostream>
#include "my-libs/cadastro.h"
#include "my-libs/exibicao.h"
#include "my-libs/menu.h"
#include "my-libs/sair.h"

int main(){

    int opcao;
    do{
        system("cls");
        opcao = menu();
        switch (opcao){
        case 1:
            cadastro();
            break;
        case 2:
            exibicao();
            break;
        case 3:
            sair();
            break;
        default:
            std::cout << "\033[35m" << "Opcao invalida, digite outra." << std::endl;
            break;
        }
    }while(opcao != 3);

    return 0;
}




