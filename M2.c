//Nome: Gabriel Kento Toledo Takagi  Registro Academico:1929933

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define TAMANHOLISTA 10

int main(void){

    pid_t pid = fork();
    int status;
    int matriz[TAMANHOLISTA][TAMANHOLISTA] = {{3, 8, 1, 6, 4, 9, 7, 2, 5, 10},
                                               {9, 6, 5, 1, 2, 3, 8, 7, 10, 4},
                                               {2, 1, 7, 9, 5, 10, 4, 8, 6, 3},
                                               {4, 10, 8, 3, 7, 6, 5, 1, 2, 9},
                                               {5, 2, 9, 8, 10, 4, 6, 3, 1, 7},
                                               {1, 4, 3, 2, 8, 5, 10, 6, 9, 7},
                                               {8, 3, 6, 10, 1, 7, 2, 4, 9, 5},
                                               {7, 9, 10, 4, 6, 1, 3, 5, 8, 2},
                                               {6, 5, 2, 7, 9, 8, 1, 10, 4, 3},
                                               {10, 7, 4, 5, 3, 2, 9, 8, 3, 1}};



    if (pid < 0) //Erro ao executar o processo filho
    {
        printf("Erro ao iniciar o fork\n");
        exit(-1);
    }else if (pid == 0)//Processo filho
    {   
        int o;
        printf("Iniciando processo Filho: %d\n", getpid());
        execlp("/bin/bash", "/bin/bash", "/home/kento/VScode/C/comandos.sh", NULL); //Executa o arquivo bash
        //sleep(100);
        
        exit(-1);

    }else //Processo pai
    {
        printf("Iniciando processo Pai: %d\n", getpid());

        //Faz a matriz transposta
        int y,x, matrizT [TAMANHOLISTA][TAMANHOLISTA];
        for(y = 0; y < TAMANHOLISTA; y++){
            for(x = 0; x < TAMANHOLISTA; x++){
                matrizT[x][y] = matriz[y][x];
            }
        }

        wait(&status);//Espera o filho terminar

        //Printa a matriz normal
        printf("\n");
        printf("Matriz normal\n");
        for(y = 0; y < TAMANHOLISTA; y++){
            for(x = 0; x < TAMANHOLISTA; x++){
                printf("%d ", matriz[y][x]);
            }
            printf("\n");
        }

        //printe da matriz composta
        printf("\n");
        printf("Matriz transposta \n");
        for(y = 0; y < TAMANHOLISTA; y++){
            for(x = 0; x < TAMANHOLISTA; x++){
                printf("%d ", matrizT[y][x]);
            }
            printf("\n");
        }

        printf("%s", WEXITSTATUS(status) == 0 ? "Sucesso" : "Falha");
        printf("\n");
    }
    
    return 0;
}