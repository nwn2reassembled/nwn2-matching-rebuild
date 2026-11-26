struct Link {
    Link* entry;
    Link* next;
};

Link* __cdecl ResolveNext(Link** table, Link* node)
{
    if (node == 0)
        return *table;
    if ((*table)->entry == node)
        return 0;
    return node->next;
}
