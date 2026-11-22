struct MyStruct {
    char padding[0x44];
    float* arr;
    float method(int idx);
};

float MyStruct::method(int idx)
{
    return arr[idx];
}

