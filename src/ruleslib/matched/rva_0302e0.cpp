class Legacy {
public:
    static void __stdcall setByte(void* objPtr, unsigned char value);
};

void Legacy::setByte(void* objPtr, unsigned char value) {
    *reinterpret_cast<unsigned char*>(static_cast<char*>(objPtr)+0x7C) = value;
}

