struct Widget
{
    int value;
    Widget* Clear();
};

Widget* Widget::Clear()
{
    value = 0;
    return this;
}
