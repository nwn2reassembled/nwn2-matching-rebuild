class Legacy {
public:
    void writeValue(unsigned char* ptr, unsigned short value);
};

void Legacy::writeValue(unsigned char* ptr, unsigned short value) {
    *(unsigned short*)(ptr + 0x6E) = value;
}

