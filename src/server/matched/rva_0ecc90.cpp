class MyStruct {
public:
    int a;
    int b;
    int c;
    int d;
    int target;
    void setTarget(int value);
};

void MyStruct::setTarget(int value) {
    this->target = value;
}

