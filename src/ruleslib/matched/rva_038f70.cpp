struct Block {
    char pad0[0x159];
    unsigned char count;
    char pad1[0x0e];
    unsigned char* data;
};

void* __stdcall GetBlockEntry(Block* block, unsigned char index)
{
    if (index < block->count)
        return block->data + index * 0x630;
    return 0;
}
