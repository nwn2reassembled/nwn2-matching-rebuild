struct Legacy
{
    unsigned long compute(unsigned long val);
};

unsigned long Legacy::compute(unsigned long val)
{
    return (val << 5) + reinterpret_cast<unsigned long>(this);
}
