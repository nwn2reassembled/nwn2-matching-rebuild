struct CValueList
{
    unsigned char unknown0[0x24];
    int count;
    int* items;
    unsigned char unknown1[0x30];
    int selected;
};

int __cdecl LookupValue(CValueList* p, int value)
{
    if (p == 0)
        return 0x23;

    int* item = p->items;
    if (item == 0)
        return 0x26;

    int* end = item + p->count;
    for (; item < end; ++item)
    {
        if (*item == value)
        {
            p->selected = *item;
            return 0;
        }
    }

    return 6;
}
