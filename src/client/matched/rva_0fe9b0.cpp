struct Owner
{
    unsigned char pad_0x0[0x1D8];
    void* slots[39];

    void __thiscall SetFieldA4(void* value);
};

void Owner::SetFieldA4(void* value)
{
    void** p = slots + 1;
    int i = 13;
    do
    {
        void* a = p[-1];
        if (a != 0)
            *reinterpret_cast<void**>(reinterpret_cast<char*>(a) + 0xA4) = value;
        void* b = p[0];
        if (b != 0)
            *reinterpret_cast<void**>(reinterpret_cast<char*>(b) + 0xA4) = value;
        void* c = p[1];
        if (c != 0)
            *reinterpret_cast<void**>(reinterpret_cast<char*>(c) + 0xA4) = value;
        p += 3;
        --i;
    } while (i != 0);
}
