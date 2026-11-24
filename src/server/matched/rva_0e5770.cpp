class Legacy {
public:
    int getValue() const;
private:
    char padding[16];
};

int Legacy::getValue() const {
    return *reinterpret_cast<const int*>(reinterpret_cast<const char*>(this)+16);
}

