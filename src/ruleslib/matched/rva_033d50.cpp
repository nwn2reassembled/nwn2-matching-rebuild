struct Legacy {
    int getFlag(const void* p) const;
};

int Legacy::getFlag(const void* p) const
{
    unsigned char c = *reinterpret_cast<const unsigned char*>(static_cast<const char*>(p)+0x6d0);
    return static_cast<int>(c & 1);
}

