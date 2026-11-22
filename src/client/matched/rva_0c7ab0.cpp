struct Legacy {
    unsigned char pad[0x44];
    unsigned char byteField;
    void zeroByte();
};

void Legacy::zeroByte() { this->byteField = 0; }

