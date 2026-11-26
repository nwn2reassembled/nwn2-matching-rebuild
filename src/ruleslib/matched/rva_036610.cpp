struct NWNObject
{
    int field0;
    int field4;
    int field8;
};

NWNObject* __stdcall SetField8(NWNObject* object, int value)
{
    if (object != 0)
        object->field8 = value;
    return object;
}
