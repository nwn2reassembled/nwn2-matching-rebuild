struct Entry
{
    char pad0[0x108];
    int value;
};

struct Global
{
    char pad0[0x30];
    Entry** entries;
};

class CObject
{
public:
    int GetEntryValue();
private:
    char pad0[0x20];
    unsigned int index;
};

int CObject::GetEntryValue()
{
    return (*(Global**)0x86ac78)->entries[index & 0xffff]->value;
}
