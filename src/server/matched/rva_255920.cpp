struct MyStruct {
    char padding[68];          // pad so that arr is at offset 0x44
    float* arr;                // array of floats
    void setValue(int index, float value);
};

void MyStruct::setValue(int index, float value) {
    arr[index] = value;
}
