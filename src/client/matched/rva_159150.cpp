class Foo {
public:
    int GetByBit(int flag);
    unsigned char pad0[0x1F8];
    int values[13];
};

int Foo::GetByBit(int flag) {
    for (int i = 0; i < 13; ++i) {
        if ((1 << i) == flag)
            return values[i];
    }
    return 0;
}
