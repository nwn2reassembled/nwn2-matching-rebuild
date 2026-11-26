struct Widget
{
    unsigned char m_padding[0xE0];
    unsigned char m_flag;
};

struct Holder
{
    Widget* m_widget;
    void Clear();
};

void Holder::Clear()
{
    if (m_widget != 0)
    {
        m_widget->m_flag = 0;
    }
}
