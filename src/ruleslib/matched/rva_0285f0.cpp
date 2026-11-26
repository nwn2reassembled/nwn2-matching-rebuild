// 6 bytes: mov eax, 0x125 ; ret  (no stack cleanup, plain retn)
unsigned int __cdecl GetSomething()
{
    return 0x125u; // 293
}
