struct Node {
    Node* f0;
    Node* f4;
    Node* f8;
    unsigned char pad[9];
    unsigned char f15;
};

class List {
    Node* m_head;
    Node* m_pos;

public:
    void Relink(Node* n);
};

void List::Relink(Node* n)
{
    Node* e = n->f0;
    Node* t = e->f8;
    n->f0 = t;
    t = e->f8;
    if (t->f15 == 0)
        t->f4 = n;
    Node* s = n->f4;
    e->f4 = s;

    Node* c = this->m_pos;
    if (n == c->f4) {
        c->f4 = e;
        e->f8 = n;
        n->f4 = e;
        return;
    }
    c = n->f4;
    if (n == c->f8) {
        c->f8 = e;
        e->f8 = n;
        n->f4 = e;
        return;
    }
    c->f0 = e;
    e->f8 = n;
    n->f4 = e;
}
