class Thing
{
public:
    unsigned short GetEntry(unsigned int index);

    unsigned int m_field0;
    unsigned int m_field1;
    unsigned short m_table[27];
};

unsigned short Thing::GetEntry(unsigned int index)
{
    if (index <= 26)
        return m_table[index];
    return 0xFFFF;
}
