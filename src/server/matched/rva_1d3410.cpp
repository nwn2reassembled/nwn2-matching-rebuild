struct Element
{
    int v0;
    int v1;
    int v2;
    int v3;
    int v4;
};

class Container
{
public:
    Element* Get(int index);

private:
    char m_pad[0xa84];
    Element* m_elements;
    int m_count;
};

Element* Container::Get(int index)
{
    if (index < 0 || index >= m_count)
        return 0;

    return &m_elements[index];
}
