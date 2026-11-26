unsigned char __stdcall MapClassToSlot(unsigned char cls)
{
    unsigned char result = 0;

    if (cls == 4)
        result = 1;
    else if (cls == 5)
        result = 2;
    else if (cls == 7)
        result = 3;
    else if (cls == 8)
        result = 4;
    else if (cls == 11)
        result = 5;
    else if (cls == 6)
        result = 8;
    else if (cls == 9)
        result = cls;

    return result;
}
