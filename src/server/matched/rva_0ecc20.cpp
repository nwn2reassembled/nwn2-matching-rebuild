struct LegacyStruct {
    char pad[0x18];
    float value;
    float getValue() const;
};

float LegacyStruct::getValue() const { return value; }
