struct Sub {
    int placeholder[206];
    int flag;
};

struct Main {
    int dummy;
    Sub* sub;
    void setFlag();
};

void Main::setFlag() {
    sub->flag = 1;
}

