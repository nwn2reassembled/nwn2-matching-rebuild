class CWordList
{
public:
    unsigned short __thiscall Get(unsigned short index);

    char m_pad[0x28];
    unsigned short* m_pWords;
    int m_count;
};

unsigned short __thiscall CWordList::Get(unsigned short index)
{
    if (index >= m_count)
    {
        return 0xFFFF;
    }
    return m_pWords[index];
}
