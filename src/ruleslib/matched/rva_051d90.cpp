struct Foo {
    char pad[0x58];
    int  data;

    int* GetData();
};

int* Foo::GetData() {
    return &this->data;
}
