struct Legacy {
    int dummy;
    void* ptr;

    unsigned int func();
};

unsigned int Legacy::func() {
    return *reinterpret_cast<unsigned int*>( reinterpret_cast<char*>(ptr) + 0x10020 );
}
