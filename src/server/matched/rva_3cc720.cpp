struct FourBytes
{
    unsigned char first;
    unsigned char second;
    unsigned char third;
    unsigned char fourth;
};

FourBytes ReverseFour(const unsigned char* p)
{
    FourBytes result;
    result.first = p[3];
    result.second = p[2];
    result.third = p[1];
    result.fourth = p[0];
    return result;
}
