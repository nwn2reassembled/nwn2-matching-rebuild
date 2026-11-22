struct Legacy
{
    char padding[0x10470];
    short value;
    short getValue();
};

short Legacy::getValue()
{
    return value;
}

