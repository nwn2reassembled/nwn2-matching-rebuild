unsigned __fastcall reverse_bits(unsigned value, int count)
{
    unsigned result = 0;
    do
    {
        result |= value & 1;
        value >>= 1;
        count--;
        result <<= 1;
    } while (count > 0);
    return result >> 1;
}
