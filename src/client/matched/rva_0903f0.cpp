struct MyStruct {
    unsigned int field;
    void setField(unsigned int);
};

void MyStruct::setField(unsigned int val) { this->field = val; }
