struct Holder
{
    char reserved[0x14];
    int first;
    int second;

    void read_into(int* out_first, int* out_second);
};

void Holder::read_into(int* out_first, int* out_second)
{
    *out_first = first;
    *out_second = second;
}
