struct StateHolder
{
    int unknown0;
    int state;
    bool IsStateUsable() const;
};

bool StateHolder::IsStateUsable() const
{
    return state == 0 || state == 1;
}
