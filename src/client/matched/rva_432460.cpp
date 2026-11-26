struct Widget {
    char padding[0x64];
    unsigned int m_a;
    unsigned int m_b;
    unsigned int m_c;
    int Check();
};

int Widget::Check()
{
    return m_a == 0 || m_b > m_c;
}
