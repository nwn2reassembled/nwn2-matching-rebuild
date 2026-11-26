struct MyStruct {
    unsigned int dummy0;
    float f1;
    char pad[40];
    int i1;
    int i2;
    int i3;
    void setValues(float a, int b, int c, int d);
};

void MyStruct::setValues(float a, int b, int c, int d)
{
    f1 = a;
    i1 = d;
    i2 = b;
    i3 = c;
}

