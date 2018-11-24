#include <bits/stdc++.h>

using namespace std;
vector<vector<int>>path;
vector<bool>b;
int q[100000];
int gcount=0;

vector<string> split_string(string);
void dfs(int i)
{   if(b[i]==false)
    {
        //cout<<"i="<<i;
        gcount++;
    b[i]=true;
    for(int k=0;k<path[i].size();k++)
    {
        if(b[path[i][k]]==false)
        {
            //cout<<"abc"<<i<<" "<<k;
            dfs(path[i][k]);
        }
    }
    }
}
// Complete the roadsAndLibraries function below.
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
path.resize(n);
path={{0}};
b.resize(n);
b={false};
long tc=0;

for(int i=0;i<cities.size();i++)
{
    path[cities[i][0]-1].push_back(cities[i][1]-1);
    path[cities[i][1]-1].push_back(cities[i][0]-1);
}
for(int i=0;i<n;i++)
{
    if(b[i]==false)
    {gcount=0;
    dfs(i);
    //cout<<"here"<<gcount<<" ";
    if(gcount==1)
    {
        tc+=c_lib;
    }
    else if(c_lib<=c_road)
    {
        tc+=gcount*c_lib;
    }
    else{
        tc+=(gcount-1)*c_road+c_lib;
    }
    }
}
//cout<<"sh="<<tc;
return tc;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        int n = stoi(nmC_libC_road[0]);

        int m = stoi(nmC_libC_road[1]);

        int c_lib = stoi(nmC_libC_road[2]);

        int c_road = stoi(nmC_libC_road[3]);

        vector<vector<int>> cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        cout << result << "\n";
    }

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

