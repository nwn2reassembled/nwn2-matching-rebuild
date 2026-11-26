struct S {
    int pad[10];
    int value;
};

void set_value(S* s, int value)
{
    s->value = value;
}
