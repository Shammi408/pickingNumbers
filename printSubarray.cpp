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

vector<int> pickingNumbers(vector<int> a) {
  vector<vector<int>> b;

  for (int i = 0; i < a.size(); i++) { //4 6 5 3 3 1
    vector<int> low = {};
    vector<int> high = {};
    int val = a[i];

    for (int j = 0; j < a.size(); j++) {

      if (val == a[j] - 1) {
        high.push_back(a[j]);
      } else if (val == a[j] + 1) {
        low.push_back(a[j]);
      } else if (val == a[j]) {
        high.push_back(a[j]);
        low.push_back(a[j]);
      }
    }
    if (high.size() > low.size()) {
      b.push_back(high);
    } else {
      b.push_back(low);
    }
  }

  int len = 0;
  int index = 0;
  for (int i = 0; i < b.size(); i++) {
    if (len < b[i].size()) {
      len = b[i].size();
      index = i;
    }
  }
  return b[index];
}

int main() {
  // ofstream fout(getenv("OUTPUT_PATH"));

  // string n_temp;
  // getline(cin, n_temp);

  // int n = stoi(ltrim(rtrim(n_temp)));

  // string a_temp_temp;
  // getline(cin, a_temp_temp);

  // vector<string> a_temp = split(rtrim(a_temp_temp));

  // vector<int> a(n);

  // for (int i = 0; i < n; i++) {
  //     int a_item = stoi(a_temp[i]);

  //     a[i] = a_item;
  // }
  // vector<int> a = {4, 6, 5, 3, 3, 1};
    vector<int> a ={1,1,2,2,4,4,5,5,5};
  vector<int> result = pickingNumbers(a);

  // fout << result << "\n";
  // fout.close();

  for (int i : result) {
    cout << i << " ";
  }

  return 0;
}

string ltrim(const string &str) {
  string s(str);

  s.erase(s.begin(),
          find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string &str) {
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

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
