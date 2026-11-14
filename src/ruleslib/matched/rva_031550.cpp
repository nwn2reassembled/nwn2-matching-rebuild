class Legacy {
public:
    static void __stdcall WriteValue(Legacy* obj, unsigned int value);
};

void __stdcall Legacy::WriteValue(Legacy* obj, unsigned int value) {
    *(unsigned int*)((char*)obj + 0x5fc) = value;
}

