#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C" {
#include "extApi.h"
}

int main(int argc, char* argv[])
{
    //Abrir e ler o arquivo
    char votos[8192];
    FILE* arq = fopen("votos.txt", "r");

    if (arq == NULL) {
        printf("Não foi possível abrir o arquivo.");
        exit(1);
    }

    //conecta com o coppelia
    int clientID = simxStart((simxChar*)"127.0.0.1", 19999, true, true, 2000, 5);

    extApi_sleepMs(500);

    //verifica conexao com simulador
    if (clientID == -1) {
        printf("Erro ao conectar com o Coppelia!\n");
        return 0;
    }else {
        printf("Conectado ao Coppelia!\n");
    }

    //cria string representa um junta, em sua ordem respectiva
    simxChar joint1[150] = "/braco/joint_1";
    simxChar joint2[150] = "/braco/joint_2";
    simxChar joint3[150] = "/braco/joint_3";

    //cada varíavel indica uma junta
    int handler1 = 1;
    int handler2 = 2;
    int handler3 = 3;

    //Armazena o diretório de cada junta no endereço das variáveis "handler"
    simxGetObjectHandle(clientID, joint1, &handler1, (simxInt)simx_opmode_oneshot_wait);
    simxGetObjectHandle(clientID, joint2, &handler2, (simxInt)simx_opmode_oneshot_wait);
    simxGetObjectHandle(clientID, joint3, &handler3, (simxInt)simx_opmode_oneshot_wait);

    //Deixa o braço mecânico na posição de tomada para apertar os números
    simxSetJointTargetPosition(clientID, handler1, -0.27, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler3, 0.02, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler2, -0.80, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(10000);

    while (!feof(arq)) { //Continuará rodando enquanto não ler o arquivo inteiro
        fscanf(arq, "%s\n", votos);

        for (int i = 0; i < strlen(votos); i++) { //Aperta os números da linha que foi lida

            simxSetJointTargetPosition(clientID, handler2, -0.80, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(2000);
            simxSetJointTargetPosition(clientID, handler1, -0.27, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(2000);
            simxSetJointTargetPosition(clientID, handler3, 0.02, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(2000);

            if (votos[i] == '0') {
                simxSetJointTargetPosition(clientID, handler1, -0.285, (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(1500);
                simxSetJointTargetPosition(clientID, handler3, -0.088, (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(1500);
                simxSetJointTargetPosition(clientID, handler2, -0.837, (simxInt)simx_opmode_oneshot_wait);
            }else if (votos[i] == '1') {
                simxSetJointTargetPosition(clientID, handler1, -0.20, (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(2000);
                simxSetJointTargetPosition(clientID, handler2, -0.790, (simxInt)simx_opmode_oneshot_wait);
                simxSetJointTargetPosition(clientID, handler3, 0.11, (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(1500);
                simxSetJointTargetPosition(clientID, handler2, -0.845, (simxInt)simx_opmode_oneshot_wait);
            }else if (votos[i] == '2') {
                simxSetJointTargetPosition(clientID, handler1, -0.25, (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(2000);
                simxSetJointTargetPosition(clientID, handler3, 0.13, (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(1500);
                simxSetJointTargetPosition(clientID, handler2, -0.855, (simxInt)simx_opmode_oneshot_wait);
            }else if (votos[i] == '3') {
                simxSetJointTargetPosition(clientID, handler1, -0.32, (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(2000);
                simxSetJointTargetPosition(clientID, handler3, 0.2, (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(1500);
                simxSetJointTargetPosition(clientID, handler2, -0.895, (simxInt)simx_opmode_oneshot_wait);
            }else if (votos[i] == '4') {
                simxSetJointTargetPosition(clientID, handler1, -0.20, (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(1500);
                simxSetJointTargetPosition(clientID, handler3, 0.019, (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(1500);
                simxSetJointTargetPosition(clientID, handler2, -0.814, (simxInt)simx_opmode_oneshot_wait);
            }else if (votos[i] == '5') {
                simxSetJointTargetPosition(clientID, handler3, 0.050, (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(1500);
                simxSetJointTargetPosition(clientID, handler2, -0.840, (simxInt)simx_opmode_oneshot_wait);
            }else if (votos[i] == '6') {
                simxSetJointTargetPosition(clientID, handler1, -0.34, (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(1500);
                simxSetJointTargetPosition(clientID, handler3, 0.13, (simxInt)simx_opmode_oneshot_wait);
                simxSetJointTargetPosition(clientID, handler2, -0.885, (simxInt)simx_opmode_oneshot_wait);
            }else if (votos[i] == '7') {
                simxSetJointTargetPosition(clientID, handler3, -0.050, (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(1500);
                simxSetJointTargetPosition(clientID, handler2, -0.790, (simxInt)simx_opmode_oneshot_wait);
                simxSetJointTargetPosition(clientID, handler1, -0.20, (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(1500);
                simxSetJointTargetPosition(clientID, handler2, -0.814, (simxInt)simx_opmode_oneshot_wait);
            }else if (votos[i] == '8') {
                simxSetJointTargetPosition(clientID, handler3, -0.020, (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(1500);
                simxSetJointTargetPosition(clientID, handler2, -0.830, (simxInt)simx_opmode_oneshot_wait);
            }else if (votos[i] == '9') {
                simxSetJointTargetPosition(clientID, handler1, -0.34, (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(1500);
                simxSetJointTargetPosition(clientID, handler3, 0.0, (simxInt)simx_opmode_oneshot_wait);
                simxSetJointTargetPosition(clientID, handler2, -0.845, (simxInt)simx_opmode_oneshot_wait);
                simxSetJointTargetPosition(clientID, handler3, 0.03, (simxInt)simx_opmode_oneshot_wait);
                simxSetJointTargetPosition(clientID, handler2, -0.870, (simxInt)simx_opmode_oneshot_wait);
            }else if (votos[i] == 'b') { //Caso o voto seja em branco
                simxSetJointTargetPosition(clientID, handler3, -0.175, (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(2000);
                simxSetJointTargetPosition(clientID, handler1, -0.20, (simxInt)simx_opmode_oneshot_wait);
                extApi_sleepMs(2000);
                simxSetJointTargetPosition(clientID, handler2, -0.830, (simxInt)simx_opmode_oneshot_wait);
            }
            extApi_sleepMs(1500);
        }

        //Retorna a posição de tomada
        simxSetJointTargetPosition(clientID, handler2, -0.80, (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(1500);
        simxSetJointTargetPosition(clientID, handler1, -0.27, (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(1500);
        simxSetJointTargetPosition(clientID, handler3, 0.02, (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(1500);

        //Confirma o voto
        simxSetJointTargetPosition(clientID, handler3, -0.075, (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(1500);
        simxSetJointTargetPosition(clientID, handler1, -0.40, (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(1000);
        simxSetJointTargetPosition(clientID, handler2, -0.880, (simxInt)simx_opmode_oneshot_wait);
        simxSetJointTargetPosition(clientID, handler3, -0.060, (simxInt)simx_opmode_oneshot_wait);
        simxSetJointTargetPosition(clientID, handler2, -0.900, (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(1500);
    }

    //Retorna a posição inicial do braço mecânico
    simxSetJointTargetPosition(clientID, handler2, 0.0, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);
    simxSetJointTargetPosition(clientID, handler3, 0.0, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);
    simxSetJointTargetPosition(clientID, handler1, 0.0, (simxInt)simx_opmode_oneshot_wait);

    // Fecha a conexão 
    simxFinish(clientID);
    fclose(arq);

    return(0);
}
