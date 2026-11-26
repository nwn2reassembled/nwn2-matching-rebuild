struct Widget
{
    char padding[0x318];
    int value;
    int* GetValue();
};

int* Widget::GetValue()
{
    return &value;
}
