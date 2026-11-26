class Widget
{
public:
    unsigned int offset;
};

unsigned int __fastcall Widget_GetOffset(Widget *that, void *edxUnused)
{
    if (that->offset != 0)
        return that->offset + 0x74;

    return 0;
}
