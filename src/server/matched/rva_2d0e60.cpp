struct ServerObject;

struct ServerObject {
  int field_0;
  ServerObject* GetSelf();
};

ServerObject* ServerObject::GetSelf()
{
  return this;
}
