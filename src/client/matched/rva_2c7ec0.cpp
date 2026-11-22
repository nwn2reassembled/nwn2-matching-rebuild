struct Legacy {
    void* data;
    void update(unsigned int* src, unsigned short val);
};

void Legacy::update(unsigned int* src, unsigned short val) {
    char* base = reinterpret_cast<char*>(data);
    *reinterpret_cast<unsigned int*>(base + 0x1390) = *src;
    *reinterpret_cast<unsigned short*>(base + 0x139c) = val;
}

