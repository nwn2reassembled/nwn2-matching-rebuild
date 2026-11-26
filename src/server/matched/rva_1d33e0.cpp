struct Element
{
    int values[5];
};

class Container
{
public:
    Element* Get(int index);

private:
    char reserved[0xa78];
    Element* elements;
    int count;
};

Element* Container::Get(int index)
{
    if (index < 0 || index >= count)
        return 0;

    return &elements[index];
}
