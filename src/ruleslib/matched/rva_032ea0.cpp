struct Legacy {
    static void __stdcall setByte(void* ptr, unsigned char val);
};

void Legacy::setByte(void* ptr, unsigned char val)
{
    // Store the byte value at offset +4 of the supplied pointer.
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(ptr) + 4) = val;
}

