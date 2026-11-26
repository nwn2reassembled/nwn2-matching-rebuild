class Legacy {
public:
    int compare(unsigned int value);
};

int Legacy::compare(unsigned int value) {
    return (value <= 4u) ? 1 : 0;
}
