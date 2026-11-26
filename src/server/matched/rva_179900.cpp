struct CObject
{
    unsigned char reserved0[0x4c];
    int limit;
    unsigned char reserved1[4];
    unsigned char value;

    void SetValue(int n);
};

void CObject::SetValue(int n)
{
    if (limit < n)
        value = (unsigned char)n;
}
