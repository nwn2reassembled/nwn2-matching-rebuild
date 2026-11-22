class Legacy {
public:
    int legacyFunc();
};

int Legacy::legacyFunc() {
    int* ptr = *(int**)((char*)this + 4);
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(ptr) + 0x60);
}

