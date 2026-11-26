struct Part
{
    char payload[8];
    void init();
};

struct Trial
{
    Part first;
    Part second;
    Trial *eval();
};

Trial *Trial::eval()
{
    first.init();
    second.init();
    return this;
}
