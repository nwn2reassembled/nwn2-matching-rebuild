struct InnerValue {
    char reserved[0x964];
    short value;
};

struct OuterValue {
    short GetInnerValue();

    char reserved[0x9a0];
    InnerValue* inner;
};

short OuterValue::GetInnerValue()
{
    if (inner != 0)
        return inner->value;

    return -1;
}
