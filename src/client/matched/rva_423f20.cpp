struct C {
    char pad[0x130];
    int m_count;
    int GetCountClamped();
};

int C::GetCountClamped() {
    int c = m_count;
    if (c >= 28) c = 28;
    return c;
}
