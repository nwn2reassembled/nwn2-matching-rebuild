struct MyStruct {
    float getValue() const;
private:
    float m1, m2, m3, m4, m5, m6; // 24 bytes total
    float value;                    // at offset 0x18
};
float MyStruct::getValue() const { return value; }
