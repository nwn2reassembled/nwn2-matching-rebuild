struct Legacy {
    char padding[300];
    int flag;
    void clearFlag();
};

void Legacy::clearFlag() { flag = 0; }
