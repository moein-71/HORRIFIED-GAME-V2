#include "Programm.hpp"
#include <stdexcept>

using namespace std ;

int main() {

    try{ // we need more
        Program p ;
        p.Start() ;

        while (!p.End())
        {
            p.Run() ;
        }
    }
    catch(bad_alloc & s) {
        cout<< "you have bad alloc\n" ;
    }
    catch(runtime_error & s) {
        cout<< s.what() << '\n' ;
    }
    catch(logic_error & s) {
        cout<< s.what() << '\n' ;
    }
    catch(exception & s) {
        cout<< s.what() << '\n' ;
    }

    return 0 ;
}
