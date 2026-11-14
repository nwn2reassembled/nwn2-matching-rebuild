class Legacy {
public:
    static void __stdcall func(unsigned int offset, unsigned char index, unsigned char value);
};

void Legacy::func(unsigned int offset, unsigned char index, unsigned char value) {
    *reinterpret_cast<unsigned char*>(0x5c4 + offset + index) = value;
}

