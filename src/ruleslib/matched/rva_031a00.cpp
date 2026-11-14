struct Legacy {
    void writeByte(unsigned char* ptr, unsigned char val);
};

void Legacy::writeByte(unsigned char* ptr, unsigned char val) {
    ptr[0x62c] = val;
}

