class user{
    public:
        int id;
        std::string name;
        user(int id, std::string name) : id(id), name(name) {}
        ~user() {}
        bool operator<(const user &user) const { return this->id < user.id; };
        bool operator==(const user &user) const { return this->id == user.id; };
};