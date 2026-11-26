struct Block
{
    unsigned int values[8];
};

class Container
{
    unsigned char reserved[0x35c];
    Block block;

public:
    Block* CopyBlock(Block* out);
};

Block* Container::CopyBlock(Block* out)
{
    *out = block;
    return out;
}
