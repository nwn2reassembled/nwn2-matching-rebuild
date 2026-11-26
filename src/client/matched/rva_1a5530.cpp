class C {
public:
    char pad[0xae8];
    int fieldAe8;
    int fieldAec;
    int CanDo();
};

int C::CanDo()
{
    if (fieldAe8 != 0 && fieldAec == 0)
        return 1;
    return 0;
}
