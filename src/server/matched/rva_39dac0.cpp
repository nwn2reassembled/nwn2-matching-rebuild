struct Obj {
    char pad[0x14];
    unsigned short field14;
};

int IsField14Zero(Obj* obj) {
    return obj->field14 == 0;
}
