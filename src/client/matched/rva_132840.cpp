struct Object
{
    int unknown[9];
    int field_24;
};

void SetField24(Object* object, int value)
{
    object->field_24 = value;
}
