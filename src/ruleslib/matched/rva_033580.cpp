struct Object
{
    char padding[0x4c];
    float value;
};

float __stdcall GetObjectValue(const Object* object)
{
    return object->value;
}
