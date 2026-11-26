class CGameObject {
public:
    CGameObject* Self();
};

CGameObject* CGameObject::Self()
{
    return this;
}
