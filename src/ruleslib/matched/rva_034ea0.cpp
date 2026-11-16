struct Legacy {
    void writeByte(void* ptr, unsigned char value);
};

void Legacy::writeByte(void* ptr, unsigned char value) {
    static_cast<unsigned char*>(ptr)[1] = value;
}

