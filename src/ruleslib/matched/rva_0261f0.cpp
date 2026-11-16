class Legacy {
public:
    static unsigned long __stdcall getValue(void* ptr);
};

unsigned long Legacy::getValue(void* ptr)
{
    return *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(ptr) + 0x1BC);
}

