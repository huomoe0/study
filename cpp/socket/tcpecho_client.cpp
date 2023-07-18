#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")
int main(int args, const char *argv[])
{
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    SOCKET hSocket = socket(PF_INET, SOCK_STREAM, 0);
    sockaddr_in servAdr, clntAdr;
    memset(&servAdr,0, sizeof(servAdr));
    servAdr.sin_family = AF_INET;
    servAdr.sin_addr.s_addr= inet_addr(argv[1]);
    servAdr.sin_port= htons(atoi(argv[2]));
    connect(hSocket, (SOCKADDR *)&servAdr, sizeof(servAdr));
    int strLen, BUF_SIZE = 200;
    char message[255], res[255];
    while (1)
    {
        fputs("Input message(Q to quit): ", stdout);
        
        fgets(message, BUF_SIZE, stdin);

        if (!strcmp(message, "q\n")||!strcmp(message, "Q\n")) break;

        send(hSocket, message, strlen(message), 0);
        strLen= recv(hSocket, res, BUF_SIZE-1, 0);

        res[strLen]=0;
        printf("The message from the server: %s\n", res);
    }
    
    closesocket(hSocket);
    WSACleanup();
    
}