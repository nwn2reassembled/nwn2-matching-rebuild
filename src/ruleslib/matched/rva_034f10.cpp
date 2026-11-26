struct Holder
{
    char padding[0x38];
    int value_;
};

void __stdcall SetValue(Holder& holder, int value)
{
    holder.value_ = value;
}
