struct Legacy {
    void setValue(unsigned int* data, unsigned int idx, unsigned short val);
};

void Legacy::setValue(unsigned int* data, unsigned int idx, unsigned short val) {
    *(unsigned short*)((char*)data + idx * 2 + 0x3e) = val;
}
