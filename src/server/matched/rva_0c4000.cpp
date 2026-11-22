class Legacy {
public:
    int getValue() const;
private:
    char pad[0xbc];
    int value;
};

int Legacy::getValue() const { return value; }

