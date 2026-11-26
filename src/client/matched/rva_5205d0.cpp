struct SomeStruct
{
    char padding[0x60];
    void* field60;
};

void* GetField60(SomeStruct* obj)
{
    return obj->field60;
}
