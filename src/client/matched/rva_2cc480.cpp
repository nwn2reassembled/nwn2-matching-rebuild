struct Legacy {
    int dummy;          // offset 0
    void* ptr;          // offset 4 – the pointer to be written through
    void setField(int value);
};

void Legacy::setField(int value)
{
    // Write the supplied integer into the structure pointed to by ptr,
    // at an offset of 0x348 bytes.
    *((int*)((char*)ptr + 0x348)) = value;
}

