struct Legacy {
    static float __stdcall getVal(void* ptr);
};

float Legacy::getVal(void* ptr)
{
    return *reinterpret_cast<float*>(reinterpret_cast<char*>(ptr) + 0x10);
}

