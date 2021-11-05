#define _CRT_SECURE_NO_WARNINGS 1
#include <string.h>
#include <cstdio>
#include <corecrt_malloc.h>

__int64 __fastcall subfhsadkhjbfleiowiuoyfgshjdvbsmnakl(__int64 a1, __int64 a2)
{
    int i; // [rsp+1Ch] [rbp-24h]
    char* dest; // [rsp+20h] [rbp-20h]
    char* s; // [rsp+28h] [rbp-18h]

    dest = (char*)malloc(0x80uLL);
    strcpy(dest, (const char*)(a1 + 7));
    dest[strlen(dest) - 1] = 0;
    s = (char*)malloc(0x80uLL);
    strcpy(s, (const char*)(a2 + 7));
    s[strlen(s) - 1] = 0;
   // for (i = 0; i < strlen(dest); ++i)
       // dest[i] ^= *(*unk_6984657 + i);
    //return unk_sa7ydu3jb432(dest, s);
    return (_int64)dest;
}


int __cdecl main(int argc, const char** argv, const char** envp)
{
    char* s; // [rsp+8h] [rbp-8h]

    s = (char*)malloc(0x40uLL);
    puts(
        "              __________   _____  __________ _____________________\n"
        "             \\______   \\ /  _  \\ \\______   \\\\_   _____/\\______\n"
        "              |     ___//  /_\\  \\ |     ___/ |    __)_  |       _/\n"
        "              |    |   /    |    \\|    |     |        \\ |    |   \\\n"
        "              |____|   \\____|__  /|____|    /_______  / |____|_  /\n"
        "                               \\/                   \\/         \\/\n"
        "       __________ .____     ___________   _____     ____________________\n"
        "       \\______   \\|    |    \\_   _____/  /  _  \\   /   _____/\\_   _____/\n"
        "        |     ___/|    |     |    __)_  /  /_\\  \\  \\_____  \\  |    __)_\n"
        "        |    |    |    |___  |        \\/    |    \\ /        \\ |        \\\n"
        "        |____|    |_______ \\/_______  /\\____|__  //_______  //_______  /\n"
        "                          \\/        \\/         \\/         \\/         \\/\n"
        "--------------------------------------------------------------------------------------");
    printf("Write down your passphrase: ");
    scanf("%s", s);
    if (*s == 68
        && s[1] == 65
        && s[2] == 83
        && s[3] == 67
        && s[4] == 84
        && s[5] == 70
        && s[6] == 123
        && s[strlen(s) - 1] == 125                  // DSCTF{}
        && !(unsigned int)subfhsadkhjbfleiowiuoyfgshjdvbsmnakl(
            (__int64)s,
            (__int64)"DASCTF{5c715207e3abed7dfb7c8ea9c82d0e29}"))
    {
        puts("Your passphrase is valid! Welcome.");
    }
    else
    {
        puts("Oops, your passphrase is invalid.\nBetter luck next time :)");
    }
    free(s);
    return 0;
}