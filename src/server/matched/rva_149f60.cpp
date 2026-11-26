struct Legacy {
    int dummy;
    void* ptr;
    unsigned long getValue() const;
};

unsigned long Legacy::getValue() const
{
    return *reinterpret_cast<const unsigned long*>(
        reinterpret_cast<const char*>(ptr) + 0x100b4);
}

