struct ObjectAt38
{
    unsigned char padding[0x38];
    int value;
};

int __stdcall ReadValueAt38(ObjectAt38* object)
{
    return object->value;
}
