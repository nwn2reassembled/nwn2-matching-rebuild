struct MyStruct {
    void setParam(unsigned int);
    unsigned char data[20];
    unsigned int flag;
    unsigned char mid[5];
    unsigned char byteField;
};

void MyStruct::setParam(unsigned int param) { flag = 1; byteField = static_cast<unsigned char>(param); }
