struct SomeStruct {
    unsigned char field0;
    unsigned char field1;
    unsigned char field2;
    unsigned char field3;
};

void __stdcall SomeStruct_SetField1(SomeStruct *s, unsigned char value)
{
    if (s != 0) {
        s->field1 = value;
    }
}
