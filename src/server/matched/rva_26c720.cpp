struct ValueHolder
{
    int value;
    void assign(int v);
};

void ValueHolder::assign(int v)
{
    value = v;
}
