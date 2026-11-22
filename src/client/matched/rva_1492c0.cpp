class Legacy {
public:
    int func();
};

int Legacy::func() {
    int* p = *(int**)((char*)this + 4);
    return (*((int*)((char*)p + 0x10190)) != 0);
}

