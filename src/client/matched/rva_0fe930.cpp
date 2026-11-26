struct Obj {
    unsigned char pad[0x1dc];
    void* slots[38];
};

struct Target {
    unsigned char pad[0xa0];
    unsigned char flag;
};

void __fastcall Obj_SetFlagRange(Obj* obj, void* /*edx*/, unsigned char v)
{
    void** q = reinterpret_cast<void**>(reinterpret_cast<char*>(obj) + 0x1dc);
    for (int i = 0; i < 13; ++i) {
        for (int j = -1; j <= 1; ++j) {
            Target* t = static_cast<Target*>(q[j]);
            if (t)
                t->flag = v;
        }
        q += 3;
    }
}
