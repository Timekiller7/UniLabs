#include <iostream>
#include "Stack.cpp"

int main()
{
    Stack <int> stack(5);

    //обработка исключения №1
    try {
        stack.pop();
    }
    catch( const char * str ) {
        cout << "Caught exception: " << str << endl;
    }

    for(int i = 0; i < 5; i++) {
        stack.push(i+1);
    }
    stack.show();

    //обработка исключения №2
    try {
        stack.push(6);
    }
    catch (bool) {
        cout << "\nPush can't be used at the moment" <<endl;
    }

    cout << "\nPOP 2 elements:\n";
    stack.pop();
    stack.pop();
    stack.show();

    return 0;
}
