struct Legacy {
    unsigned int getField(void* p);
};

unsigned int Legacy::getField(void* p) {
    return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(p)+0x21c);
}

