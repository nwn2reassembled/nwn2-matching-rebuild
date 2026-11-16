struct Legacy {
    char pad[0x1a0];
    float fieldA;
    float fieldB;
    float fieldC;
    void setValues(float a, float b, float c);
};

void Legacy::setValues(float a, float b, float c) {
    fieldA = a;
    fieldB = b;
    fieldC = c;
}

