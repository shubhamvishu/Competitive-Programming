//https://www.hackerrank.com/challenges/richie-rich/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);


string highestValuePalindrome(string s, int n, int k) {

    int i=0,j=s.length()-1,m,c=0;
    while(j>i)
    {
        if(s[i]!=s[j])
            c++;
        i++;
        j--;
    }
    cout<<c<<" "<<k;
    int l=k-c;
    if(c>k)
    {
        return "-1";
        //exit(0);
    }    
    m=k,i=0,j=s.length()-1;
 
    while(j>=i && m>0)
    {   if(i==j)
       {
          s[i]='9';
         m--;
       }
        if(s[i]!='9' && s[j]!='9' && s[i]!=s[j] && l>0)
        {
            s[i]='9';s[j]='9';
            l--;
            m=m-2;
        }
       else if(s[i]!='9' && s[j]!='9' && s[i]==s[j] && l>1)
        {
            s[i]='9';s[j]='9';
            l=l-2;;
            m=m-2;
        }
        else if(s[i]!='9' && s[j]!='9' && s[i]!=s[j] && l<=0)
        {
           if(s[i]>=s[j])
              s[j]=s[i];
            else if(s[j]>s[i])
                s[i]=s[j];
            
            m--;
        }
       else if(s[i]=='9' && s[j]=='9')
       {  }
        else if(s[i]=='9' || s[j]=='9')
        {
            s[i]='9';
            s[j]='9';
            m--;
        }
        i++;
        j--;
    }
    return s;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string s;
    getline(cin, s);

    string result = highestValuePalindrome(s, n, k);

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

