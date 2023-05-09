#include <iostream>
#include <fstream>


int identificador_incremento(){
    
    int identificador;

    std::ifstream identificador_valor("identificador.txt");

    if(identificador_valor.is_open()){
        identificador_valor >> identificador;
        identificador++;
        identificador_valor.close();
    }

    std::ofstream atualizar_identificador_valor("identificador.txt");

    if(atualizar_identificador_valor.is_open()){
        atualizar_identificador_valor << identificador;
        atualizar_identificador_valor.close();
    }

    return identificador;
}