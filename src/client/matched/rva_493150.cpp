struct Thing {
    unsigned char IsReady(int /*unusedArg*/);

    unsigned long pad1[11];
    unsigned long field_2c;
    unsigned long field_30;
    unsigned long pad2;
    unsigned long field_38;
    unsigned long field_3c;
};

unsigned char __thiscall Thing::IsReady(int /*unusedArg*/)
{
    if (field_30 > field_2c)
        return 1;
    return field_3c > field_38;
}
