struct Legacy {
    unsigned int pad[636];
    unsigned int field1;
    unsigned int field2;
    unsigned int field3;
    void setFields(unsigned int a, unsigned int b, unsigned int c);
};

void Legacy::setFields(unsigned int a, unsigned int b, unsigned int c) {
    field1 = a;
    field2 = b;
    field3 = c;
}

