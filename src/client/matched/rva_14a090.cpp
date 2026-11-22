struct MyLegacy {
    char pad[160];
    int value;
    int getValue() const;
};

int MyLegacy::getValue() const { return value; }
