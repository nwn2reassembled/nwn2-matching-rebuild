class IntVector
{
public:
    int Get(int index) const;

private:
    char m_reserved[0x200];
    int* m_pData;
    int m_nCount;
};

int IntVector::Get(int index) const
{
    if (index < 0 || index >= m_nCount)
        return 0;

    return m_pData[index];
}
