struct LegacyStruct {
    unsigned char field0;
    unsigned char field1;
    unsigned int  field2;
    unsigned short field3;
    unsigned short field4;
    unsigned int  field5;
    unsigned int  field6;
    unsigned short field7;
    unsigned short field8;
    unsigned short field9;
    unsigned short field10;
    unsigned int  field11;
    unsigned int  field12;
    unsigned int  field13;
    unsigned int  field14;
    float         field15;
    float         field16;
    float         field17;
    unsigned int  field18;
    unsigned int  field19;
    unsigned int  field20;
    float         field21;

    void copyFrom(const LegacyStruct* src);
};

void LegacyStruct::copyFrom(const LegacyStruct* src) {
    field0 = src->field0;
    field1 = src->field1;
    field2 = src->field2;
    field3 = src->field3;
    field4 = src->field4;
    field5 = src->field5;
    field6 = src->field6;
    field7 = src->field7;
    field8 = src->field8;
    field9 = src->field9;
    field10 = src->field10;
    field11 = src->field11;
    field12 = src->field12;
    field13 = src->field13;
    field14 = src->field14;
    field15 = src->field15;
    field16 = src->field16;
    field17 = src->field17;
    field18 = src->field18;
    field19 = src->field19;
    field20 = src->field20;
    field21 = src->field21;
}

