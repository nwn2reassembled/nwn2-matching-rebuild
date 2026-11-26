struct Legacy {
    char _pad[28];
    int value;
    int* getValuePtr();
};

int* Legacy::getValuePtr() { return &value; }
