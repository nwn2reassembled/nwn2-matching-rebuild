struct MyStruct {
    float in0;   // offset 0
    float in1;   // offset 4
    float in2;   // offset 8
    float mult1; // offset 12
    float in3;   // offset 16
    float in4;   // offset 20
    float in5;   // offset 24
    float mult2; // offset 28
    float out0;  // offset 32
    float out1;  // offset 36
    float out2;  // offset 40
    float out3;  // offset 44
    float out4;  // offset 48
    float out5;  // offset 52
    void compute();
};

void MyStruct::compute() {
    out0 = in0 * mult1;
    out1 = in1 * mult1;
    out2 = in2 * mult1;
    out3 = in3 * mult2;
    out4 = in4 * mult2;
    out5 = in5 * mult2;
}

