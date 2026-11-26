struct C
{
    unsigned char padding[0x628];
    unsigned char m_base;
    unsigned char m_step;

    bool Func(unsigned char value);
};

bool C::Func(unsigned char value)
{
    unsigned char base = m_base;
    bool result = false;

    if (base > 0 && value >= base)
    {
        if ((value - base) % m_step == 0)
            result = true;
    }

    return result;
}
