struct Holder
{
    char unknown[0x24];
    void* value;
    bool SetValue(void* p);
};

bool Holder::SetValue(void* p)
{
    if (!p)
    {
        return false;
    }

    if (!value)
    {
        value = p;
    }

    return true;
}
