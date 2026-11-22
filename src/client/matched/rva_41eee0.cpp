class Legacy {
public:
    void store(int);
};

void Legacy::store(int value) {
    *((int*)((char*)this - 0x14)) = value;
}

