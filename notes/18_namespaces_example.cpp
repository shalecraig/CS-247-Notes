

namespace X {
    int i, j, k;
}
int k;
void f() {
    int i=0;
    using namespace X;
    i+=1;
    j+=1;
    // this is not defined. 
    k+=1;

    // Here's a better way:
    ::k+=1;
    // x namespace
    X::k += 1;
}

void f2() {
    int i=0;
    // this clashes with the local i.
    using X::i;
    using X::j;
    using X::k;
    i+= 1;
    // X::j ++
    j+=1; 
    // X::k ++
    k+=1;
}

/* snip */
// ------------------------------------------------------------------------------------------------
// We want to protect local names against possible name clashes, so an nunamed name=space is used to declare local (private) methods in functions.
// 
// This generates a namespace like "namespace $$-asdfkkl1==" in the namespace - and it won't be able to be called from the outside.
// 
// This also generates a "use namespace $$-asdfkkl1==" directly after the namespace.
namespace {
    void foo();
}

// **Namespace lookup (resolution) rules:**
// 
// * Local Scope
// 
// * Enclosing scopes (inner -> outer), global namespace is last.
// 
// * Namespaces of all of function's arguments are last.
// 
/* snip */

namespace Chrono {
    class Date {
        ...
    };

    ...
    bool operator ==(const Date&, const std:: string);
    ...
}

void f(Chrono::Date d, std::strings) {
    // This equality operator is resolved towards:
    // Local, then enclosing scopes, then namespaces of the arguments of the function 9i.e. std::string's namespace -> string
    if (d == ...) {

    }
}
