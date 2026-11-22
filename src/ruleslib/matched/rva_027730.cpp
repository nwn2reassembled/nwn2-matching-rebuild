struct Legacy {
    int getField(void*);
};

int Legacy::getField(void* p) {
    return *reinterpret_cast<int*>(static_cast<char*>(p)+0x32c);
}

