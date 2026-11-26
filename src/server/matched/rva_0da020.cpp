class Legacy {
public:
    int * getElement(int index) const;
private:
    char pad[0x3c];
    int * array_;
};

int * Legacy::getElement(int index) const {
    return array_ + index * 5;
}

