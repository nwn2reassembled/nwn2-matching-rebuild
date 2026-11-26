struct Zeroed {
    int first;
    int second;
    int third;
    int fourth;
    int fifth;

    Zeroed* clear();
};

Zeroed* Zeroed::clear()
{
    first = 0;
    second = 0;
    third = 0;
    fourth = 0;
    fifth = 0;
    return this;
}
