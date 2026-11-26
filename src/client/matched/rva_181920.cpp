class CObjectFlags
{
public:
    int IsUsable() const;

private:
    unsigned char m_reserved[0xDE5];
    unsigned char m_flags;
};

int CObjectFlags::IsUsable() const
{
    unsigned char flags = m_flags;

    if (flags & 0x04)
        return 0;

    if (!(flags & 0x10))
    {
        if (!(flags & 0x08))
            return 0;

        if (flags & 0x02)
            return 0;
    }

    return 1;
}
