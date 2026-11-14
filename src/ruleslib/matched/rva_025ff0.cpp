struct Legacy {
    int getField(const void* ptr);
};

int Legacy::getField(const void* ptr) {
    const unsigned char* base = reinterpret_cast<const unsigned char*>(ptr);
    return *reinterpret_cast<const int*>(base + 0xf8);
}

