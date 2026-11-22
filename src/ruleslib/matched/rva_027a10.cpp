struct Target { char pad[0x190]; int value; };

class Wrapper {
public:
    int getFrom(const Target* p);
};

int Wrapper::getFrom(const Target* p) { return p->value; }

