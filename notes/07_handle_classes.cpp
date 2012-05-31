// **Handle Classes**
// 
// * You can do pointer arithmetic to access private variables - this is bad.
// 
// * Also, changing the .h files requires a complete re-compile of all code that derives from this.
// 
// * Response is to use a handle-class instead of what was defined in #6

// --------------------------------

// ***Rational.h file***
class Rational {
public:
    Rational(int num: 0, int denom: 1);
    int numerator() const;
    int denominator() const;
private:
    struct impl;
    impl *rat_;
public:
    
    //delete
    ~Rational();

    // copy
    Rational(const &Rational);

     // assignment
    Rational& operator=(const Rational);
}

// --------------------------------

// ***Rational.cpp file***
// 
// we create a struct called rational.
struct Rational::Impl {
    int num_;
    int denom_;
};

// Constructor:
Rational::Rational(int num, int denom)
    // Re: single colon in method:
    // 
    // In general, it needs to have the object that it is destructing, and the construction starts for the Rational object between the ":" and the "{"
    : rat_(new Rational::Impl) {
    if (denom == 0) throw "Panic!";
    rat_->num_ = num;
    rat_->denom_ = denom;
}

// Destructor
Rational::~Rational() {
    delete _rat;
}

// Initialization example (deep);
Rational::Rational(const Rational& r) {
    *rat_ = *(r.rat_);
}

// Copy example (deep);
Rational& operator=(const Rational& r) {
    if (&r = this) {
        return *this;
    }
    delete rat_;
    rat_ = new Rational::Impl(*r.rat_);
    return *this;
}

// ---------------------------------
// random code for code snippets:
int main() {
    // initialized as 0/1
    Rational r;

    // initialized as 0/1
    Rational s(r);

    //change the value of r
    cin >> r;

    // As a *shallow* copy, r = 10/1, s = 10/1.
    // As a *deep* copy, r = 10/1, s = 0/1
    cout << "r= " << r << ", s= ", << s;

}