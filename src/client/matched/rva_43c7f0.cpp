struct Legacy {
    virtual ~Legacy() {}
    int value;
    int* getAddress();
};

int* Legacy::getAddress() { return &value; }
