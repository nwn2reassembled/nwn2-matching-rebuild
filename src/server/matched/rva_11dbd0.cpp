struct Element
{
    unsigned char reserved0[0x30];
    unsigned int value;
};

struct Container
{
    unsigned char reserved0[0x38];
    Element* elements;

    unsigned int GetValue(unsigned int index);
};

unsigned int Container::GetValue(unsigned int index)
{
    return elements[index].value;
}
