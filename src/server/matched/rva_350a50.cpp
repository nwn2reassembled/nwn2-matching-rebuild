struct Pair {
    int first;
    int second;
    Pair* clear();
};

Pair* Pair::clear()
{
    first = 0;
    second = 0;
    return this;
}
