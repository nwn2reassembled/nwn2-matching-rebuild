struct Container
{
    char reserved[0x2368];
    int count;
    void* object;

    void Update(int delta, void* value);
};

void Container::Update(int delta, void* value)
{
    if (value != 0)
    {
        count = 0;
        object = value;
    }
    else if (count > 0)
    {
        count += delta;
    }
    else
    {
        count = delta;
    }
}
