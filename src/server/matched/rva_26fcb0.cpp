class MyStruct {
public:
    int field0;
    int field1; // offset 4
    int field2; // offset 8
    int field3; // offset 12
    int field4; // offset 16
    int field5; // offset 20
    int field6; // offset 24
    int field7; // offset 28
    int field8; // offset 32
    int field9; // offset 36
    int field10; // offset 40
    int field11; // offset 44
    int field12; // offset 48
    MyStruct* clear();
};

MyStruct* MyStruct::clear() {
    field1 = 0;
    field2 = 0;
    field3 = 0;
    field4 = 0;
    field5 = 0;
    field6 = 0;
    field7 = 0;
    field8 = 0;
    field9 = 0;
    field10 = 0;
    field11 = 0;
    field12 = 0;
    return this;
}

