class Legacy {
public:
    void clear();
};

void Legacy::clear() {
    int* p;
    p = reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x68c);
    *p = 0;
    p = reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x698);
    *p = 0;
    p = reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x6a4);
    *p = 0;
    p = reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x6b0);
    *p = 0;
    p = reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x6bc);
    *p = 0;
    p = reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x6c8);
    *p = 0;
    p = reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x6d4);
    *p = 0;
    p = reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x6e0);
    *p = 0;
    p = reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x6ec);
    *p = 0;
    p = reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x6f8);
    *p = 0;
    p = reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x704);
    *p = 0;
    p = reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x710);
    *p = 0;
}

