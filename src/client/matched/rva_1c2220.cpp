class Legacy {
public:
    int getValue() const;
private:
    int pad[199];
    int value; // at offset 0x31c
};

int Legacy::getValue() const
{
    return value;
}

