struct Value {
    unsigned int field0;
    unsigned int field1;
    unsigned int field2;
    unsigned int field3;
    unsigned int field4;

    Value& operator=(const Value& rhs);
};

Value& Value::operator=(const Value& rhs)
{
    field0 = rhs.field0;
    field1 = rhs.field1;
    field2 = rhs.field2;
    field3 = rhs.field3;
    field4 = rhs.field4;
    return *this;
}
