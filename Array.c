#include<stdio.h>
#define N 8 //-> Número de elementos que seram lidos pelo vetor:

//Função responsável por fazer a leitura do vetor e vereficar
//os valores introduzidos:
void readarray(int vetor[], int n){
    if (n > 0){
        scanf("%i", &vetor[N - n]);
        while (vetor[N - n] > 40 | vetor[N - n] < -8){
            printf("O valor esta fora do intervalo pretendido\n");
            scanf("%i", &vetor[N - n]);
        }
        readarray(vetor, n - 1);
    }
}

//Função responsável por fazer a soma da primeira metade do vetor
//Com a segunda metade do vetor
void somaarray(int vetor[], int soma[]){ 
    for (int i = 0; i < N/2; i++){
        soma[i] = vetor[i] + vetor[(N/2) + i]; 
    }
}

//Função responsável devolver o calculo o cubo dos valores:
int cubo(int x){
    return x * x * x;
}

//Função que devolver o valor das posição multiplas de 3 do vetor:
void x3(int vetor[]){
    for (int i = 3; i < N; i = i + 3){
        printf("\nValor da %iº posição -> %i\n", i, vetor[i]);
    }
}

//Função responsável por construir uma matriz 4 x 14 em que cada linha
//É composta pelo vetor lido
void array4x14(int vetor[]){
    for (int i = 1; i <= 4; i++){
        for (int j = 0; j < N; j++){
            printf(" %i |", vetor[j]);
        }
        printf("\n");
    }
}

//Função responsável por fazer a ordenação de metade do vetor
void ordenar(int vetor[]){
    int aux = -99999, vetoraux[N];
    //Criação de um vetor auxiliar para não alterar o original
    for (int i = 0; i < N; i++){
        vetoraux[i] = vetor[i];
    }
    //Calculo do vetor com a segunda metade em ordem crescente:
    for (int i = N/2; i < N; i++){
    int menor = 99999999;     
        for (int j = N/2; j < N; j++){
            if (vetor[j] < menor & vetor[j] > aux){
                menor = vetor[j];
            }          
        }
        vetoraux[i] = menor;
        aux = menor;
    }
    //Impressão no ecrã do vetor com a segunda metade em ordem crescente:
    for (int i = 0; i < N; i++){
        printf("%i\n", vetoraux[i]);
    }
}

//Função responsável por mostrar o menu na tela:
void menu(){
    printf("\n*************************************************************************************\n");
    printf("*                                      Menu                                         *\n");
    printf("*************************************************************************************\n");
    printf("1 -> Cálculo da soma da primeira metade dos elementos com os elementos da segunda metade.\n");
    printf("2 -> Cálculo do cubo de primeiro e último elementos do vetor.\n");
    printf("3 -> Devolução dos valores em posições múltiplas de três.\n");
    printf("4 -> Construção de uma matriz 4 x 14, em que cada linha é o vetor lido.\n");
    printf("5 -> Cálculo da mediana dos elementos no vetor.\n");
    printf("6 -> Devolução do vetor, com a segunda metade dos valores ordenada por ordem crescente.\n");
    printf("0 -> Sair\n");
}

int main(void){
    int soma[N/2], vetor[N], vetoraux[N],op;
    printf("Por favor indique 14 valores entre o intervalo -7 a 39\n");
    readarray(vetor, N);
    vetoraux[N] = vetor[N];
    do
    {
        menu();
        scanf("%i", &op);
        switch (op)
        {
        case 1:
            somaarray(vetor, soma);
            printf("\nA soma da primeira metade do vetor com a segunda metade,\ndá origem ao seguinte vetor\n");
            printf("soma = ");
            for (int i = 0; i < N/2; i++){
                printf(" %i |", soma[i]);
            }
            printf("\n");
            break;
        case 2:
            printf("\nCubo da 1ª posição do vetor -> %i\n", cubo(vetor[0]));
            printf("Cubo da ultima posição do vetor -> %i\n", cubo(vetor[N - 1]));
            break;
        case 3:
            x3(vetor);
            break;
        case 4:
            array4x14(vetor);
            break;
        case 5:
            break;
        case 6:
            ordenar(vetor);
            break;
        default:
            break;
        }
    }while (op != 0);    
    return 0;
}
