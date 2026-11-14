class Legacy {
public:
    void setByte(unsigned int* ptr, unsigned char value);
};

void Legacy::setByte(unsigned int* ptr, unsigned char value) {
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(ptr)+0x75) = value;
}

