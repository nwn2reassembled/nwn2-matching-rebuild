struct Legacy {
    void setByte(void* ptr, unsigned char val);
};

void Legacy::setByte(void* ptr, unsigned char val) {
    *reinterpret_cast<unsigned char*>(static_cast<char*>(ptr)+0x77) = val;
}

