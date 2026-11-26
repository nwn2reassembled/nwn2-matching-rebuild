struct TableHolder
{
    char reserved[0x1A];
    short values[13];

    int GetValue(unsigned short index) const;
};

int TableHolder::GetValue(unsigned short index) const
{
    if (index < 13)
        return values[index];

    return 0;
}
