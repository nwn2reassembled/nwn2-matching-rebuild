struct MyStruct {
    void* getField() const;
};

void* MyStruct::getField() const { return (void*)((char*)this + 0x84); }
