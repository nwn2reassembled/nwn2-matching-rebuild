void __stdcall WriteWordIfNotNull(unsigned short* target, unsigned short value)
{
    if (target != 0)
    {
        *target = value;
    }
}
