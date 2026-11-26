struct Obj {
    unsigned char pad[0x24];
    unsigned int f24;
    unsigned char pad_28[4];
    unsigned int f2c;
    unsigned int f30;
    unsigned char pad_34[0x14];
    unsigned int f48;
    unsigned int f4c;
    unsigned int f50;
    unsigned char pad_54[4];
    unsigned int f58;
};

void ResetFields(Obj* obj)
{
    obj->f24 = 0;
    obj->f4c = 1;
    obj->f48 = 0;
    obj->f58 = 0;
    obj->f2c = 0;
    obj->f30 = 0;
    obj->f50 = 1;
}
