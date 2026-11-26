struct Nested {
    char pad[0x60];
    int value;
};

class Outer {
public:
    int getValue();
private:
    char pad[0x6c8];
    Nested* nested;
};
int Outer::getValue() { return nested->value; }
