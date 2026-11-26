struct Obj {
    char pad000[0x134];
    int field134;
    int field138;

    int GetSlot();
};

int Obj::GetSlot()
{
    int v = field134;
    if (v >= 28) {
        v = field138;
        if (v >= 28) {
            v = 28;
        }
    }
    return v;
}
