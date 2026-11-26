struct Bridge
{
    int callee();
};

int __stdcall evaluate(Bridge *value)
{
    return value->callee();
}
