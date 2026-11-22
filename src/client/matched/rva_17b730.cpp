class Legacy {
public:
    void setValues(int a, int b);
private:
    char pad1[0x148];
    int field_148;
    int field_14c;
    char pad2[0x3ec];
    int field_53c;
    int field_540;
    char pad3[0x24];
    int field_568;
    int field_56c;
};

void Legacy::setValues(int a, int b) {
    field_53c = a;
    field_540 = b;
    field_148 = a;
    field_14c = b;
    field_568 = a;
    field_56c = b;
}

