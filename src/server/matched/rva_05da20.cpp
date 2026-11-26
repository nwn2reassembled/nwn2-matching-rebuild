struct Trial
{
    void helper();
    int eval();
};

int Trial::eval()
{
    helper();
    return 0;
}
