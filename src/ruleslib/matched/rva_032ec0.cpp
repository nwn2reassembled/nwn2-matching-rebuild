class Legacy {
public:
    unsigned char readByte(const void* p);
};

unsigned char Legacy::readByte(const void* p)
{
    const unsigned char* q = static_cast<const unsigned char*>(p);
    return q[9];
}

