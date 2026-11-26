class SessionManager {
public:
    SessionManager* GetSelf();
};

SessionManager* SessionManager::GetSelf() {
    return this;
}
