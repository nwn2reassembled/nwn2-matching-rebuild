class Widget {
public:
    unsigned char m_reserved[0x164];
    int m_value;
    int m_other;
    int m_total;

    short GetValue(bool flag);
};

short Widget::GetValue(bool flag)
{
    if (flag)
        return (short)m_value;
    return m_total + m_value;
}
