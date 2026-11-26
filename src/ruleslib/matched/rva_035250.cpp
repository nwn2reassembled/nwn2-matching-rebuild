struct ThreeByteSlot
{
    unsigned char reserved[0x20];
    unsigned char values[3];
};

void __stdcall StoreThreeByteValue(ThreeByteSlot* slot, unsigned char index, unsigned char value)
{
    if (index < 3)
    {
        slot->values[index] = value;
    }
}
