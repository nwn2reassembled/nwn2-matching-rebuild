struct Legacy {
    void setByte(void* ptr, unsigned char val);
};

void Legacy::setByte(void* ptr, unsigned char val)
{
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(ptr)+0x10) = val;
}

