struct Object {
    unsigned char reserved[0x310];
    unsigned long value;

    unsigned long GetValue() const;
};

unsigned long Object::GetValue() const
{
    return value;
}
