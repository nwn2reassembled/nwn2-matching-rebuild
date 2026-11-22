struct Legacy
{
    int compute(int);
};

int Legacy::compute(int value)
{
    return (value << 5) + reinterpret_cast<unsigned>(this) + 0x18f;
}
