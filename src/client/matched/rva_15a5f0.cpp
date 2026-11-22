struct Legacy {
    int modify(int val);
};

int Legacy::modify(int val) {
    short tmp = *(short*)((char*)this + 0x164);
    int res = (int)tmp - val;
    *(int*)((char*)this + 0x164) = res;
    return res;
}
