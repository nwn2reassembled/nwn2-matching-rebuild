struct CFlagHolder
{
    unsigned char gap[0x290];
    unsigned int flags;
    bool HasFlags() const;
};

bool CFlagHolder::HasFlags() const
{
    if (flags)
        return true;
    return false;
}
