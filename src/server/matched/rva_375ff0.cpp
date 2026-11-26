class CgiOptions {
public:
    unsigned char gap0[4];
    unsigned char flags1;
    unsigned char flags2;

    bool ClearFlags();
};

bool CgiOptions::ClearFlags() {
    flags1 = 0;
    flags2 = 0;
    return false;
}
