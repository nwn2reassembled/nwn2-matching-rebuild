class GameGlobals {
    int* m_pTable;
public:
    int getRuntimeValue() const;
};

int GameGlobals::getRuntimeValue() const {
    int* p = m_pTable;
    if (p != 0)
        return *reinterpret_cast<int*>(reinterpret_cast<char*>(p) + 0x7ac4c);
    return 0;
}
