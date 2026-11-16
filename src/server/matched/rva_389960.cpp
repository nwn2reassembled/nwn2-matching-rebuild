struct MyStruct {
    int* data;
    int get(int idx) const;
};

int MyStruct::get(int idx) const { return data[idx]; }
