struct Entry
{
    unsigned short value;
    unsigned char rest[22];
};

struct Table
{
    unsigned char header[0x46c];
    Entry entries[1];

    unsigned short __stdcall GetValue(unsigned char index);
};

unsigned short __stdcall Table::GetValue(unsigned char index)
{
    return entries[index].value;
}
