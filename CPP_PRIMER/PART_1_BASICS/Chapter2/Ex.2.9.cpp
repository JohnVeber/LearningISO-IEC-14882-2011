/*      Variable initialization tests not in function body (except case "a").
The lines with the code that causes compilation errors are commented on.
A comment is provided for each case.                                       */

#include <iostream>

/*  Case b (declaration part): */
// int i = {3.14};

/*  Case c (declaration part): */
//  double salary = wage = 9999.99;

/*  Case d (declaration part): */
int i = 3.14;

int main(){
    /*  Case a: */
    // std::cin >> input_value;
    // std::cout << input_value << std::endl;

    /*  Comments to the case a: */
    // 1) After the operator >> compiler expect an expression, not a keyword (that denotes the variable of type int).
    // 2) In C++ the variable’s type declaration is a statement, not an expression.
    // 3) Problem type: Use object name without preannouncement.
    // 4) The second compiler error "'input_value' was not declared in this area" is a direct consequence of the first error.


    /*  Case b: */
    //std::cout << i << std::endl;

    /*  Comments to the case b: */
    // 1) List initialization (with curly braces {}) has an important rule - it prohibits narrowing conversions.
    // 2) Figure brackets {} is a way to tell the compiler: "Be more strict, make sure I’m not losing data by chance."
    // 3) That's why, when compiling, the response to truncation does not cause a warning, but leads to compilation error.


    /*  Case c: */
    // std::cout << salary << std::endl;
    // std::cout << wage << std::endl;

    /*  Comments to the case c: */
    // 1) "= wage = 9999.99" is an initialization expression for the salary variable.
    // 2) By the time the compiler reaches "wage" in terms of initialization, the "wage" variable has not yet been announced.
    // 3) Chain of assignment is possible, but all variables must already be declared before the start of the chain.


    /*  Case d: */
    std::cout << i << std::endl;

    /*  Comments to the case d: */
    // 1) Classical initialization = (case d) allows data loss when the value assigned to an object of integer type.
    // 2) In this case, it is a simple drop of the fractional part of a floating point number.
    // 3) Use the "-Wconversion" flag to get a warning during the compilation step.

    return 0;
}
