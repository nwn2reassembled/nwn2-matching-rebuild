class Legacy {
public:
    unsigned char func(unsigned int idx, const unsigned char* ptr);
};

unsigned char Legacy::func(unsigned int idx, const unsigned char* ptr)
{
    return *reinterpret_cast<const unsigned char*>( reinterpret_cast<unsigned int>(ptr) + idx + 8 );
}

