struct Counter
{
    int value;
    Counter* Advance();
};

Counter* Counter::Advance()
{
    Counter* result = this;
    result->value += 4;
    return result;
}
