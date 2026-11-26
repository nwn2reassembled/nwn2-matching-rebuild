class Obj {
public:
    int Get(int index);
};

int Obj::Get(int index) {
    if (index == 0)
        return *(int*)((char*)this + 0x8);
    if (index == 1)
        return *(int*)((char*)this + 0xC);
    return 0;
}
