struct Legacy {
    int getValue(void* p);
};

int Legacy::getValue(void* p)
{
    return *reinterpret_cast<int*>(static_cast<char*>(p) + 0x150);
}

