class Legacy {
public:
    int* getFieldPtr();
private:
    char pad[8];
    int field;
};

int* Legacy::getFieldPtr() { return &field; }
