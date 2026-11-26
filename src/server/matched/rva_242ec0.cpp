struct CounterHolder
{
    char padding[0x2368];
    int value;

    void Subtract(int amount);
};

void CounterHolder::Subtract(int amount)
{
    value -= amount;
    if (value < 0)
    {
        value = 0;
    }
}
