class Legacy {
public:
    unsigned int getValue(char* ptr);
};

unsigned int Legacy::getValue(char* ptr) {
    return *(unsigned int*)(ptr + 0x274);
}

