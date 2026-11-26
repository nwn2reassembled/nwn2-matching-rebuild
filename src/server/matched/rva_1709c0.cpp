struct Controller;

struct ServerObject
{
    unsigned char pad_0000[0x7bc];
    int playerId; // +0x7bc
};

struct Node
{
    unsigned char pad_0000[4];   // +0x0
    Node*       next;            // +0x4
    ServerObject* object;        // +0x8
};

struct Controller
{
    Node* first; // +0x0
};

class ServerList
{
public:
    ServerObject* FindByPlayerId(int playerId);

    unsigned char pad_0000[0xc];
    Controller* controller; // +0xc
};

ServerObject* ServerList::FindByPlayerId(int playerId)
{
    Node* node = controller->first;
    while (node != 0)
    {
        ServerObject* object = node->object;
        if (object->playerId == playerId)
            return object;
        node = node->next;
    }
    return 0;
}
