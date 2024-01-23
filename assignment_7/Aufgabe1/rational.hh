#include <string>
#include <iostream>

// (a)
int ggT (int a, int b) {
    //euklidischer Algorithmus
    while(b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

class Rational {
private:
  double _zaehler;
  double _nenner;

public:
  Rational(double zaehler, double nenner) : _zaehler(zaehler), _nenner(nenner) {
    _zaehler /= ggT(_zaehler, _nenner);
    _nenner /= ggT(_zaehler, _nenner);
    if (_nenner == 0) {
      _zaehler = 0;
      _nenner = 1;
      std::cerr << "Division durch 0 ist nicht definiert." << std::endl;
    }
    if (_nenner < 0) {
      _zaehler = -_zaehler;
      _nenner *= -1;
    }
  };
  Rational(int zaehler) : _zaehler(zaehler), _nenner(1) {};
  Rational() : _zaehler(0), _nenner(1) {};

  // (b)
  friend std::ostream& operator<<(std::ostream& os, const Rational& r) {
    if (r._nenner == 1) {
      return os << std::to_string(r._zaehler);
    } else {
      // os << std::to_string(r._zaehler) + "/" + std::to_string(r._nenner) << std::endl;
      return os << r._zaehler << "/" << r._nenner << std::endl;
    }
  }

  // (c)
  Rational operator+(Rational const& r) {
    Rational res;
    if (_nenner == r._nenner) {
      res._zaehler = _zaehler + r._zaehler;
      res._nenner = _nenner;
    } else {
      res._zaehler = _zaehler * r._nenner + r._zaehler * _nenner;
      res._nenner = _nenner * r._nenner;
    }
    return res;
  }

  Rational operator-(Rational const& r) {
    Rational res;
    if (_nenner == r._nenner) {
      res._zaehler = _zaehler - r._zaehler;
      res._nenner = _nenner;
    } else {
      res._zaehler = _zaehler * r._nenner - r._zaehler * _nenner;
      res._nenner = _nenner * r._nenner;
    }
    return res;
  }

  Rational operator*(Rational const& r) {
    Rational res;
    res._zaehler = _zaehler * r._zaehler;
    res._nenner = _nenner * r._nenner;
    return res;
  }

  Rational operator/(Rational const& r) {
    Rational res;
    res._zaehler = _zaehler * r._nenner;
    res._nenner = _nenner * r._zaehler;
    return res;
  }

  Rational operator-() {
    Rational res;
    res._zaehler = -_zaehler;
    res._nenner = _nenner;
    return res;
  }

  // (d)
  double eval() {
    return (double) _zaehler / (double) _nenner;
  }

  friend double operator+(double zahl, Rational r) {
    r._zaehler = r._zaehler + r._nenner * zahl;
    return r.eval();
  }

  friend double operator-(double zahl, Rational r) {
    r._zaehler = r._nenner * zahl - r._zaehler;
    return r.eval();
  }

  friend double operator*(double zahl, Rational r) {
    r._zaehler = r._zaehler * zahl;
    return r.eval();
  }

  friend double operator/(double zahl, Rational r) {
    r._nenner = r._nenner * zahl;
    double temp = r._nenner;
    r._nenner = r._zaehler;
    r._zaehler = temp;
    return r.eval();
  }

  friend double operator+(Rational r, double zahl) {
    r._zaehler = r._zaehler + r._nenner * zahl;
    return r.eval();
  }

  friend double operator-(Rational r, double zahl) {
    r._zaehler = r._zaehler - r._nenner * zahl;
    return r.eval();
  }
  friend double operator*(Rational r, double zahl) {
    r._zaehler = r._zaehler * zahl;
    return r.eval();
  }
  friend double operator/(Rational r, double zahl) {
    r._nenner = r._nenner * zahl;
    return r.eval();
  }

  // (e)
  Rational& operator=(Rational& r) {
    if (this != &r) {
      _zaehler = r._zaehler;
      _nenner = r._nenner;
    }
    return *this;
  }
  Rational& operator+=(Rational& r) {
    if (this != &r) {
      _zaehler = r._zaehler * _nenner + r._nenner * _zaehler;
      _nenner = r._nenner * _nenner;
    }
    return *this;
  }
  Rational& operator-=(Rational& r) {
    if (this != &r) {
      _zaehler = _zaehler * r._nenner - r._zaehler * _nenner;
      _nenner = _nenner * r._nenner;
    }
    return *this;
  }
  Rational& operator*=(Rational& r) {
    if (this != &r) {
      _zaehler *= r._zaehler;
      _nenner *= r._nenner;
    }
    return *this;
  }
  Rational& operator/=(Rational& r) {
    if (this != &r) {
      _zaehler = _zaehler * r._nenner;
      _nenner = _nenner * r._zaehler;
    }
    return *this;
  }

  // (f)
  bool operator==(Rational r) {
    double x = eval();
    double y = (double) r._zaehler / (double) r._nenner;
    return x == y; 
  }
  bool operator!=(Rational r) {
    double x = eval();
    double y = (double) r._zaehler / (double) r._nenner;
    return x != y; 
  }
  bool operator<(Rational r) {
    double x = eval();
    double y = (double) r._zaehler / (double) r._nenner;
    return x < y; 
  }
  bool operator>(Rational r) {
    double x = eval();
    double y = (double) r._zaehler / (double) r._nenner;
    return x > y; 
  }
  bool operator<=(Rational r) {
    double x = eval();
    double y = (double) r._zaehler / (double) r._nenner;
    return x <= y; 
  }
  bool operator>=(Rational r) {
    double x = eval();
    double y = (double) r._zaehler / (double) r._nenner;
    return x >= y; 
  }
  // (g)
  explicit operator bool() const {
    return _zaehler == 0 ? false : true;
  }
};