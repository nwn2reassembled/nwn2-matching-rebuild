struct Legacy {
    void update(unsigned int value);
};

void Legacy::update(unsigned int value) {
    unsigned int* ptr = *reinterpret_cast<unsigned int**>(reinterpret_cast<char*>(this)+4);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(ptr)+0x100ec) = value;
}

