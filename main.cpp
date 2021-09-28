/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T( int v, const char* s ) : value(v), name(s) {}  //1
    int value; //2
    std::string name; //3
};

struct CompareFuncForT                                //4
{
    T* compare(T& a, T& b) //5
    { 
        if( a.value < b.value ) return &a;
        if( b.value > b.value ) return &b;
        return nullptr;
    }
};

struct U
{
    float fval_1 { 0 }, fval_2 { 0 };
    float convergeUVars( float& updatedValue )    //12
    {
        std::cout << "U's fval_1 value: " << fval_1 << std::endl;
        fval_1 = updatedValue;
        std::cout << "U's fval_1 updated value: " << fval_1 << std::endl;
        while( std::abs(fval_2 - fval_1) > 0.001f )
        {
            fval_2 += 0.5f;  // makes distance between fval_2 and fval_1 get smaller
        }
        std::cout << "U's fval_2 updated value: " << fval_2 << std::endl;
        return fval_2 * fval_1; 
    }
};

struct AddAndMultUvals
{
    static float convergeUVarsStatic( U& that, float& updatedValue )  //10
    {
        std::cout << "U's fval_1 value: " << that.fval_1 << std::endl;
        that.fval_1 = updatedValue;
        std::cout << "U's fval_1 updated value: " << that.fval_1 << std::endl;
        while( std::abs(that.fval_2 - that.fval_1 ) > 0.001f )
        {
            that.fval_2 += 0.5f;  // makes distance between fval_2 and fval_1 get smaller
        }
        std::cout << "U's fval_2 updated value: " << that.fval_2 << std::endl;
        return that.fval_2 * that.fval_1;
    }
};

        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T pair1( 7, "foo" );                                             //6
    T pair2( 11, "bar");                                             //6
    
    CompareFuncForT f;                                            //7
    auto* smaller = f.compare( pair1, pair2 );  
    if (smaller != nullptr)
    {                            //8
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    }
    else 
    {
        std::cout << "nullptr returned from T integer comparison: ensure int vals are not identical";
    }

    U myFirstU;
    float updatedValue = 5.f;
    std::cout << "[static func] convergeUVarsStatic's multiplied values: " << AddAndMultUvals::convergeUVarsStatic( myFirstU, updatedValue ) << std::endl;                  //11
    
    U mySecondU;
    std::cout << "[member func] convergeUVars's multiplied values: " << mySecondU.convergeUVars( updatedValue ) << std::endl;
}

        
        
        
        
        
        
        
