void FillRange(char* dest, char* destEnd, const char* src)
{
    if (dest != destEnd)
    {
        do
        {
            *dest = *src;
            ++dest;
        } while (dest != destEnd);
    }
}
