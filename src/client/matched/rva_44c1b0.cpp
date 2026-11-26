struct Legacy {
    int dummy1;
    int dummy2;
    int dummy3;
    int dummy4;
    int dummy5;
    int dummy6;
    int dummy7;
    int dummy8;
    int dummy9;
    int dummy10;
    int fieldA; // offset 0x28
    int fieldB; // offset 0x2c

    void setFields(int a, int b);
};

void Legacy::setFields(int a, int b) {
    this->fieldA = a;
    this->fieldB = b;
}

