struct Legacy {
    void update(void* base, unsigned char idx, unsigned char val);
};

void Legacy::update(void* base, unsigned char idx, unsigned char val) {
    *(reinterpret_cast<unsigned char*>(base) + 10 + idx) = val;
}

