struct Legacy
{
    unsigned int dummy;      // offset 0x0 – unused placeholder
    unsigned int* ptr;       // offset 0x4 – pointer loaded by mov eax,[ecx+0x4]
    unsigned int getValue() const;
};

unsigned int Legacy::getValue() const
{
    return *reinterpret_cast<unsigned int*>( reinterpret_cast<char*>(ptr) + 0x10070 );
}

