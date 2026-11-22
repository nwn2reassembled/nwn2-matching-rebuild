class Legacy {
public:
    void inc(int* p);
};

void Legacy::inc(int* p) { (*p)++; }
