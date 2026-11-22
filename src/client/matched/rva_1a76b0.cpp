class Legacy {
public:
    unsigned int getValue() const;
};

unsigned int Legacy::getValue() const {
    return *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 0x37c);
}

