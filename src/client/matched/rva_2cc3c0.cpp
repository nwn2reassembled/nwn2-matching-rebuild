struct Inner
{
    char pad[0x33c];
    void* target;
};

struct Outer
{
    int placeholder;
    Inner* inner;
    void setTarget(void* arg);
};

void Outer::setTarget(void* arg)
{
    this->inner->target = arg;
}

