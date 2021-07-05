#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//========variaveis globais
typedef struct status{
  int contJogadas;
  int venceu;
  int vitX;
  int vitO;
  int qtdPartidas;
   // venceu = 0,
   // vitX = 0,
   // vitO = 0,
   
}Status;

Status dados;


int tam =3;
//==========================
void resetStruct(){
    dados.venceu = 0;
    dados.vitX = 0;
    dados.vitO = 0;
}
//=======tabuleiro===========
void exibirTabuleiro(char tab[tam][tam]){
    system("cls");
    printf("\n");
    printf(" %c | %c | %c \n",tab[0][0],tab[0][1],tab[0][2]);
    printf("------------\n");
    printf(" %c | %c | %c \n",tab[1][0],tab[1][1],tab[1][2]);
    printf("------------ \n");
    printf(" %c | %c | %c \n",tab[2][0],tab[2][1],tab[2][2]);
}

void verificaX(char tab[tam][tam]){

    if(tab[0][0] == 'X' && tab[0][1]=='X' && tab[0][2]=='X'){
        dados.contJogadas = 10;
        dados.venceu =1;
        dados.vitX++;
        printf("X Ganhou \n");
    }else if(tab[1][0] == 'X' && tab[1][1]=='X' && tab[1][2]=='X'){
        dados.contJogadas = 10;
         dados.venceu =1;
         dados.vitX++;
         printf("X Ganhou \n");
    }else if(tab[2][0] == 'X' && tab[2][1]=='X' && tab[2][2]=='X'){
         dados.contJogadas = 10;
         dados.venceu =1;
         dados.vitX++;
         printf("X Ganhou \n");
    }else if(tab[0][0] == 'X' && tab[1][0]=='X' && tab[2][0]=='X'){
         dados.contJogadas = 10;
         dados.venceu =1;
         dados.vitX++;
         printf("X Ganhou \n");
    }else if(tab[0][1] == 'X' && tab[1][1]=='X' && tab[2][1]=='X'){
         dados.contJogadas = 10;
         dados.venceu =1;
         dados.vitX++;
         printf("X Ganhou \n");
    }else if(tab[0][2] == 'X' && tab[1][2]=='X' && tab[2][2]=='X'){
         dados.contJogadas = 10;
         dados.venceu =1;
         dados.vitX++;
         printf("X Ganhou \n");
    }else if(tab[0][2] == 'X' && tab[1][2]=='X' && tab[2][2]=='X'){
         dados.contJogadas = 10;
         dados.venceu =1;
         dados.vitX++;
         printf("X Ganhou \n");
    }
}

void verificaO(char tab[tam][tam]){

    if(tab[0][0] == 'O' && tab[0][1]=='O' && tab[0][2]=='O'){
         dados.contJogadas = 10;
         dados.venceu = 1;
         dados.vitO++;
        printf("O Ganhou \n");
    }else if(tab[1][0] == 'O' && tab[1][1]=='O' && tab[1][2]=='O'){
         dados.contJogadas = 10;
         dados.venceu =1;
          dados.vitO++;
         printf("O Ganhou \n");
    }else if(tab[2][0] == 'O' && tab[2][1]=='O' && tab[2][2]=='O'){
         dados.contJogadas = 10;
         dados.venceu =1;
         dados.vitO++;
         printf("O Ganhou \n");
    }else if(tab[0][0] == 'O' && tab[1][0]=='O' && tab[2][0]=='O'){
         dados.contJogadas = 10;
         dados.venceu =1;
         dados.vitO++;
         printf("O Ganhou \n");
    }else if(tab[0][1] == 'O' && tab[1][1]=='O' && tab[2][1]=='X'){
         dados.contJogadas = 10;
         dados.venceu =1;
         dados.vitO++;
         printf("O Ganhou \n");
    }else if(tab[0][2] == 'O' && tab[1][2]=='O' && tab[2][2]=='O'){
         dados.contJogadas = 10;
         dados.venceu =1;
         dados.vitO++;
         printf("X Ganhou \n");
    }else if(tab[0][2] == 'O' && tab[1][2]=='O' && tab[2][2]=='O'){
         dados.contJogadas = 10;
         dados.venceu =1;
         dados.vitO++;
         printf("O Ganhou \n");
    }
}

int verifyInvalida(int linha, int coluna){
    if(linha !=1 || linha !=2 || linha != 3 || coluna!=1 || coluna!=2 || coluna!=3){
        return 1;
    }else{
        return 0;
    }
}

int verifyPreenchido(int linha, int coluna,char tab[tam][tam]){
    if(tab[linha-1][coluna-1] == ' '){
        return 1;
    }else{
        return 0;
    }
}



//=======inicializa o Jogo
void inicializar(char tab[tam][tam]){
    resetStruct();
    int gameLoad = 1;
    char continuar;
    int vez = 0;
    int linha, coluna;
    do{
         dados.contJogadas = 1;
         dados.qtdPartidas++;
        for(int i = 0; i<tam;i++){
            for(int j = 0; j<tam;j++){
                tab[i][j] = ' ';
            }
        }

        do{
            exibirTabuleiro(tab);
            if(vez%2 == 0){
                printf("Vez do Jogador X \n \n");
            }else{
                printf("Vez do Jogador O \n \n");
            }

            printf("Digite a Linha: ");
            scanf("%d",&linha);
            printf("Digite a Coluna: ");
            scanf("%d",&coluna);
            if(verifyInvalida(linha,coluna)==1){
            
                if(verifyPreenchido(linha,coluna,tab)==1){
                     if(vez%2 == 0){
                         tab[linha-1][coluna-1] = 'X';
                         verificaX(tab);
                        verificaO(tab);
                     }else{
                        tab[linha-1][coluna-1] = 'O';
                        verificaX(tab);
                         verificaO(tab);
                     }
                       vez++;
                }else{
                linha = 0;
                coluna = 0;
                printf("Campo já preenchido / Tente Novamente \n");
                system("pause");
                }
                
            }else{
                 linha = 0;
                coluna = 0;
                printf("Jogada Inválida / Tente Novamente \n");
                system("pause");
                
            }
             dados.contJogadas++;

        }while( dados.contJogadas<=9);
        printf("\n");
        if( dados.venceu == 0){
            printf("Empate");
        }
    printf("\n- Deseja continuar jogando? s/n : ");
    scanf("%s",&continuar);
    if(continuar == 'n'){
        gameLoad = 0;
    }

    }while(gameLoad == 1);
}
//=======fecha o Jogo
void breakGame(){
    system("pause");
    return 0;
}
//=======exibe o menu do jogo
 void menu(char tab[tam][tam]){
      int x = 0;
      int op;
        do{
        printf("_____# JOGO DA VELHA #_____\n");
        printf("\n");
        printf("Menu: \n");
        printf("1 - Iniciar Jogo \n");
        printf("2 - Fechar Jogo \n \n");
        printf("Digite o numero da opcao:");
        scanf("%d",&op);
        printf("\n");
        if(op == 1){
            inicializar(tab);
            x =1 ;
        }else if(op == 2){
            breakGame();
        }else{
            printf("Inválido digite novamente \n");
        }
        }while(x == 0);
 }
 
 void statistics(){
     float pX =  dados.vitX/ dados.qtdPartidas;
     float pO =  dados.vitO/ dados.qtdPartidas;
     printf("Quantidade de Partidas Jogadas : %d \n",  dados.qtdPartidas);

     printf("Quantidade de Vitórias: \n");
     printf("X = %d \n", dados.vitX);
     printf("O = %d \n", dados.vitO);

       printf("Porcentagem de Vitórias: \n");
     printf("X = %.1f porcentos \n",pX*100);
     printf("O = %.1f porcentos \n",pO*100);

 }
     
int main(){
    setlocale(LC_ALL, "Portuguese");
    //variáveis do jogo
    char tabuleiro[3][3];
    menu(tabuleiro);
    printf("\n\n");
    statistics();
      
}


   
    

    


