struct Block
{
    int value[8];
};

class Container
{
public:
    unsigned char padding[0xE4];
    Block block;

    void* Copy(void* dest);
};

void* Container::Copy(void* dest)
{
    *(Block*)dest = block;
    return dest;
}
