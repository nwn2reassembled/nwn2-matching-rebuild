struct Buffer
{
    unsigned char reserved[0x88];
    unsigned char values[10];

    void SetValue(unsigned char index, unsigned char value);
};

void Buffer::SetValue(unsigned char index, unsigned char value)
{
    if (index < 10)
        values[index] = value;
}
