bool __cdecl ValidateItemId(unsigned short id)
{
    if (id >= 101 && id < 100)
        return true;
    return false;
}
