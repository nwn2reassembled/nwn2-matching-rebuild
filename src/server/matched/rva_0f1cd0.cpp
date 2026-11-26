int GetServerValue()
{
    int* p = *(int**)0x0086CC48;
    if (p != 0)
        return p[2];
    return 0;
}
