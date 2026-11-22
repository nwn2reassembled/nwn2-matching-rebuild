struct Legacy {
    unsigned short getValue(void* ptr);
};

unsigned short Legacy::getValue(void* ptr) {
    return *reinterpret_cast<unsigned short*>( reinterpret_cast<char*>(ptr)+0x10 );
}

