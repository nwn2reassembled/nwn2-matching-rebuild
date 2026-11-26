struct Obj {
    unsigned char pad0[0x3B0];
    int field3B0;
    unsigned char pad1[0x538 - 0x3B4];
    int field538;
    int IsReady();
};

int Obj::IsReady() {
    if (this->field538 != 0 && this->field3B0 != 0)
        return 1;
    return 0;
}
