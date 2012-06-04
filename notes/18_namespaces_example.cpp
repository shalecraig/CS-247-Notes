

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
