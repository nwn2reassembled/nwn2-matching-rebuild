struct UString16
{
    unsigned short* m_data;
    int m_reserved;
    int m_length;

    bool Equals(const UString16& other) const;
};

bool UString16::Equals(const UString16& other) const
{
    if (m_length != other.m_length)
        return false;

    for (int i = 0; i < m_length; ++i)
    {
        if (m_data[i] != other.m_data[i])
            return false;
    }

    return true;
}
