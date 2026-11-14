
struct Legacy {
    void setField(unsigned int* p, unsigned short value);
};

void Legacy::setField(unsigned int* p, unsigned short value)
{
    *(unsigned short*)((char*)p + 0x5e) = value;
}

