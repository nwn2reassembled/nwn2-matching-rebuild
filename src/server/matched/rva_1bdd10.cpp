struct Inner
{
    char pad0[0x622];
    unsigned short value;
};

struct Item
{
    char pad0[8];
    int value;
};

class Big
{
public:
    bool Check();

private:
    char pad0[0x1a0];
    Item** items;
    int count;
    char pad1[0x1e1c];
    Inner* inner;
};

bool Big::Check()
{
    if (count > 0)
    {
        int idx = inner->value;
        if (idx < count)
        {
            if (items[idx]->value == *(int*)0x805dd4)
                return true;
        }
    }
    return false;
}
