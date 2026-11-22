struct Legacy {
    int a;
    int b;
    int value;
    int getValue() const;
};

int Legacy::getValue() const { return value; }
