void StatBlock_SetPair(void *block, unsigned int a, unsigned int b) {
    *(unsigned int *)((char *)block + 0xeb) = a;
    *(unsigned int *)((char *)block + 0xef) = b;
}
