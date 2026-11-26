void __cdecl SetResourcePair(unsigned char* obj, unsigned int a, unsigned int b)
{
    *reinterpret_cast<unsigned int*>(obj + 0xEB) = a;
    *reinterpret_cast<unsigned int*>(obj + 0xEF) = b;
}
