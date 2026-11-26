bool ValidateOption(unsigned char option, int enabled)
{
    if (enabled != 0)
    {
        unsigned char diff = option - 5;
        if (diff <= 1)
            return true;
    }
    else
    {
        unsigned char diff2 = option - 8;
        if (diff2 == 0)
            return true;
    }
    return false;
}
