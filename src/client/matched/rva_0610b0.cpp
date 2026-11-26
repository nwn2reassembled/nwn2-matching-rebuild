struct Widget {
    unsigned char pad[0x1350];
    unsigned char field_1350;
    void SetField1350(unsigned char value);
};

void Widget::SetField1350(unsigned char value) {
    field_1350 = value;
}
