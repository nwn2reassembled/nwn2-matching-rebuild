struct Block
{
    int values[8];
};

struct Holder
{
    char prefix[0xD0];
    Block block;

    void assign(const Block& src);
};

void Holder::assign(const Block& src)
{
    block = src;
}
