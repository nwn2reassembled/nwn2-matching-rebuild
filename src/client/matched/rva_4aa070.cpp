char __stdcall classify(signed char value)
{
    if (value < 14)
        return 1;

    char result = value >= 16;
    result += 2;
    return result;
}
