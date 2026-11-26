bool CheckFlag(char flag, int check)
{
    if (check)
    {
        unsigned char d = flag - 5;
        if (d <= 1)
            return true;
    }
    else
    {
        char d = flag - 8;
        if (d == 0)
            return true;
    }
    return false;
}
