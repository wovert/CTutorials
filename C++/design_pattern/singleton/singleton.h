class Singleton {
    private:
        int data;
        static Singleton *instance;
        Singleton() {};
        Singleton(const Singleton &ob) {};
    public:
        static Singleton* getInstance() {
            return instance;
        };
        void setData(int data) {
            this->data = data;
        };
        int getData(void) {
            return data;
        };
};