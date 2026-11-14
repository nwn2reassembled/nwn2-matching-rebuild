class Legacy {
public:
    static void __stdcall setValue(void* ptr, int value);
};

void Legacy::setValue(void* ptr, int value) {
    *(int*)((char*)ptr + 0x5ec) = value;
}

