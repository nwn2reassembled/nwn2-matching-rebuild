struct CObject
{
    unsigned char reserved[0xde5];
    unsigned char flags;

    int Check() const;
};

int CObject::Check() const
{
    if (flags & 0x4)
        return 0;

    return (flags & 0x10) || ((flags & 0x8) && !(flags & 0x2));
}
