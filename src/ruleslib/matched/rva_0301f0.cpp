class Legacy {
public:
    static void __stdcall SetByte(void* ptr, unsigned char val);
};

void Legacy::SetByte(void* ptr, unsigned char val)
{
    *((unsigned char*)ptr + 0x61) = val;
}

