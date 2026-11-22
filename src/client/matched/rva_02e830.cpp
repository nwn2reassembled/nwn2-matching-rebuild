struct MyStruct {
    int* p;
    bool check() const;
};

bool MyStruct::check() const {
    return *p != 0;
}

