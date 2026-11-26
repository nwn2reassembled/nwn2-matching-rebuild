class Widget {
    unsigned int field_00;
    unsigned int field_04;
    unsigned int field_08;
    unsigned int field_0c;
    unsigned int field_10;
    unsigned int field_14;
    unsigned int field_18;
    unsigned int field_1c;
    unsigned int field_20;
    unsigned int field_24;
    unsigned int field_28;
    unsigned int field_2c;
    unsigned int field_30;
    unsigned int field_34;
    unsigned int field_38;
    unsigned int field_3c;
    unsigned int field_40;
    unsigned char field_44;
public:
    void SetField04(unsigned int value);
};

void Widget::SetField04(unsigned int value) {
    if (field_44 == 0)
        field_04 = value;
}
