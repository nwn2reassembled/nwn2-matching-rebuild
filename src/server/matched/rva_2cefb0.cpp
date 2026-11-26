struct State
{
    int first;
    int second;
    int third;

    State* Clear();
};

State* State::Clear()
{
    second = 0;
    third = 0;
    first = 0;
    return this;
}
