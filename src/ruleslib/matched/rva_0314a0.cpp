struct Legacy
{
    static void __stdcall WriteByte(unsigned char* ptr, unsigned char val);
};

void Legacy::WriteByte(unsigned char* ptr, unsigned char val)
{
    ptr[0x5f4] = val;
}

