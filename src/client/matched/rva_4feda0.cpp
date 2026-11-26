class IndexedBuffer
{
public:
    int Get(int a, int b) const;
private:
    int m_stride;
    char m_padding[0x40];
    int* m_data;
};

int IndexedBuffer::Get(int a, int b) const
{
    int* p = m_data;
    if (!p)
        return 0;
    return p[m_stride * b + a];
}
