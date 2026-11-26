class MyStruct {
public:
    float getValue() const;
private:
    char pad[48];
    float value;
};

float MyStruct::getValue() const { return value; }

