struct CHolder
{
    int m_pad[8];
    int* m_items;
};

class CIndexed
{
public:
    int Get();

private:
    int m_pad[33];
    int m_index;
};

int CIndexed::Get()
{
    if (m_index < 0)
        return 0;

    return (*(CHolder**)0x86ac80)->m_items[m_index];
}
