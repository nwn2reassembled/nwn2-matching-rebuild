class C
{
public:
    int Clear();
private:
    char m_pad0[0x8c8];
    int m_entries[0x27];
    char m_pad1[0xa4];
    int m_state;
};

int C::Clear()
{
    int i;
    for (i = 0; i < 0x27; ++i)
        m_entries[i] = 0;
    m_state = 0;
    return 0;
}
