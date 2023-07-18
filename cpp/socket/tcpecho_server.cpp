#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")
int main(int args, const char *argv[])
{
    WSADATA wsaData;
    int err = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (err != 0)
    { 
        printf("WSAStartup failed with error: %d\n", err);
        system("pause");
        exit(1);
    }
    sockaddr_in servAdr, clntAdr;
    SOCKET hServ_sock = socket(AF_INET, SOCK_STREAM, 0);
    printf("%llu\n", hServ_sock);
    memset(&servAdr,0, sizeof(servAdr));
    servAdr.sin_family = AF_INET;
    servAdr.sin_addr.s_addr= htonl(INADDR_ANY);
    servAdr.sin_port= htons(atoi(argv[1]));

    bind(hServ_sock, (SOCKADDR *)&servAdr, sizeof(servAdr));
    listen(hServ_sock, 32);
    int clntAdrSize = sizeof(clntAdr);                      
    int strLen, BUF_SIZE = 200;
    char message[255];
    for(int i = 0 ;i < 3;i++)
    {
        SOCKET hClnt_sock = accept(hServ_sock, (SOCKADDR *)&clntAdr, &clntAdrSize);

        printf("%llu\n", hClnt_sock);

        while((strLen = recv(hClnt_sock, message, BUF_SIZE, 0))!=0)
        {
            send(hClnt_sock, message, strLen, 0);
        }

        closesocket(hClnt_sock);
    }
    closesocket(hServ_sock);
    WSACleanup();
}