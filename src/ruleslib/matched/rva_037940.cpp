class Legacy {
public:
    static void __stdcall store(void* ptr, unsigned char value);
};

void Legacy::store(void* ptr, unsigned char value)
{
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(ptr) + 0x5e) = value;
}

