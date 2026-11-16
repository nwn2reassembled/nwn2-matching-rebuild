struct TargetStruct {
    char pad[76];
    int flag_4c;
};

class MyClass {
public:
    void setFlag(TargetStruct* p);
};

void MyClass::setFlag(TargetStruct* p) {
    p->flag_4c = 1;
}

