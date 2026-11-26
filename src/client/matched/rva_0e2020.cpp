struct Record
{
    char pad[0x16];
    short value;
};

class Gauge
{
public:
    char pad0[0x200];
    Record **records;
    int count;
    char pad1[0x10];
    int position;
    int low;
    int extent;
    char pad2[0x0C];
    unsigned int state;

    bool IsWithinRange();
};

bool Gauge::IsWithinRange()
{
    int n = count;
    if (state & 0x10)
    {
        int span = extent - low;
        int margin = 0;
        Record **table = records;
        if (n > 0)
        {
            Record *last = table[n - 1];
            if (last != 0)
                margin = last->value;
        }
        bool result = false;
        if (position <= span + margin)
        {
            if (position >= span - margin)
                result = true;
        }
        return result;
    }

    int diff = n - low;
    return diff == position;
}
