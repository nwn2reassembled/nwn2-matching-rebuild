class LegacyStruct {
public:
    int getValue() const;
private:
    char pad[0x110];
    int value;
};

int LegacyStruct::getValue() const { return value; }
