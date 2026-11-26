struct Widget {
    char reserved[0xC4];
    int value;
    void setValue(int v);
};

void Widget::setValue(int v)
{
    value = v;
}
