struct MyStruct {
    char pad[0x78];
    int arr[10];
public:
    void setField(int idx, int val);
};

void MyStruct::setField(int idx, int val) {
    this->arr[idx] = val;
}

