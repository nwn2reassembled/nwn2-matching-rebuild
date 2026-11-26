struct Other {
    char pad[0x7d0];
    int value;
};

struct C {
    int unknown;
    int values[18];

    int Contains(Other* other);
};

int C::Contains(Other* other)
{
    for (int i = 0; i < 18; ++i) {
        if (values[i] == other->value) {
            return 1;
        }
    }
    return 0;
}
