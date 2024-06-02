#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------------*/
string addTwoNumber(string num1, string num2) {
  if (num1 == "")
    return num2;
  if (num2 == "")
    return num1;
  reverse(num1.begin(), num1.end());
  reverse(num2.begin(), num2.end());
  int diff = num1.size() - num2.size();
  if (diff > 0)
    num2 += string(diff, '0');
  else
    num1 += string(abs(diff), '0');
  string ans = "";
  int carry = 0, sum = 0;
  for (int i = 0; i < num1.size(); i++) {
    sum = (num1[i] + num2[i] + carry - 96) % 10;
    carry = (num1[i] + num2[i] + carry - 96) / 10;
    ans += to_string(sum);
  }
  ans += to_string(carry);
  while (ans.back() == '0')
    ans.pop_back();
  reverse(ans.begin(), ans.end());
  return ans;
}
/*------------------------------------------------------------*/

/*------------------------------------------------------------*/

int main() { return 0; }
