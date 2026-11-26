struct Obj { unsigned char pad[0x7bc]; int id; };
struct Node { unsigned char pad[4]; Node* next; Obj* obj; };
struct List { Node* head; };

struct Container {
    unsigned char pad[0xc];
    List* list;

    Obj* FindById(int id);
};

Obj* Container::FindById(int id)
{
    Node* n = this->list->head;
    while (n != 0) {
        Obj* o = n->obj;
        if (o->id == id)
            return o;
        n = n->next;
    }
    return 0;
}
