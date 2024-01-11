template<typename t0, typename t1, typename t2>
class Triplet
{
private:
    t0 afirst;
    t1 asecond;
    t2 athird;
public:
    Triplet(t0 pfirst, t1 psecond, t2 pthird): afirst(pfirst), asecond(psecond), athird(pthird) {}

    ~Triplet() {}

    t0 first() const {return afirst;}
    void setFirst(t0 wert){afirst = wert;}

    t1 second() const {return asecond;}
    void setSecond(t1 wert){asecond = wert;}

    t2 third() const {return athird;}
    void setThird(t2 wert){athird = wert;}
};