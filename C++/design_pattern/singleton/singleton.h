class Singleton {
    private:
        int data;
        static Singleton *instance;
        Singleton();
        Singleton(const Singleton &ob);
        void operator=(const Singleton &single) {}
    public:
        static Singleton* getInstance();
        static void deleteSingleton();
        void setData(int data);
        int getData(void);
};