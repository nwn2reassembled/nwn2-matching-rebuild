struct Entry
{
    int field_00;
    int field_04;
    int field_08;
    int field_0C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
};

class Container
{
public:
    Entry* __thiscall Find(int key);

    Entry* entries_00;
    int pad_04;
    int count_08;
};

Entry* Container::Find(int key)
{
    int count = count_08;
    int index = 0;
    while (index < count)
    {
        if (entries_00[index].field_1C == key)
        {
            return &entries_00[index];
        }
        ++index;
    }
    return 0;
}
