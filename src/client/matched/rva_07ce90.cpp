struct Obj {
    unsigned char flag;
    unsigned char pad0[0x2F];
    int field30;
    unsigned char pad1[0x34];
    int field68;

    int GetValue();
};

int Obj::GetValue() {
    if (flag != 0)
        return field30;
    return field68;
}
