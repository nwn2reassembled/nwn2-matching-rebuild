struct Object {
    int field_0;
    int field_4;
    int field_8;
    char gap_0C[0x418 - 0x0C];
    int field_418;
};

void __cdecl SetObjectValue(Object* obj, int value)
{
    obj->field_8 = value;
    if (value == 0)
        obj->field_418 = value;
}
