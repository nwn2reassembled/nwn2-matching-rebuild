extern "C" void notify(int value);

struct Trial
{
    int unused;
    int flag;
    void eval();
};

void Trial::eval()
{
    if (flag)
        notify(0);
}
