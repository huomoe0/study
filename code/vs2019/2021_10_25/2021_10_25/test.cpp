#define _CRT_SECURE_NO_WARNINGS 1
#include <cstdio>
#include <string>
#include <cstdlib>


__int64 __cdecl main()
{
    std::__cxx11::string s; // [rsp+20h] [rbp-60h]
    char v2; // [rsp+4Fh] [rbp-31h]
    std::__cxx11::string v3; // [rsp+50h] [rbp-30h]

    _main();
    std::allocator<char>::allocator(&v2);
    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::basic_string(&s, "IAMFLAG", &v2);
    std::allocator<char>::~allocator(&v2);
    change(&v3, &s);
    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string(&v3);
    std::operator<<<char, std::char_traits<char>, std::allocator<char>>(refptr__ZSt4cout, &s);
    system("pause");
    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string(&s);
    return 0i64;
}


std::__cxx11::string* __cdecl change(std::__cxx11::string* retstr, std::__cxx11::string* s)
{
    _BYTE* v2; // rax
    _BYTE* v3; // rax
    int i; // [rsp+2Ch] [rbp-4h]
    std::__cxx11::string* v6; // [rsp+40h] [rbp+10h]
    std::__cxx11::string* sa; // [rsp+48h] [rbp+18h]
    v6 = retstr;
    sa = s;
    for (i = 0; i < 32; ++i)
    {
        v2 = (_BYTE*)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::operator[](sa, i);
        *v2 += 25;
        v3 = (_BYTE*)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::operator[](sa, i);
        *v3 = (unsigned __int8)*v3 % 128;
    }
    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::basic_string(v6, sa);
    return v6;
}