#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
bool ismagicsq(vector<int> v);
void getmagicsq(vector<vector<int> >& magic_squares) 
{  
    vector<int> v(9); 
  
    // Initialing the vector 
    for (int i = 0; i < 9; ++i) 
        v[i] = i + 1; 
  
    // Producing all permutation of vector 
    // and checking if it denote the magic square or not. 
    do { 
        if (ismagicsq(v)) { 
            magic_squares.push_back(v); 
        }
    } while (next_permutation(v.begin(), v.end())); 
} 

bool ismagicsq(vector<int> v)
{
    int a[3][3]; 

    int sum=0,tsum=0;  
    // Convert vector into 3 X 3 matrix 
    for (int i = 0; i < 3; ++i)  
        for (int j = 0; j < 3; ++j)  
            a[i][j] = v[3 * i + j];  
    
    for(int i=0;i<3;i++)
    sum=sum+a[0][i];

    for(int i=0;i<3;i++)
    {
        tsum=0;
        for(int j=0;j<3;j++)
        tsum=tsum+a[i][j];
        
        if(tsum!=sum)
        return false;
     }


    for(int i=0;i<3;i++)
    {
        tsum=0;
        for(int j=0;j<3;j++)
        tsum=tsum+a[j][i];
        if(tsum!=sum)
        return false;
    }

    tsum=0;
    for(int i=0;i<3;i++)
    {
        tsum=tsum+a[i][i];
    }
    if(tsum!=sum)
        return false;

    tsum=0;
    for(int i=0,j=2;i<3;i++,j--)
    {
        tsum=tsum+a[i][j];
    }
    if(tsum!=sum)
        return false;
 
   
     return true;    

}

int diff(vector<int> a,vector<int> b)
{
    int sum=0;
    for(int i=0;i<8;i++)
    sum=sum+abs(a[i]-b[i]);

    return sum;

}
// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {
    vector<vector<int>> magicsquares;
    getmagicsq(magicsquares);  

    vector<int> v(9);
    int k=0;
    for(int i=0;i<3;i++)
     for(int j=0;j<3;j++)
        v[k++]=s[i][j];
    int m=999;
    for(int i=0;i<magicsquares.size();i++)
    {
    	
         m=min(m,diff(magicsquares[i],v));

    }
    for(int i=0;i<magicsquares.size();i++)
    {
		for(int j=0;j<9;j++)
		{
			cout<<" "<<magicsquares[i][j];
		}
		cout<<endl;
    }
        return m;
    }



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    cout << result << "\n";

    fout.close();

    return 0;
}

