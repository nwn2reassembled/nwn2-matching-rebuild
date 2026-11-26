struct CharBuffer
{
    char* m_data;
    unsigned int m_reserved;
    unsigned int m_size;

    char Get(unsigned int index) const;
};

char CharBuffer::Get(unsigned int index) const
{
    if (m_size > index)
        return m_data[index];
    return 0;
}
