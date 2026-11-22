class Legacy {
public:
    int getField(void* p);
};

int Legacy::getField(void* p) {
    return *(int*)((char*)p + 0x240);
}
