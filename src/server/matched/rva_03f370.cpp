struct DataBlock {
    unsigned int handle;
    unsigned int field_4;
    unsigned int field_8;
    unsigned int count;
    unsigned int state;
};

unsigned int __cdecl GetHandleIfComplete(DataBlock* block) {
    if (block == 0)
        return 0;
    if (block->count == 0)
        return 0;
    if (block->state != 100)
        return 0;
    return block->handle;
}
