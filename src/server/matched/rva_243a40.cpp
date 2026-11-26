struct R {
    int threshold;
};

struct Q {
    void* field0;
    void* field4;
    R* field8;
};

struct P {
    Q* q;
};

class C {
public:
    char pad0[0x2350];
    int m_value;
    char pad1[0x23b8 - 0x2350 - sizeof(int)];
    P* m_p;

    int Method();
};

int C::Method()
{
    P* p = m_p;
    if (p)
    {
        Q* q = p->q;
        if (q)
        {
            R* r = q->field8;
            if (m_value >= r->threshold)
                return 1;
        }
    }
    return 0;
}
