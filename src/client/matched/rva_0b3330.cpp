class MyStruct {
public:
    int field0;
    char pad[44];
    int value;

    int getValue() const;
};

int MyStruct::getValue() const { return value; }

