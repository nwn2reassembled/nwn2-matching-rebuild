class CTextBuffer
{
public:
    int IsInvalid() const;

private:
    char* m_data;
};

int CTextBuffer::IsInvalid() const
{
    return m_data == 0 || *m_data == 0;
}
