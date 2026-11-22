struct Outer {
    int* ptr;
    virtual void dummy() const {}
    int get_value() const;
};

int Outer::get_value() const {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(ptr) + 0x100c0);
}
