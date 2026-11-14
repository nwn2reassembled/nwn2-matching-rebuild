struct Legacy {
    int getField(const void* ptr);
};

int Legacy::getField(const void* ptr) {
    return *reinterpret_cast<const int*>(static_cast<const char*>(ptr)+0x234);
}
