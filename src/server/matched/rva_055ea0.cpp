class Legacy {
public:
    unsigned int get_value() const;
private:
    char padding[0x64];
    unsigned int value;
};

unsigned int Legacy::get_value() const { return value; }
