#include <GUI/GUI.h>
#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;




void command()
{
    string cmd = "";
    while (cmd != "exit"){
        cout << ">";
        cin >> cmd;
    }
}


int main()
{
    std::cout.unsetf ( std::ios::floatfield );
    cout.precision(5);
    srand (time(nullptr));











    command();




    return 0;
}


