struct RingBuffer {
    int header[11];
    unsigned char data[20];
    int count;

    void __cdecl push(unsigned char value);
};

void RingBuffer::push(unsigned char value)
{
    if (count < 20) {
        data[count] = value;
        count = count + 1;
    }
}
