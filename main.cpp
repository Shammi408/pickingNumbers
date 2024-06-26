#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'pickingNumbers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int pickingNumbers(vector<int> a) {
  
    vector<int>b; // to store the max length of sub arrays
 
 for(int i=0;i<a.size();i++){ // picks a index 
     int low=0;  
     int high=0;
     int val=0;
     for(int j=0;j<a.size();j++){ // compares the picked index to every other indices
        val=a[i];
        if(val==a[j]-1  ){   // picked index is 1 less
            high++;
        } else if( val ==a[j]+1){ // picked index is 1 high
            low++;
        }  else if(val ==a[j]){ // picked index is equal
            high++;
            low++;
        }
     }
     if(high>low){   // push the higher value in b.
         b.push_back(high); 
     }else{
         b.push_back(low);
     }
 }
    int max=0;   
    for(int i : b){   // return the max value in b
        if(max<i){
            max=i;
        }
    }
    return max;
}
       


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = pickingNumbers(a);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
