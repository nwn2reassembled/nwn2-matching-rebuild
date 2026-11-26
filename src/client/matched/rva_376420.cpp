struct Obj {
    unsigned char pad[0xDD];
    unsigned char b[7];

    void SetSlot(int index, unsigned char value);
};

void Obj::SetSlot(int index, unsigned char value) {
    if ((unsigned int)index <= 6) {
        b[index] = value;
    }
}
