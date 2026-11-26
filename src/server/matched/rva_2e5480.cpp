struct Buffer
{
    unsigned int m_Count;
    unsigned int m_Reserved;
    const unsigned char* m_Begin;
    const unsigned char* m_End;

    int IsFull() const;
};

int Buffer::IsFull() const
{
    unsigned int available;
    if (m_Begin == 0)
    {
        available = 0;
    }
    else
    {
        available = static_cast<unsigned int>(m_End - m_Begin);
    }
    return m_Count >= available;
}
