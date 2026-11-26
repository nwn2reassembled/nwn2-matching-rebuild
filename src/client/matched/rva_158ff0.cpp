struct ThresholdState
{
    char reserved0[0x4c];
    int threshold;
    char reserved1[0x4];
    unsigned char value;

    void UpdateValue(int candidate);
};

void ThresholdState::UpdateValue(int candidate)
{
    if (threshold < candidate)
        value = static_cast<unsigned char>(candidate);
}
