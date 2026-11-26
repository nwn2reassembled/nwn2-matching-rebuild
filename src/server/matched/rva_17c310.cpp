struct Legacy {
    char pad[0x164];
    void adjust(int);
};

void Legacy::adjust(int param) {
    short s = *reinterpret_cast<short*>(reinterpret_cast<char*>(this)+0x164);
    int result = static_cast<int>(s) - param;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this)+0x164) = result;
}

