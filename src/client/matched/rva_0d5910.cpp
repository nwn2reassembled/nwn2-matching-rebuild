class CItemArray {
public:
    int GetAt(int index);
private:
    char m_padding[0x190];
    int* m_pData;
    int m_nCount;
};

int CItemArray::GetAt(int index) {
    if (index <= m_nCount && index >= 0)
        return m_pData[index];
    return 0;
}
