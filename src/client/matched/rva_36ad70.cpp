struct ContainerImpl
{
    char reserved[0x2c];
    void** entries;
};

class Container
{
public:
    void* GetEntry(unsigned int index);

private:
    char reserved[0x2c];
    void** entries;
};

void* Container::GetEntry(unsigned int index)
{
    return index <= 0x9f ? entries[index] : 0;
}
