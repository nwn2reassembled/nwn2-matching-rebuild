struct Node {
    int field_00;
    int field_04;
    int field_08;
    int field_0C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
};

void __cdecl Node_Reset(Node *node)
{
    node->field_18 = 0;
    node->field_24 = 0;
    node->field_1C = 1;
}
