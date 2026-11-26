struct Object
{
    char pad0[0x744];
    int field744;
    char pad1[0x7D0 - 0x748];
    int field7D0;

    int SetBoth(int value);
};

int Object::SetBoth(int value)
{
    field744 = value;
    field7D0 = value;
    return value;
}
