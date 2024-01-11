template<typename onetype> //template fuer die Variable 
class Collector {
private:
    onetype sum;
    onetype adder;

public:
    // Konstruktor
    Collector(onetype initialSum, onetype initialAdder) : sum(initialSum), adder(initialAdder) {}

    // Methode zum Hinzufügen eines Werts zu sum und adder
    void add(onetype value) {
        sum += adder;
        sum += value;
    }

    // Methode zum Abrufen des aktuellen Werts von sum
    onetype digest() const {
        return sum;
    }
};