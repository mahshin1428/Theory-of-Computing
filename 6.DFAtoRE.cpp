#include <bits/stdc++.h>
using namespace std;

#define STATES 3
#define SYMBOLS 2

string dfa_transition[STATES][SYMBOLS+1];

void readInput()
{
    for(int i=0; i<STATES; i++)
    {
        for(int j=0; j<SYMBOLS + 1; j++)
        {
            cin>>dfa_transition[i][j];
        }
    }
}

int main()
{
    int k = 0;
    string RE[STATES][STATES][STATES];
    string Transition[STATES][STATES];

    freopen("6 input.txt", "r", stdin);
    readInput();

    for(int i=0; i<STATES; i++)
    {
        if(dfa_transition[i][1] == "q0")
            Transition[i][0] = "0";
        else if(dfa_transition[i][2] == "q0")
            Transition[i][0] = "1";
        else
            Transition[i][0] = "#";

        if(dfa_transition[i][1] == "q1")
            Transition[i][1] = "0";
        else if(dfa_transition[i][2] == "q1")
            Transition[i][1] = "1";
        else
            Transition[i][1] = "#";

        if(dfa_transition[i][1] == "q2")
            Transition[i][2] = "0";
        else if(dfa_transition[i][2] == "q2")
            Transition[i][2] = "1";
        else
            Transition[i][2] = "#";

    }

    for(int i=0; i<STATES; i++)
    {
        for(int j=0; j<STATES; j++)
        {
            cout<<Transition[i][j]<<" ";
        }
        cout<<endl;
    }

/*
    string Transition[STATES][STATES] = {
        {"1", "0", "#"},
        {"1", "#", "0"},
        {"#", "1", "0"}
    };
*/

    for(int i=0; i<STATES; i++)
    {
        if(Transition[i][i] != "#")
            RE[i][i][0] = "e + ";
        for(int j=0; j<STATES; j++)
        {
            RE[i][j][0] += Transition[i][j];
            if(RE[i][i][0] == "#") RE[i][i][0] = "e";
        }
    }

/*
    // Initialize base cases for k = 0
    RE[0][0][0] = "e + 1";
    RE[0][1][0] = "0";
    RE[0][2][0] = "#";
    RE[1][0][0] = "1";
    RE[1][1][0] = "e";
    RE[1][2][0] = "0";
    RE[2][0][0] = "#";
    RE[2][1][0] = "1";
    RE[2][2][0] = "0 + e";
*/

    for(int i=0; i<STATES; i++)
        for(int j=0; j<STATES; j++)
            cout<<"R"<< i << j<<"(0) = " + RE[i][j][0]<<endl;




    k = 1;
    for(int i=0; i<STATES; i++)
        for(int j=0; j<STATES; j++)
                if(RE[i][k][k-1] == "#" || RE[k][k][k-1] == "#" || RE[k][j][k-1] == "#")
                {
                    RE[i][j][k] = RE[i][j][k-1];
                }else
                {
                    RE[i][j][k] = RE[i][j][k-1] + " + (" + RE[i][k][k-1] + ")(" + RE[k][k][k-1] + ")*(" + RE[k][j][k-1] + ")";
                }


    // Print Rij(1)
    for(int i=0; i<STATES; i++)
        for(int j=0; j<STATES; j++)
            cout<<"R"<< i << j<<"(1) = " + RE[i][j][1]<<endl;




    cout<<endl<<endl;


    k = 2;
    for(int i=0; i<STATES; i++)
        for(int j=0; j<STATES; j++)
                if(RE[i][k][k-1] == "#" || RE[k][k][k-1] == "#" || RE[k][j][k-1] == "#")
                {
                    RE[i][j][k] = RE[i][j][k-1];
                }else
                {
                    RE[i][j][k] = RE[i][j][k-1] + " + (" + RE[i][k][k-1] + ")(" + RE[k][k][k-1] + ")*(" + RE[k][j][k-1] + ")";
                }


    // Print Rij(2)
    for(int i=0; i<STATES; i++)
        for(int j=0; j<STATES; j++)
            cout<<"R"<< i << j<<"(2) = " + RE[i][j][2]<<endl;



    return 0;
}



