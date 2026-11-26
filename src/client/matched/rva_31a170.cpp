class Widget {
public:
    char pad00[0xCC];
    int *items;
    char padD0[0x04];
    int count;

    int GetItemAt(int index);
};

int Widget::GetItemAt(int index)
{
    if (index < 0 || index >= count)
        return 0;
    return items[index];
}
