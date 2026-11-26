class Legacy {
public:
    void setValues(const float* src);
private:
    char padding[0x210];
    float value1;
    float value2;
    float value3;
};

void Legacy::setValues(const float* src) {
    value1 = src[0];
    value2 = src[1];
    value3 = src[2];
}

