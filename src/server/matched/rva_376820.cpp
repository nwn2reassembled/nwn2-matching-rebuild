struct CIndexLookup
{
    unsigned char m_pad[0x28];
    unsigned short m_values[10];
    char Find(unsigned short value);
};

char CIndexLookup::Find(unsigned short value)
{
    if (value != 0xFFFF)
    {
        for (unsigned char i = 0; i < 10; ++i)
        {
            if (m_values[i] == value)
                return i;
        }
    }
    return -1;
}
