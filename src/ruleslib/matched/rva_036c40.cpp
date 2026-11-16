class LegacyClass {
public:
    static void __stdcall WriteWord(void* ptr, unsigned short val);
};

void LegacyClass::WriteWord(void* ptr, unsigned short val) {
    *(unsigned short*)((char*)ptr + 0xA) = val;
}

