struct Legacy {
    unsigned int getValue(void *obj);
};

unsigned int Legacy::getValue(void *obj) {
    return **reinterpret_cast<unsigned int**>(reinterpret_cast<unsigned char*>(obj)+0x13c);
}
