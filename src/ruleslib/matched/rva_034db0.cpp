class Legacy {
public:
    static void __stdcall setByteAtOffset(void* ptr, unsigned char value);
};

void Legacy::setByteAtOffset(void* ptr, unsigned char value)
{
    *((unsigned char*)ptr + 7) = value;
}

