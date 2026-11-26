struct Foo {
    void setFlag();
};

void Foo::setFlag() { *(int*)((char*)this + 0x23c0) = 1; }
