class ServerObject {
public:
  ServerObject* retain();
};

ServerObject* ServerObject::retain() {
  return this;
}
