// P V T, if at least two r sure, they implement solution
// we know which is sure for each of n problems
// find number of problems they submit solutions for
// INPUT: n, each line then represents who is sure
#include <iostream>
#include <vector>
#include <array>
using namespace std;
bool submit(array<int, 3> sureVote)// for each line is a sureVote
{
    int sureness = 0;
    for(int i = 0; i < 3; i++)
    {
        if (sureVote[i] == 1)
            sureness++;
    }
    if (sureness >= 2)
        return true;
    else
        return false;
}
void printArray(array<int, 3> arr)
{
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i];
    }
}
array<int, 3> lineArray(string line)  //line -> length 3 int array
{
    //input exa: '1 0 1'
    int length = line.length(); //exa: 5
    array<int, 3> vote;//
    for (int i = 0; i < length; i++)
    {
        if (line[i] != ' ')// if not a space, so integer
            vote[i] = line[i]-'0';// put integer into vote array
    }
    cout << "lineStr: " << line << endl;
    cout << "vote: "; printArray(vote); cout << endl;
    return vote;
}
int main()
{
    int n = 0;
    cin >> n;
    vector<array<int, 3>> votes(n);// a vector of length n, of rows length 3
    for (int i = 0; i < n; i++)// fill votes[3][n]
    {
        string voteStr;
        cin >> voteStr;
        votes[i] = lineArray(voteStr);
        // row i of votes is replaced with int input
    }
    //loop through each row seeing if each is to be submitted
    int submitted = 0;
    for (int i = 0; i < n; i++)
    {
        if (submit(votes[i]) == true)
            submitted++;
    }
    cout << "They submitted " << submitted << " of their problems" << endl;
}
