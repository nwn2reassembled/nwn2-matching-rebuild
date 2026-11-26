void CopyBytes(char* dest, const char* end, const char* src)
{
    if (dest != end) {
        do {
            *dest = *src;
            ++dest;
        } while (dest != end);
    }
}
