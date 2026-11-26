struct Widget
{
    char reserved[0x15];
    unsigned char field;
};

void __cdecl SetWidgetField(Widget* widget, unsigned char value)
{
    widget->field = value;
}
