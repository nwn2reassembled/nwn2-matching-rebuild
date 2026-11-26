struct StrHolder {
    const char* m_pStr;
    unsigned int GetStrLength() const;
};

unsigned int StrHolder::GetStrLength() const {
    const char* s = m_pStr;
    if (s == 0) {
        return 0;
    }
    const char* end = s + 1;
    const char* p = s;
    char c;
    do {
        c = *p++;
    } while (c != 0);
    return (unsigned int)(p - end);
}
