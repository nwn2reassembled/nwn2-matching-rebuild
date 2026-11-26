struct MessageQueue {
    char head[0x2C];
    char data[20];
    int count;

    void __cdecl Append(char value);
};

void __cdecl MessageQueue::Append(char value)
{
    if (count < 20) {
        data[count] = value;
        count = count + 1;
    }
}
