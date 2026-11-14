class Legacy {
public:
    int check(int value);
};

int Legacy::check(int value) {
    if (value == 1 || value == 5 || value == 6)
        return 1;
    return 0;
}
