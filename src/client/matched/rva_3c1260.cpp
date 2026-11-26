struct Target
{
    unsigned char pad0[0x3c];
    int valueAt3c;
    unsigned char pad1[0x04];
    int flagAt44;
    unsigned char pad2[0x2c];
    int valueAt74;

    int getValue();
};

int Target::getValue()
{
    if (flagAt44 != 0)
        return valueAt3c;
    return valueAt74 + valueAt3c;
}
