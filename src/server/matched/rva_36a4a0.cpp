int __stdcall IsSelectionTypeValid(unsigned int type)
{
    if (type == 1 || type == 5 || type == 6)
        return 1;
    return 0;
}
