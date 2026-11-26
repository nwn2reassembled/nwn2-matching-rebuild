struct Data { int v[8]; };

struct Block {
    int data[8];
    unsigned char flag;
    void CopyTo(Block* dest) const;
};

void Block::CopyTo(Block* dest) const
{
    *(Data*)dest->data = *(const Data*)data;
    dest->flag = 0;
}
