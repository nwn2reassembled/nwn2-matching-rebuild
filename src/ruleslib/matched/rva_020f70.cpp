struct LegacyStruct {
    int field0;
    int field1;
    int field2;
    int field3;
    int field4;
    int field5;
    int field6;
    int field7;
    int field8;
    int field9;
    LegacyStruct* clear();
};

LegacyStruct* LegacyStruct::clear() {
    field4 = 0;
    field5 = 0;
    field6 = 0;
    field7 = 0;
    field8 = 0;
    field9 = 0;
    field0 = 0;
    field1 = 0;
    field3 = 0;
    field2 = 0;
    return this;
}
