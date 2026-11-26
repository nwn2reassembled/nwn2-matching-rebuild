struct Widget {
    unsigned char m_data[10000];

    void __thiscall SetEntry(unsigned char a, unsigned char b, unsigned char c);
};

void __thiscall Widget::SetEntry(unsigned char a, unsigned char b, unsigned char c)
{
    if (a < 4 && b < 10) {
        m_data[b + a * 10 + 0x63C] = c;
    }
}
