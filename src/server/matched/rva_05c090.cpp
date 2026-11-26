struct CFields
{
    unsigned char reserved[0x28];
    int first;
    int second;

    int StorePair(int a, int b);
};

int CFields::StorePair(int a, int b)
{
    first = a;
    second = b;
    return 0;
}
