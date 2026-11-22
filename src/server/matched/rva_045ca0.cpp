struct MyStruct {
    char pad[0x5C];
    unsigned int value;
    unsigned int get_value() const;
};

unsigned int MyStruct::get_value() const
{
    return value;
}

