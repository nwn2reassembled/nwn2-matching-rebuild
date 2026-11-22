class Legacy {
public:
    void setFlag();
private:
    char pad[0xC8];
    unsigned int flag;
};

void Legacy::setFlag() {
    this->flag = 1;
}

