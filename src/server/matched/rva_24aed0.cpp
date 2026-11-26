class CServerObject
{
public:
    CServerObject* GetSelf();

    int m_id;
    void* m_data;
};

CServerObject* CServerObject::GetSelf()
{
    return this;
}
