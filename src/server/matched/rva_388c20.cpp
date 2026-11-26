struct Holder
{
    int first;
    int second;
    __int64 value;
    __int64 GetValue() const;
};

__int64 Holder::GetValue() const
{
    return value;
}
