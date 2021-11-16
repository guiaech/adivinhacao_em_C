#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    printf("**********************************\n");
    printf("*Bem vindo ao jogo de adivinhação*\n");
    printf("**********************************\n");

    int segundos = time(0);
    srand(segundos);

    int numerogrande = rand();

    int numerosecreto = numerogrande % 100;
    int chute;
    int ganhou = 0;
    int tentativas = 1;
    double pontos = 1000;
    int acertou = 0;

    int nivel;
    printf("Qual nível de dificuldade quer jogar? \n");
    printf("(1) Fácil  (2) Médio (3) Difícil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numerodetentativas ;

    switch(nivel)
    {
      case 1:
      numerodetentativas = 20;
      break;

      case 2:
      numerodetentativas = 15;
      break;

      default:
      numerodetentativas = 6;
      break;
    }


    for (int i = 1; i<= numerodetentativas; i++ )
    {
        printf("\n");
        printf("Tentativa %d \n",tentativas);
        printf("Qual é o seu chute? ");
        scanf("%d", &chute);
        printf("Seu chute foi %d \n", chute);

        if (chute < 0)
        {
          printf("Não pode chutes com valores negativos \n");
          continue;
        }

        acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;

        if (acertou){
        break;
        }
        else if (maior)
          {
            printf("\nSeu chute foi maior que o número secreto\n");
          }
          else 
          {
            printf("\nSeu chute foi menor que o número secreto .\n");
          }
          tentativas++;   

          double pontosperdidos = abs(chute - numerosecreto) / (double)2;
          pontos = pontos - pontosperdidos;
    }
    if (acertou){
      printf("Parabéns você acertou! \n");
      printf("Jogue de novo, você é um bom jogador! \n");
      printf("\n");
      printf("********* Fim de jogo! **********\n");
      printf("  Você acertou em %d tentativa(s)\n", tentativas-1);
      printf("   Sua pontuação foi de %.1f!\n", pontos);
      printf("*********************************\n");
    }else
    {
      printf("********* Fim de jogo! **********\n");
      printf("  Você perdeu, tente novamente   \n");
      printf("*********************************\n");
    }

}
