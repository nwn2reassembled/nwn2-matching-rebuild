class MyStruct {
public:
    void setFlag();
};

void MyStruct::setFlag() {
    *(reinterpret_cast<unsigned char*>(this) + 0xb0) = 1;
}

