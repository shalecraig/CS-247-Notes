// RationalExeptional.cpp
//------------------------------------
Rational operator* (const Rational &r, const Rational &s) {
    long numer = (long)r.numerator()   * (long) s.numerator();
    long denom = (long)r.denominator() * (long)s.denominator();
    try {
        // are watching for an overflow exception... this is a stupid example to show how try/catches work...
        if (numer <= INT_MAX && denom <= INT_MAX) {
            return Rational(numer, denom);
        } else {
            throw 0;
        }
    } catch (int) {
        long n = (numer> INT_MAX)  ? INT_MAX : numer;
        long d = (denom > INT_MAX) ? INT_MAX : denom;
        return Rational((int) n, (int) d);
    }
}

// RationalExeptional.cpp
//------------------------------------

Rational::Rational(int num, int denom): _n(1), _d(1) {
    if (denom == 0) {
        // We throw an exception
        // 
        // 1. Exception object is constructed
        // 
        // 1. We pass it to the nearest exception handler, which matches on the exception thrown.
        // 
        // 1. We may exit a number of functions in the call chain.
        // 
        // 1. Local stack-based objects of exited functions are properly destroyed.
        throw DivideByZeroException(num);
    }
    /* ... */
}

// somewhere else...
//------------------------------------

int main() {
    Rational r(1, 2);
    try {
        cout << "Enter rational number (a/b). " << endl;
        cin >> r;
    } catch (DivideByZeroException &e) {
        cout << e.numer() << "/0 is not a legal value, dickhead."<< endl;
    }
}

//------------------------------------
//
//  **Throwing exception types**

class X {
    class Trouble{};
    class Big: public Trouble{};
    class Small: public Trouble {};
    void f {throw Big();}
};

int main() {
    X x;
    try {
        x.f(); //will throw exception
    } catch (X::Small &) {
        cout << "Small Trouble" << endl;
    } catch (X::Trouble &) {
        // This will be triggered, because a big (thrown error) is a Trouble.
        cout << "Trouble" << endl;
    } catch (X::Big &) {
        cout << "Big Trouble" << endl;
    } catch (...) {
        cout << "catches any exception" << endl;
        // This re-throws the same exception.
        throw;
    }
}

// Exception specifications:
// -----------------------------------------------------------------------------------
class foo{
    // Specifies that it can throw a DivideByZero exception, or an OverFlow Exception
    // 
    // If an error that is not specified in the list is thrown, it generates a runtime error
    double safeDivide (int n, int d) throw (DivideByZero, OverFlow);
    // no specification for exceptions
    void f();
    // promises that no exceptions will be thrown.
    void g() throw()
};

// **Standard/predefined exceptions**
// -----------------------------------

// This code needs #include <stdexcept>
class runtime_error: public exception {
public:
    explicit runtime_error (const string& what_arg);
    // inherits virtual const char* what() const throw();
};

// Unwinding the stack:
// 
// - objects on the stack are deallocated automatically invoking the appropriate destructor
// 
// - partially constructed objects will also be properly destroyed (but not using their destructors)
// 
// What about dynamically allocated objects?
// 
// Solution: **RAII**
// 
// Resource allocation is Initialization idiom:
// 
// - equates resource management as object lifetime:
//
//   - construction
// 
//   - destruction

class Resource {
    resource_type * r_;
    resource_type* acquire (parms p);
    void release (resource_type *);
public:
    Resource(parms p) : r_ (acquire(p));
    ~Resource() {release(r_);}
    // accessors, mutators...
    // 
    // think about preventing copy assignment
};

// ----------------------------------
// 
// 
#include <stdio>
#include <stdexcept>
class file {
    std::FILE file_;
    file (const file&) ;
    file & operator= (const file&);
public:
    file(const char* name) : file_(std::fopen(name, "w+")) {
        // Check if successful.
    }
}