//https://www.hackerrank.com/challenges/hackerland-radio-transmitters/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);


int hackerlandRadioTransmitters(vector<int> x, int k) {
    vector<int>v1;
    vector<int>::iterator it;
    int a=0;
    for(int i:x)
    {
        if(find(v1.begin(),v1.end(),i)==v1.end())
            v1.push_back(i);
    }
    int i=0;
    sort(v1.begin(),v1.end());
    while(i<v1.size())
    {
        if(i==v1.size()-1)
        {
            a++;
            break;
        }
        int j=i;
        bool f=false;
        while((v1[j+1]-v1[i])<=k && j+1<v1.size())
        {
            j++;
        }
        if(i==j)
        {
            a++;
            i++;
            j=i;
            f=true;
        }
        else
        {
            i=j;
        }
        if(!f)
        {
            while(v1[j+1]-v1[i]<=k && j+1<v1.size())
            {
                j++;
            }
            if(i==j)
            {  a++;
               i++;
               j=i;
             }
            else
            {  a++;
               i=j;
               i++;
            }
        }
        
        
    }
    
    return a;
    

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string x_temp_temp;
    getline(cin, x_temp_temp);

    vector<string> x_temp = split_string(x_temp_temp);

    vector<int> x(n);

    for (int i = 0; i < n; i++) {
        int x_item = stoi(x_temp[i]);

        x[i] = x_item;
    }

    int result = hackerlandRadioTransmitters(x, k);

    fout << result << "\n";

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

