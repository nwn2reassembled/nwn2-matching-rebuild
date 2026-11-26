class App {
public:
    unsigned char m_pad[0x7AB54];
    unsigned long m_flag7ab54;
    int __thiscall ClearPendingFlag();
};

int App::ClearPendingFlag()
{
    if (this->m_flag7ab54 == 0)
        return 0;
    this->m_flag7ab54 = 0;
    return 1;
}
