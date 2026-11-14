class Legacy {
public:
    unsigned char getByte(const void* ptr) const;
};

unsigned char Legacy::getByte(const void* ptr) const
{
    const unsigned char* p = static_cast<const unsigned char*>(ptr);
    return p[41];
}
