void CopyValues(int* dest, const int* end, const int* src)
{
    if (dest != end)
    {
        do
        {
            *dest = *src;
            ++dest;
        } while (dest != end);
    }
}
