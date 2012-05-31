// Summary of ADT design decisions
// 
// * Legal Values, legal Default value?
// 
// * Explicit constructors
// 
// * Accessors, mutators
// 
// * function overloading (for flexible interfaces)
// 
// * operator overloading
// 
// * const parameters, methods
// 
// * member v.s.. non-member methods
// 
// * essential methods (our or the compiler's)
// 
// * mutattable or immutatable ADT
// 
// * information hiding
// 
// -----------------------------------------------
/* top */
// 
// *It looks like we're going to make a* **money ADT**
// 
// *Requirements*
// 
// * Must have up to two decimal places
// 
// * Positive,negative values
// 
// * currency
// 
// * very large values with perfect precision
// 
// Data Representation:
// 
//   * No floats!
// 
//   * Keep an integer value
// 
//   * Array of digits
// 
// Default Constructor, copy constructor
// 
// * define constructor
// 
//   * int -> Money
// 
//   * Rational -> Money
//      
// 
// Explicit:
// 
//   * value: Money -> string
// 
//   * dollars: Money -> String
// 
//   * cent: money -> string
// 
//   * +, -
// 
/* Money ADT */
//   * operator* : Money * Rational
/* nonmember */
// 
//   * Operator >>, Operator<< ==, !=, >, >=, <, <=
/* nonmember */
// 
//   * Copy constructor, operator=
// 