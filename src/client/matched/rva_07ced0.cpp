struct Obj {
    unsigned char flag;        // +0x00
    unsigned char pad0[63];
    unsigned int valueA;       // +0x40
    unsigned int pad1[13];
    unsigned int valueB;       // +0x78
};

unsigned int __fastcall Obj_GetValue(Obj *thisptr) {
    if (thisptr->flag != 0)
        return thisptr->valueA;
    return thisptr->valueB;
}
