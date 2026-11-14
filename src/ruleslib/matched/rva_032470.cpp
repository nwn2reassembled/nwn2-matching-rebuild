class Legacy {
public:
    static void __stdcall storeValue(unsigned int* dest, unsigned int value);
};

void Legacy::storeValue(unsigned int* dest, unsigned int value) { *((unsigned int*)((char*)dest + 0x20)) = value; }
