class CValueGrid
{
public:
    void Find(int value, unsigned char* column, unsigned char* row);

private:
    char m_pad0[0x204];
    int m_rows;
    int m_cols;
    char m_pad1[8];
    int* m_data;
};

void CValueGrid::Find(int value, unsigned char* column, unsigned char* row)
{
    for (int r = 0; r < m_rows; ++r)
    {
        for (int c = 0; c < m_cols; ++c)
        {
            if (value == m_data[r * m_cols + c])
            {
                *column = (unsigned char)c;
                *row = (unsigned char)r;
                return;
            }
        }
    }
}
