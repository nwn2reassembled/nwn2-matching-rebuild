class CThing;

class CWidget {
public:
    unsigned char pad[0xE58];
    class CThing* thing;

    class CWidget* GetThingOwner();
};

class CThing {
public:
    unsigned char pad[4];
    class CWidget* owner;
};

class CWidget* CWidget::GetThingOwner()
{
    class CThing* t = thing;
    if (t != 0)
        return t->owner;
    return 0;
}
