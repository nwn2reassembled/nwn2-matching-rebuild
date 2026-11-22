struct Legacy {
    virtual ~Legacy() {}
private:
    int value;
public:
    int getPlusA() const;
};

int Legacy::getPlusA() const { return value + 0xa8; }

