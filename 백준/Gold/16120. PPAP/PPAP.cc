// Stack
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    string PPAP;
    bool clearPPAP = false;
    cin >> PPAP;

    stack<char> PPAPStack;

    for (const char& PPAPChar : PPAP){
        PPAPStack.push(PPAPChar);
        if (clearPPAP && PPAPStack.top() == 'P' && PPAPStack.size() >= 4){
            for (int i = 0; i < 2; i++)
                PPAPStack.pop();
            if (PPAPStack.top() == 'P' && PPAPStack.size() >= 2)
                PPAPStack.pop();
            else    break;
            clearPPAP = false;
        }
        else if (clearPPAP)
            break;

        if (PPAPChar == 'A')
            clearPPAP = true;
    }

    if (PPAPStack.top() == 'P' && PPAPStack.size() == 1)
        cout << "PPAP";
    else
        cout << "NP";

    return 0;
}