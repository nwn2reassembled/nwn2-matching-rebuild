struct Object
{
    unsigned int first;
    unsigned int value1;
    unsigned int value2;
    unsigned int value3;
    unsigned int value4;

    Object *clear();
};

Object *Object::clear()
{
    value1 = 0;
    value2 = 0;
    value3 = 0;
    value4 = 0;
    return this;
}
