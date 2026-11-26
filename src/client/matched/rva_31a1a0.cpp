struct CItem
{
    char pad[0x6c];
    int value;
};

struct COuter
{
    char pad0[0xcc];
    CItem** items;
    char pad1[0x4];
    int count;

    int GetItemValue(int index);
};

int COuter::GetItemValue(int index)
{
    if (index < 0 || index >= count)
        return 0;

    return items[index]->value;
}
