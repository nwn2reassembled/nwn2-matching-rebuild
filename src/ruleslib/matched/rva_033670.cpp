struct Legacy{ unsigned char get_byte(void* p); };

unsigned char Legacy::get_byte(void* p){
    unsigned char* q = reinterpret_cast<unsigned char*>(p);
    return *(q + 0xCA);
}

