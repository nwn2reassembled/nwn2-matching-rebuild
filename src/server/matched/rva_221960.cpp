class DwordList
{
public:
    unsigned long* items;
    int field_4;
    int count;

    int Contains(unsigned long value) const;
};

int DwordList::Contains(unsigned long value) const
{
    int total = count;
    int i = 0;
    if (total > 0)
    {
        unsigned long* p = items;
        do
        {
            if (*p == value)
                return 1;
            i++;
            p++;
        } while (i < total);
    }
    return 0;
}
