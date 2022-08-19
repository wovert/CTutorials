class Singleton {
    private:
        int data;
        static Singleton *instance;
        Singleton();
        Singleton(const Singleton &ob);
    public:
        static Singleton* getInstance();
        void setData(int data);
        int getData(void);
};