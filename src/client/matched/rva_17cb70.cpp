bool IsExcludedClass(unsigned short nClass)
{
    if (nClass == 2 || nClass == 3 || nClass == 4 || nClass == 78 ||
        nClass == 79 || nClass == 84 || nClass == 85 || nClass == 86 ||
        nClass == 87)
        return false;
    return true;
}
