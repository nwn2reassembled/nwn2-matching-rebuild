struct Legacy
{
    char pad[0x368];
    unsigned short value;
    unsigned short getField() const;
};

unsigned short Legacy::getField() const
{
    return *reinterpret_cast<const unsigned short*>(reinterpret_cast<const char*>(this) + 0x368);
}
