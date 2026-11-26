struct Entry {
    unsigned char pad[0x88];
    unsigned long mode;      // +0x88
    unsigned char pad2[0x93 - 0x8c];
    unsigned char flag1;     // +0x93
    unsigned char flag2;     // +0x94
};

class Container {
public:
    bool HasEligible();

private:
    unsigned char pad[0x48];
    Entry** items;           // +0x48
    long count;              // +0x4c
};

bool Container::HasEligible()
{
    long n = count;
    long i = 0;

    if (n > 0)
    {
        Entry** p = items;
        do
        {
            Entry* e = *p;
            if (e->flag1 != 0 && e->flag2 != 0)
            {
                unsigned long v = e->mode;
                if (v != 3 && v != 4)
                    return true;
            }
            ++p;
        } while (++i < n);
    }
    return false;
}
