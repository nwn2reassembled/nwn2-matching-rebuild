struct Legacy{ unsigned int compute(void* ptr, unsigned short idx); };

unsigned int Legacy::compute(void* ptr, unsigned short idx){
    unsigned char* p = (unsigned char*)ptr + 0x180;
    unsigned int base = *(unsigned int*)p;
    return base + ((idx * 7u) << 2);
}
