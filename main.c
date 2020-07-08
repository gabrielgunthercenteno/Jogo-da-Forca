
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL,"portuguese");

    printf("\n   ################### JOGO DA  FORCA########################");
    printf("\n   #                                                        #");
    printf("\n   #                   MENU PRINCIPAL                       #");
    printf("\n   #                                                        #");
    printf("\n   #               0- Para encerrar do jogo                 #");
    printf("\n   #               1- Para começar  o  jogo                 #");
    printf("\n   #                                                        #");
    printf("\n   #         Voce irá tentar adivinhar 3 palavras,          #");
    printf("\n   #            para isso possui 6 tentativas.              #");
    printf("\n   #                                                        #");
    printf("\n   #                    Categorias:                         #");
    printf("\n   #                1ª Palavra: Animal                      #");
    printf("\n   #                2ª Palavra: Esporte                     #");
    printf("\n   #                3ª Palavra: Profissão                   #");
    printf("\n   #                                                        #");
    printf("\n   ##########################################################\n");

    int w;
    printf("   ################### Começar o jogo? ######################\n");
    scanf("%d",&w);
    if(w==0)
    {
        printf("Saiu do Jogo!\n");
    }

    else
    {
        setbuf(stdin,NULL);
        char palavras[3][100];
        int tamanho[3];
        strncpy(palavras[0], "tubarao", 100);
        strncpy(palavras[1], "basquete", 100);
        strncpy(palavras[2], "cozinheiro", 100);
        tamanho[0]=strlen(palavras[0]);
        tamanho[1]=strlen(palavras[1]);
        tamanho[2]=strlen(palavras[2]);
        char dicas[3][100];
        int tamanhodica[3];
        tamanhodica[0]= strncpy(dicas[0], "Animal aquatico conhecido por seus instintos ferozes", 100);
        tamanhodica[1]= strncpy(dicas[1], "Esporte muito popular nos Estados Unidos", 100);
        tamanhodica[2]= strncpy(dicas[2], "Sua função é preparar a comida dos clientes de um restaurante", 100);

        char letras[30],lacunas[100];
        int letras_usadas[30];
        int tentativas=6,acertos,falhas,z,tamanho_palavra;

        for(z=0; z<3; z++)

        {

            int continuar;
            if(z>0)
            {
                printf("Deseja continuar? (Para continuar informar 1, para sair informar 0\n");
                scanf("%d",&continuar);
                setbuf(stdin,NULL);

            }
            if(continuar==0)
            {
                printf("\nJogo encerrado!");
            }

            else
            {
                acertos=0;
                printf("\nDica: %s",dicas[z]);
                tamanho_palavra=tamanho[z];
                memset(lacunas, '\0', sizeof(lacunas));


                int y;
                for(y=0; y<30; y++)
                {
                    letras_usadas[y]=0;
                }

                for(y=0; y<tamanho_palavra; y++)
                {
                    lacunas[y]='-';

                }

                while(tentativas>0)
                {
                    falhas=0;
                    printf("\n\n%s ",lacunas);
                    printf("\n\nDigite uma letra: ");
                    gets(letras);

                    int indice= (int)(letras[0]-97);
                    for(y=0; y<tamanho_palavra; y++)
                    {
                        if(letras_usadas[indice]==0)
                        {
                            if(letras[0]==palavras[z][y])
                            {
                                lacunas[y]=palavras[z][y];
                                acertos++;
                                falhas++;

                            }
                        }
                        else
                        {
                            printf("\nVoce ja usou essa letra!");
                            break;

                        }
                    }
                    letras_usadas[indice]=1;
                    if(falhas==0)
                    {
                        tentativas=tentativas-1;


                        if(tentativas==0)
                        {
                            printf("\nVoce foi enforcado! :(");
                            printf("\nA palavra a ser descoberta era: %s\n\n",palavras[z]);

                            break;
                        }

                        else
                            printf("\nVoce errou! Restam %d tentativa(s)",tentativas);

                    }

                    else
                    {
                        if(acertos==tamanho_palavra)
                        {
                            printf("\nParabens! Voce adivinhou a palavra! :)");
                            printf("\nGabarito: %s\n\n",palavras[z]);

                            if(z<2)
                            {
                                printf("\nVoce desbloqueou a proxima palavra!\n");

                            }
                            else
                                printf("\nO jogo acabou, PARABENS");

                            break;
                        }

                        else
                        {
                            printf("\nVoce acertou uma letra, continue assim!");

                        }
                    }
                }
            }
        }
        printf("\n\n");
    }
}
