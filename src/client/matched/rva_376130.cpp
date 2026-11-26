struct Holder
{
    unsigned char pad0[0xec];
    unsigned short m_ec;
    unsigned short m_ee;

    unsigned short Get(int flag) const;
};

unsigned short Holder::Get(int flag) const
{
    if (flag != 0)
        return m_ee;
    return static_cast<unsigned short>(m_ee + m_ec);
}
