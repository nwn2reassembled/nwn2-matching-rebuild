struct Object
{
    char padding[0x4ba];
    unsigned short value;

    void SetValue(unsigned short newValue);
};

void Object::SetValue(unsigned short newValue)
{
    value = newValue;
}
