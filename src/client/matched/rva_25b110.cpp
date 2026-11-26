class Widget {
public:
    void Subtract(int amount);
private:
    char padding[0x2368];
    int value;
};

void Widget::Subtract(int amount)
{
    value -= amount;
    if (value < 0)
        value = 0;
}
