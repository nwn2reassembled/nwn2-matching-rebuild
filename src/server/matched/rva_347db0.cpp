struct Object
{
    char padding[0x40];
    int value;
    int GetValue() const;
};

int Object::GetValue() const
{
    return value;
}
