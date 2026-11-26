class Thing {
public:
    unsigned char pad[0x1AC];
    void* firstObj;
    unsigned char pad2[0x14];
    void* secondObj;
    void* GetObject(int index);
};

void* Thing::GetObject(int index) {
    if (index == 0)
        return *(void**)firstObj;
    if (index == 1)
        return *(void**)secondObj;
    return 0;
}
