class Digital_in {

    private:
        int PDX;

    public:
        Digital_in(int pin);
        void init();
        bool is_hi();
        bool is_lo();
};