struct Table {
    int reserved0;
    int reserved1;
    short entries[27];

    short Get(unsigned int index) const;
};

short Table::Get(unsigned int index) const
{
    if (index <= 26u)
        return entries[index];

    return (short)-1;
}
