class Legacy {
public:
    void legacy_func(void* base, unsigned int offset, unsigned char value);
};

void Legacy::legacy_func(void* base, unsigned int offset, unsigned char value)
{
    static_cast<unsigned char*>(base)[offset + 4] = value;
}

