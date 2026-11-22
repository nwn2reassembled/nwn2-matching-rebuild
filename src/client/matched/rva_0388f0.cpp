struct MyStruct {
    void copyFloats(int index, const float *src);
};

void MyStruct::copyFloats(int index, const float *src) {
    float* dst = reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x188) + index * 3;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

