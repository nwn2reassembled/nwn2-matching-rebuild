class Legacy {
public:
    void writeWord(unsigned int* ptr, unsigned short value);
};

void Legacy::writeWord(unsigned int* ptr, unsigned short value) {
    *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(ptr)+0xe) = value;
}

