struct Object
{
    unsigned char pad0[0xEC];
    unsigned short field_EC;
    unsigned short pad1;
    unsigned short field_F0;
    unsigned short pad2;

    unsigned short GetValue(int flag);
};

unsigned short Object::GetValue(int flag)
{
    if (flag)
        return field_F0;

    return field_F0 + field_EC;
}
