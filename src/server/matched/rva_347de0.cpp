struct Legacy {
    char pad[0x38];
    int field1;
    int field2;
    int field3;

    int clear();
};

int Legacy::clear()
{
    field1 = 0;
    field2 = 0;
    field3 = 0;
    return 1;
}

