struct Legacy{ unsigned char getByte(const void* p); };

unsigned char Legacy::getByte(const void* p){
    const unsigned char* q = static_cast<const unsigned char*>(p);
    return q[0x11];
}
