class Legacy {
public:
    unsigned int getField(void *ptr);
};

unsigned int Legacy::getField(void *ptr) {
    return *(unsigned int*)((char*)ptr + 0x28c);
}
