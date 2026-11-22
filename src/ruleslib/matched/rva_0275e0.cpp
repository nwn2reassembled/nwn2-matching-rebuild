struct Legacy {
    unsigned char foo(void* ptr);
};

unsigned char Legacy::foo(void* ptr) {
    return *reinterpret_cast<unsigned char*>(static_cast<char*>(ptr)+0x5a);
}

