struct Legacy {
    int readOffset(void* ptr);
};

int Legacy::readOffset(void* ptr) {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(ptr)+0x600);
}

