struct Target {
    char padding[0xa44];
    float value;
    int SetValue(float v);
};

int Target::SetValue(float v)
{
    value = v;
    return 1;
}
