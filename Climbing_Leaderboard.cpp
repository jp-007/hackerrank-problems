#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the climbingLeaderboard function below.
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {

    sort(scores.begin(),scores.end(),greater<int>());
    vector<int> v,final,demo,demo1;

    v.push_back(0);
    int j=0;
    for(int i=0;i<scores.size();i++)
    {
        if(v[j]!=scores[i])
        {
            v.push_back(scores[i]);
            j++;
        }
    }



    int k=0,l=1,g=(v.size()-2),x,tag=0;

    for(int i=0;i<alice.size();i++)
    {   
        
        l=1,g=(v.size()-2);
        x=0;
        while(l<=g)
        {
            x=l+(g-l)/2;
            if(v[x]==alice[i])
            {
                final.push_back(x);
                demo.push_back(v[x]);
                demo1.push_back(x);
                break;
            }else if(v[x]>alice[i])
            {
                 l=x+1;
            }else
            {
                 g=x-1;
            }
        }
        
        if(v[x]>alice[i])
        {
            while(v[x]>alice[i] && x<=scores.size()-1)
            {
                x++;
            }
            final.push_back(x);
            demo.push_back(v[x]);
            demo1.push_back(x);
            continue;
        }

        if(v[x]<alice[i])
        {
            while(v[x]<alice[i] && x>=1)
            {
                x--;
            }
            final.push_back(x+1);
            demo.push_back(v[x]);
            demo1.push_back(x);
        }
            
     }

//     
    return final;
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    freopen("input.txt","r",stdin);
    int scores_count;
    cin >> scores_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(scores_count);

    for (int i = 0; i < scores_count; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    int alice_count;
    cin >> alice_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string alice_temp_temp;
    getline(cin, alice_temp_temp);

    vector<string> alice_temp = split_string(alice_temp_temp);

    vector<int> alice(alice_count);

    for (int i = 0; i < alice_count; i++) {
        int alice_item = stoi(alice_temp[i]);

        alice[i] = alice_item;
    }

    vector<int> result = climbingLeaderboard(scores, alice);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
