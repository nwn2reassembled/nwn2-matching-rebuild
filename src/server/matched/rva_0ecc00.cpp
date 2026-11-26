struct MyStruct {
    int field1;
    int field2;
    int field3;
    int field4;
    int field5;
    float value;

    float getValue();
};

float MyStruct::getValue() { return this->value; }
