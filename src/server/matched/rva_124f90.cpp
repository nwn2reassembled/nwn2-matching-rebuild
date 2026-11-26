struct RefCounted
{
    int reserved0;
    int reserved1;
    int reserved2;
    int references;
};

struct Holder
{
    RefCounted* first;
    void* second;

    Holder& CopyFrom(Holder const& other);
};

Holder& Holder::CopyFrom(Holder const& other)
{
    second = other.second;
    first = other.first;
    ++first->references;
    return *this;
}
