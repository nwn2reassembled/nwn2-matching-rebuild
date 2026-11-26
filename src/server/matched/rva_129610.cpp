int AddByteToBuffer(unsigned char *buffer, unsigned int value)
{
    if (*(int *)(buffer + 0x100) >= 0xFE || value - 1 > 0xFDu)
        return 0;
    int count = *(int *)(buffer + 0x100);
    buffer[count] = (unsigned char)value;
    (*(int *)(buffer + 0x100))++;
    return 1;
}
