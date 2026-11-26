struct Container
{
    int m_padding[15];
    int* m_pData;

    int* GetRow(int row);
};

int* Container::GetRow(int row)
{
    return m_pData + row * 5;
}
