struct Legacy
{
    static void __stdcall setValue(void* ptr, unsigned int val);
};

void Legacy::setValue(void* ptr, unsigned int val)
{
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(ptr) + 0x34u) = val;
}

