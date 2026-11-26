class LazyPtr
{
    void* ptr;
public:
    void InitIfNull(void* newValue);
};

void LazyPtr::InitIfNull(void* newValue)
{
    if (ptr == 0)
        ptr = newValue;
}
