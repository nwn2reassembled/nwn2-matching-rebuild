class ServerObject {
public:
    ServerObject& Self();
};

ServerObject& ServerObject::Self() {
    return *this;
}
