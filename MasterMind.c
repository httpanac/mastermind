#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

int dificuldadeJogo = 1; 
int tamanhoSenha = 0; 
int tamanhoHistorico = 0; 
int tentativa = 1; 
int maximoSenha; 
int jogadoresJogo = 1; 
char jogadorUm[25] = "Jogador 1"; 
char jogadorDois[25] = "Jogador 2"; 
int repetirNumerosJogo = 0; 
char senhaJogo[6]; 
int numeroRodadas = 1; 
int rodadaAtual; 
int jogadorAtual = 1; 
int jogadorVencedor = 1; 
int pontosJogadorUm = 0; 
int pontosJogadorDois = 0; 
char historicoJogo[6][14]; 

void vermelho () {
  printf("\033[1;31m");
}

void amarelo () {
  printf("\033[1;33m");
}

void verde () {
  printf("\033[1;32m");
}

void reset () {
  printf("\033[0m");
}


void logo(){
    verde();
    printf("\n\n\n\n");
    printf("         %c",218);
    reset();
    printf("\n");
    vermelho();
    printf("           **    **      ***      ****    ********   *******   *******   **    **   *   **  *   ******\n");
    printf("           **    **     *   *     **         *       ****      *******   **    **   *   * * *   *     *\n");
    printf("           * *  * *    *******      ****     *       ****      *   *     * *  * *   *   *  **   *     *\n");
    printf("           *  **  *   *       *    *****     *       *******   *     *   *  **  *   *   *   *   ** ***\n");
    reset();
    verde();
    printf("\n");
    printf("                                                                                                         %c",217);
    reset();
    vermelho();
    printf("\n\n\n\n\n\n Aluno(a): Ana Carolina Vargas. ");
    printf("\n Turma: 1 ADS. ");
    reset();
    vermelho();
    printf("\n\n\n\n\n                                                            ----------- AGUARDE 7 SEGUNDOS -----------");
    fflush(stdout);
    sleep(1);
    menu();
}


void vencedor() {
    system("cls");
    char vencedor[25];
    
    if(jogadorVencedor == 1) {
        for (int i = 0; i < sizeof(jogadorUm); i++) {
            vencedor[i] = jogadorUm[i];
        }
    } else {
        for (int i = 0; i < sizeof(jogadorDois); i++) {
            vencedor[i] = jogadorDois[i];
        }
    }
    
    verde();
    
    printf("===========================================================\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("\t\t\t  %s", vencedor);
    printf("\n\t\t\tVENCEDOR(A)\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("===========================================================");
    
    reset();
    
    fflush(stdout);
    sleep(4);
    menu();
}


void gameover() {
    system("cls");
    
    vermelho();
    
    printf("===========================================================\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("\t\t\tGAME OVER!");
    printf("\n\t\t\t   ;-;\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("===========================================================");
    
    reset();
    
    fflush(stdout);
    sleep(4);
    menu();
}


void empate() {
    system("cls");
    
    amarelo();
    
    printf("===========================================================\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("\t\t\tEMPATE!");
    printf("\n\t\t\t  '-'\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("===========================================================");
    
    reset();
    
    fflush(stdout);
    sleep(4);
    menu();
}


void jogo() {
    system("cls");
    char resposta[6]; 
    int contem = 0; 
    char jogador[25];

    
    if(jogadorAtual == 1) {
        for (int i = 0; i < sizeof(jogadorUm); i++) {
            jogador[i] = jogadorUm[i];
        }
    } else {
        for (int i = 0; i < sizeof(jogadorDois); i++) {
            jogador[i] = jogadorDois[i];
        }
    }

    if(tentativa == 1 && jogadoresJogo > 1) {
        system("cls");

        printf("Olha pra lá, ");
        verde();
        if(jogadorAtual == 1) {
            printf("%s", jogadorUm);
        } else {
            printf("%s", jogadorDois);
        }
        reset();
        printf("! ");
        verde();
        if(jogadorAtual == 1) {
            printf("%s", jogadorDois);
        } else {
            printf("%s", jogadorUm);
        }
        reset();
        printf(" vai digitar a senha!");
        printf("\n\n");
        printf("Regras da senha:");
        printf("\n");
        vermelho();
        printf("• Só podem ser números");
        if(dificuldadeJogo == 1) {
            printf("\n• Deve conter 4 números");
            printf("\n• Deve conter apenas números de 1 a 6");
        }
        if(dificuldadeJogo == 2) {
            printf("\n• Deve conter 5 números");
            printf("\n• Deve conter apenas números de 1 a 7");
        }
        if(dificuldadeJogo == 3) {
            printf("\n• Deve conter 6 números");
            printf("\n• Deve conter apenas números de 1 a 8");
        }
        if(repetirNumerosJogo == 0) {
             printf("\n• Não pode conter números repetidos ");
        }
        printf("\n\n");
        reset();
        printf("Digite a senha -> ");
        scanf(" %s", &senhaJogo);
    }  
    }
    
    system("clear");
    vermelho();
    printf("MASTER");
    reset();
    amarelo();
    printf("MIND");
    printf("\n\n");
    reset();
    
   
    if(jogadoresJogo > 1) {
        printf("\t\t");
        printf("%s(%i) X %s(%i)", jogadorUm, pontosJogadorUm, jogadorDois, pontosJogadorDois);
        printf("\n\n");
    }
    
    printf("RODADA %i / %i",  rodadaAtual, numeroRodadas);
    printf("\t\t");
    printf("TENTATIVA: %i / %i", tentativa, tamanhoHistorico);
    printf("\t\t");
    printf("JOGADOR(A): %s", jogador);
    
    printf("\n\n");

    
    for(int y = 0; y < tamanhoHistorico; y++) {
        for(int x = 0; x < tamanhoSenha; x++) {
            contem = 0;
            for(int i = 0; i < tamanhoSenha; i++) {
                if(historicoJogo[y][x] == senhaJogo[i]) {
                    contem = 1;
                }
            }
            if(historicoJogo[y][x] == senhaJogo[x]) {
                verde();
                printf("[%c] ", historicoJogo[y][x]);
            } else if(contem == 1) {
                amarelo();
                printf("[%c] ", historicoJogo[y][x]); 
            } else {
                vermelho();
                printf("[%c] ", historicoJogo[y][x]);
            }
        }
        printf("\n");
    }

    reset();

    printf("\n\n");

    printf("Digite o codigo de %i digitos -> ", tamanhoSenha);
    scanf(" %s", &resposta);

    
    int correto = 1; 

    for(int i = 0; i < tamanhoSenha; i++) {
        if(resposta[i] != senhaJogo[i]) {
            correto = 0;
            break;
        }
    }

    printf("\n\n");

    
    printf("DECODIFICANDO SENHA: [=         ]");
    fflush(stdout);
    sleep(1);
    printf("\rDECODIFICANDO SENHA: [===       ]");
    fflush(stdout);
    sleep(1);
    printf("\rDECODIFICANDO SENHA: [====      ]");
    fflush(stdout);
    sleep(1);
    printf("\rDECODIFICANDO SENHA: [======    ]");
    fflush(stdout);
    sleep(1);
    printf("\rDECODIFICANDO SENHA: [========  ]");
    fflush(stdout);
    sleep(1);
    if(correto == 1) {
        verde();
        printf("\rDECODIFICANDO SENHA: [==========]");
        fflush(stdout);
    } else{
        vermelho();
        printf("\rDECODIFICANDO SENHA: [==========]");
        fflush(stdout);
    }
    sleep(2);

    printf("\33[2K\r");

    reset();
    
    for(int i = 0; i < tamanhoSenha; i++) {
        contem = 0;
        for(int x = 0; x < tamanhoSenha; x++) {
            if(resposta[i] == senhaJogo[x]) {
                contem = 1;
            }
        }
        if(resposta[i] == senhaJogo[i]) {
            verde();
            printf("[%c] ", resposta[i]);
        } else if(contem == 1) {
            amarelo();
            printf("[%c] ", resposta[i]);
        } else {
            vermelho();
            printf("[%c] ", resposta[i]);
        }
    }
   
    reset();
    fflush(stdout);
    sleep(3);
    
    
    for(int i = 0; i < tamanhoSenha; i++) {
        historicoJogo[tentativa - 1][i] = resposta[i];
    }
    
    if(correto == 1) {
        if(jogadoresJogo < 2) {
            vencedor();
        } else {
            if(jogadorAtual == 1) {
                jogadorAtual = 2;
            } else {
                jogadorAtual = 1;
            }
            tentativa = 1;
            rodadaAtual++;
            memset(historicoJogo, 0, sizeof historicoJogo); 
        
    } else {
        if(jogadorAtual == 1) {
            pontosJogadorDois++;
        } else {
            pontosJogadorUm++;
        }
        tentativa++;
    }
   
    if(tentativa > tamanhoHistorico && jogadoresJogo < 2) {
        gameover();
    } 
    
    if(tentativa > tamanhoHistorico) {
        if(jogadorAtual == 1) {
            jogadorAtual = 2;
        } else {
            jogadorAtual = 1;
        }
        tentativa = 1;
        rodadaAtual++;
    } 
    
    if(rodadaAtual > numeroRodadas) {
        if(pontosJogadorUm > pontosJogadorDois) {
            jogadorVencedor = 1;
            vencedor();
        } else if(pontosJogadorUm == pontosJogadorDois){
            empate();
        } else {
            jogadorVencedor = 2;
            vencedor();
        }
    }
    
    if(tentativa <= tamanhoHistorico) {
        jogo();
    }
    
    
}


void novoJogo() {
    system("cls");
    vermelho();
    printf("MASTER");
    reset();
    amarelo();
    printf("MIND");
    printf("\n\n");
    reset();
    
    
    pontosJogadorUm = 0;
    pontosJogadorDois = 0;
   
    if(dificuldadeJogo == 1) {
        tamanhoSenha = 4;
        tamanhoHistorico = 10;
        maximoSenha = 6;
    } else if(dificuldadeJogo == 2) {
        tamanhoSenha = 5;
        tamanhoHistorico = 12;
        maximoSenha = 7;
    } else {
        tamanhoSenha = 6;
        tamanhoHistorico = 14;
        maximoSenha = 8;
    }
    
    if(jogadoresJogo > 1) {
        printf("Insira o nome do jogador 1 -> ");
        scanf(" %s", &jogadorUm);
        printf("Insira o nome do jogador 2 -> ");
        scanf(" %s", &jogadorDois);
        jogadorAtual = 2;

        int numeroRodadasAuxiliar = 1;

        while(numeroRodadasAuxiliar % 2 != 0) {
            printf("Insira a quantidade de rodadas a serem jogadas -> ");
            scanf("%i", &numeroRodadasAuxiliar);
        }

        numeroRodadas = numeroRodadasAuxiliar;
    
    } else {
        printf("Insira o nome do jogador -> ");
        scanf(" %s", &jogadorUm);
        jogadorAtual = 1;
    }
    
    rodadaAtual = 1;

    system("cls");

    
    if(jogadoresJogo < 2) {
        srand ( time(NULL) );
        if(repetirNumerosJogo == 1) {
            for(int i = 0; i < tamanhoSenha; i++) {
                char numero = rand() % maximoSenha+1;
                senhaJogo[i] = numero+'0';
            }
       
        } else {
            char numero;
            int repete;
            for(int i = 0; i < tamanhoSenha; i++) {
                numero = rand() % maximoSenha+1;
                for(int x = 0; x < i; x++) {
                    if(senhaJogo[x] == numero+'0'){
                        repete = 1;
                    }
                }
                if(repete == 1) {
                    repete = 0;
                    i--;
                } else {
                    senhaJogo[i] = numero+'0';
                    repete = 0;
                }
            }
        }
        printf("%s", senhaJogo);
    }
    
    jogo();
    
}

void dificuldade() {
    system("cls");
    vermelho();
    printf("DIFICULDADE");
    reset();

    int escolha;

    printf("\n\n");
    printf("Defina a dificuldade do jogo");
    printf("\n\n");
    printf("Dificuldade atual: ");
    if(dificuldadeJogo == 1) {
        verde();
        printf("FACIL");
        reset();
    } else if (dificuldadeJogo == 2) {
        amarelo();
        printf("MEDIO");
        reset();
    }
    else {
        vermelho();
        printf("DIFICIL");
        reset();
    }
    printf("\n\n");
    verde();
    printf("1. FACIL");
    reset();
    printf("\n");
    amarelo();
    printf("2. MEDIO");
    reset();
    printf("\n");
    vermelho();
    printf("3. DIFICIL");
    reset();
    printf("\n");
    printf("0. VOLTAR");
    printf("\n\n");
    scanf("%i", &escolha);

    switch(escolha) {
        case 1:
            dificuldadeJogo = 1;
            configs();
            break;
        case 2:
            dificuldadeJogo = 2;
            configs();
            break;
        case 3:
            dificuldadeJogo = 3;
            configs();
            break;
        case 0:
            configs();
            break;
    }

}

void jogadores() {
    system("cls");
    verde();
    printf("JOGADORES");
    reset();

    int escolha;

    printf("\n\n");
    printf("Defina a quantidade de jogadores");
    printf("\n\n");
    printf("quantidade atual: ");
    if(jogadoresJogo == 1) {
        verde();
        printf("1 JOGADOR");
        reset();
    }
    else {
        verde();
        printf("2 JOGADORES");
        reset();
    }
    printf("\n\n");
    printf("1. 1 JOGADOR");
    printf("\n");
    printf("2. 2 JOGADORES");
    printf("\n");
    printf("0. VOLTAR");
    printf("\n\n");
    scanf("%i", &escolha);

    switch(escolha) {
        case 1:
            jogadoresJogo = 1;
            configs();
            break;
        case 2:
            jogadoresJogo = 2;
            configs();
            break;
        case 0:
            configs();
            break;
    }

}

void repetirNumeros() {
    system("cls");
    verde();
    printf("REPETIR NUMEROS");
    reset();

    int escolha;

    printf("\n\n");
    printf("Defina se é possível repetir números");
    printf("\n\n");
    printf("definição atual: ");
    if(repetirNumerosJogo == 1) {
        verde();
        printf("SIM");
        reset();
    }
    else {
        vermelho();
        printf("NÃO");
        reset();
    }
    printf("\n\n");
    verde();
    printf("1. SIM");
    reset();
    printf("\n");
    vermelho();
    printf("2. NÃO");
    reset();
    printf("\n");
    printf("0. VOLTAR");
    printf("\n\n");
    scanf("%i", &escolha);

    switch(escolha) {
        case 1:
            repetirNumerosJogo = 1;
            configs();
            break;
        case 2:
            repetirNumerosJogo = 0;
            configs();
            break;
        case 0:
            configs();
            break;
    }

}

void configs() {
    system("cls");
    verde();
    printf("CONFIGURACOES");
    reset();

    int escolha;

    printf("\n\n");
    printf("Selecione uma opcao abaixo");
    printf("\n\n");
    printf("1. DIFICULDADE");
    printf("\n");
    printf("2. REPETIR NUMEROS");
    printf("\n");
    printf("3. NUMERO DE JOGADORES");
    printf("\n");
    printf("0. VOLTAR");
    printf("\n\n");
    scanf("%i", &escolha);

    switch(escolha) {
        case 1:
            dificuldade();
            break;
        case 2:
            repetirNumeros();
            break;
        case 3:
            jogadores();
            break;
        case 0:
            menu();
            break;
    }
}

void menu() {
    system("cls");
    vermelho();
    printf("MASTER");
    reset();
    amarelo();
    printf("MIND");
    printf("\n\n");
    reset();

    int escolha;

    printf("Selecione uma opcao abaixo");
    printf("\n\n");
    printf("1. JOGAR");
    printf("\n");
    printf("2. CONFIGURACOES");
    printf("\n");
    printf("3. SAIR");
    printf("\n\n");
    scanf("%i", &escolha);

    switch(escolha) {
        case 1:
            novoJogo();
            break;
        case 2:
            configs();
    }
}

int main () {
    system("cls");
    memset(historicoJogo, 0, sizeof historicoJogo);
    logo();
    return 0;
}
