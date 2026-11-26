int ServerGetTrailingRunIndex(const char *s, int len, char ch)
{
    int i = len;
    if (len > 0) {
        while (i > 0) {
            if (s[i - 1] != ch)
                return len - i;
            --i;
        }
    }
    return len;
}
