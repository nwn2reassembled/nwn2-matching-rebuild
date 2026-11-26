class MessageQueue {
public:
    bool Push(unsigned int value);

    unsigned int pad[0x64];   // 0x000 .. 0x18F
    int count;                // 0x190
    unsigned int slots[128];  // 0x194
};

bool MessageQueue::Push(unsigned int value)
{
    slots[count] = value;
    count = count + 1;
    return count < 128;
}
