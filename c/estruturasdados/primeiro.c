#include <stdio.h>
#include <cs50.h>  //Obrigaório para get_string e o tipo de dados "string" que é um TAD

int main(void){

    string nome = get_string("Digite seu nome: ");

    printf("Olá, mundo!\n");
    printf("Tudo bem, %s\n", nome);
    printf("Bem vindo ao Unipê!\n");
    return 1;

    // para compilar este programa, digite no terminal:
    // make primeiro
    // Para executar, em seguida digite: ./primeiro
}