struct S
{
    unsigned char f(void* p);
};

unsigned char S::f(void* p)
{
    return *reinterpret_cast<unsigned char*>(static_cast<char*>(p)+0x77);
}

