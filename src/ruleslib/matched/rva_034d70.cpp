struct Legacy
{
    void store_byte(void* dst, unsigned char value);
};

void Legacy::store_byte(void* dst, unsigned char value)
{
    *reinterpret_cast<unsigned char*>(dst) = value;
}

