struct ByteReader
{
    unsigned char* m_data;
    int m_pad0;
    int m_pad1;
    int m_pad2;
    int m_pad3;
    int m_pad4;
    int m_pad5;
    int m_stride;
    unsigned char m_pad6[13];
    unsigned char m_flag;
    unsigned char Read(int x, int y);
};

unsigned char ByteReader::Read(int x, int y)
{
    unsigned char result = 1;
    if (m_flag == result)
    {
        unsigned char* row = m_data + m_stride * y;
        result = row[x];
    }
    return result;
}
