struct CResizable
{
    int SetSize(int newSize);

    int m_reserved[0x42];
    int m_maxSize;
    int m_size;
    int m_available;
};

int CResizable::SetSize(int newSize)
{
    if (newSize > m_maxSize)
        return 0;

    if (m_size > newSize)
    {
        int removed = m_size - newSize;
        if (removed > m_available)
            return 0;

        m_available -= removed;
        m_size = newSize;
        return 1;
    }
    else
    {
        m_available += newSize - m_size;
        m_size = newSize;
        return 1;
    }
}
