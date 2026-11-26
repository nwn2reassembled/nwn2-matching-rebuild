class Legacy {
public:
    unsigned char read() const;
};

unsigned char Legacy::read() const
{
    return *reinterpret_cast<const unsigned char*>(0x7fc21a);
}

