struct SomeObject {
    unsigned char pad_0000[0x94];
    int m_bFlag; // +0x94
};

struct SomeManager {
    unsigned char pad_0000[0x1fc4];
    SomeObject* m_pObj; // +0x1fc4

    int HasActiveFlag();
};

int SomeManager::HasActiveFlag() {
    if (m_pObj != 0 && m_pObj->m_bFlag != 0) {
        return 1;
    }
    return 0;
}
