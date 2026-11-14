class Legacy {
public:
    static int __stdcall getBit(const unsigned char* p);
};

int Legacy::getBit(const unsigned char* p)
{
    return (p[12] >> 3) & 1;
}

