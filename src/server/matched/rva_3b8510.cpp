struct SomeObj {
    unsigned char pad[0x149];
    unsigned char flags;
};

int __cdecl SomeObj_GetValueIfFlagged(SomeObj *obj, short value)
{
    if (obj->flags & 0x05)
        return value;
    return 0;
}
