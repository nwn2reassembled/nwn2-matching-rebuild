struct MyStruct {
    char _pad[0x44];
    float *arrayField;
    float getValue(int) const;
};

float MyStruct::getValue(int index) const {
    return *(arrayField + index);
}

