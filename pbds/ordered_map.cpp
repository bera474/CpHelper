#include <bits/stdc++.h>
using namespace std;

// A new data structure is defined
// Please refer https : // goo.gl/WVDL6g

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_map;


int main() {
  ordered_map om;

  om.insert({23, 20});
  om.insert({23, 10});
  om.insert({23, 30});
  om.insert({12, 35});
  om.insert({12, 22});
  // Another method to insert pair
  // om.insert(make_pair(23, 20));

  // Print the contents of the map
  cout << "Contents of map:\n";
  cout << "KEY\tELEMENT\n";
  for (auto it : om) {
    cout << it.first << "\t" << it.second << "\n";
  }
  cout << "\n";

  // value at 3rd index in sorted array.
  cout << "The value at 3rd index is "
       << "{" << om.find_by_order(3)->first << ", "
       << om.find_by_order(3)->second << "}\n";

  // Index of pair {23, 30}
  cout << "The index of pair {23, 30} is " << om.order_of_key({23, 30}) << endl;

  // Pair {23, 40} is not in the map but it will show the
  // index number if it was there in sorted array
  cout << "The index of pair {23, 40} is " << om.order_of_key({23, 40}) << endl;

  cout << "\nContents of map:\n";
  cout << "KEY\tELEMENT\n";
  for (auto itr = om.begin(); itr != om.end(); ++itr) {
    cout << itr->first << "\t" << itr->second << "\n";
  }
  cout << "\n";
  return 0;
}