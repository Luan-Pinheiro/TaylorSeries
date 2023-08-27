//Inclusão de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

//Definição da consstante PI
#define PI 3.14159265358979323846

//Protótipos das funções
double serie_Taylor_eX(double);
double fatorial(double);
double serie_Taylor_Seno(double);
double aproximacao_Seno(double);
//Função main
int main(){
    setlocale(LC_ALL,"pt_BR.UTF-8");//Setando idioma pra protuguês
    setlocale(LC_ALL,"Portuguese");//Setando idioma pra protuguês
    char selecao;// Variável de selecao do menu
    //Exibição do menu
    printf("\n\t|********************************************************|\n\t|\t\t\tMENU\t\t\t\t |");
    printf("\n\t|********************************************************|\n");
    printf("\t|RESOLUCAO DAS FUNCOES [f(x) = sen(x)] e [g(x) = e^x]\t |");
    printf("\n\t|Qual a funcao que deseja resolver?\t\t\t |");
    printf("\n\t|a)[f(x) = sen(x)]\t\t\t\t\t |");
    printf("\n\t|0) Sair\t\t\t\t\t\t |\n\t|________________________________________________________|\n");
    scanf("%c", &selecao);//Escolha de opção
        while(selecao!="-1"){
            switch (selecao){
            case 'a':{
                printf("Insira o valor de x em f(x): ");
                double x;// Variável da funcao f(x)
                scanf("%lf", &x);
                double x1 = x;
                x = x*(PI/180);  //Convertendo a entrada de graus para radianos
                double resultado = serie_Taylor_Seno(x);
                double aprox = aproximacao_Seno(x);
                //Exibicao do valor final, com 10 casas decimais, da funcao e^x, obtido atraves da serie de Taylor
                //e valor através da fórmula de aproximação
                printf("\nSerie de Taylor para seno(%.2f) = %.10f radianos\n", x1, resultado);
                printf("Aproximacao para seno(%.2f) = %.10f radianos\n\n", x1, aprox);
            break;}
            case 'b':{
                printf("Insira o valor de x em g(x): ");
                double X;// Variável da funcao g(x)
                scanf("%lf", &X);//Obtenção do valor do expoente
                //Exibicao do valor final, com 10 casas decimais, da funcao e^x, obtido atraves da serie de Taylor
                printf("\nSerie de Taylor para e^%.1lf:\n\ng(%.2lf) = %.10lf\n\n",X,X,serie_Taylor_eX(X));
            break;}
            case '0':
                return 0; //Sair
            break;
            default:
                printf("Opcao invalida! \n");//Mensagem de erro
            }
        }
    return 0;
}

//Funcao de obtenção do fatorial de um numero qualquer
double fatorial(double n) {
    //Caso base da recursao
    if (n <= 1) {
        return 1.0;
    }
    // retorno recusivo até se obter o caso base
    return n * fatorial(n - 1.0);
}

//Funcao de obtencao do valor do seno de um numero qualquer
double serie_Taylor_Seno(double x) {
    double resultado = 0.0; // resultado final, inicializado com 0.0
    double termo = x; //Termo atual da operacao
    int n = 1; //numero 'n' do termo em operacao, este vai ser usado como expoente e fatorial
/*Explicação do while:
Esse ciclo exemplifica  da serie de taylor para a funcao seno(x),
realizando a conversao da logica da serie para codificacao, em que a exponenciacao/fatorial de n, em Taylor,
sao obtidos atraves de multiplicações/divisões/potenciações sucessivas e acumulações enquanto a condicao do while 
estiver sendo atendida (termo atual absoluto fabs(termo) for maior que 0)
O resultado,recebe o valor do termo, fazendo papel acumulativo e o termo em questao é definido através da potência do 
x pro 2*n+1 e dividido pelo fatorial de 2*n+1
o sinal do termo é definido pela potência de -1 elevado a posição do termo da operação (n)*/
    while (fabs(termo) > 0) {
        resultado += termo; //acumulacão do valor do termo da iteracao
        termo = pow(-1, n) * pow(x, 2 * n + 1) / fatorial(2 * n + 1); // Operação para cada termo em específico
        n++;//iteração
    }
    return resultado;//retorno do resultado
}

//Funcao de obtencao do valor de 'e' elevado a um numero qualquer
double serie_Taylor_eX(double exp) {
    double somatorio = 0.0; //Somatorio final do resultado, inicializado com zero
    double termo = 1.0; //Termo atual, inicializado com um (1), por ser fator neutro da multiplicacao
    int n = 1; // iterador do ciclo, incialiazado em 1
/*Explicação do while:
Esse ciclo exemplifica  da serie de taylor para a funcao exponencial,
realizando a conversao da logica da serie para codificacao, em que a exponenciacao/fatorial de n, em Taylor,
sao obtidos atraves de multiplicações/divisões sucessivas e acumulacoes acumulações a condicao do while estiver sendo atendida
O somatorio,recebe o valor do termo, fazendo papel acumulativo e o termo em questao (Inicialmente 1) multiplica a 
função (expoente / iterador) ,
O ciclo ocorre enquanto o termo for maior que zero, obtendo assim grande aproximacao*/
    while (termo > 0){
      somatorio += termo;//acumulacão do valor do termo da iteracao
      termo *= exp /n; // reescrita codificada do termo especifico na serie de taylor
      n++;//iteração
    }
    return somatorio;//retorno do resultado
}


double aproximacao_Seno(double x){
    double seno = 0;
    seno = x - 1.0/6.0*(pow(x,3)) + 1.0/120.0*(pow(x,5)); //Formula aproximação

    return seno;
}


