#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set; // find_by_order, order_of_key

int main() {
  ordered_set o_set; // declaration

  // Inserting elements - 1st query
  o_set.insert(1);
  o_set.insert(10);
  o_set.insert(2);
  o_set.insert(7);
  o_set.insert(2); // ordered set only contains unique values

  // o_set contains
  cout << "o_set = ";
  for (auto i : o_set)
    cout << i << " ";
  cout << "\n\n";

  // finding kth element - 4th query
  cout << "0th element: " << *o_set.find_by_order(0) << "\n";
  cout << "1st element: " << *o_set.find_by_order(1) << "\n";
  cout << "2nd element: " << *o_set.find_by_order(2) << "\n";
  cout << "3rd element: " << *o_set.find_by_order(3) << "\n";
  cout << "\n";

  // finding number of elements smaller than X - 3rd query
  cout << "No. of elems smaller than 6: " << o_set.order_of_key(6) << "\n"; // 2
  cout << "No. of elems smaller than 11: " << o_set.order_of_key(11)
       << "\n";                                                             // 4
  cout << "No. of elems smaller than 1: " << o_set.order_of_key(1) << "\n"; // 0
  cout << "\n";

  // lower bound -> Lower Bound of X = first element >= X in the set
  cout << "Lower Bound of 6: " << *o_set.lower_bound(6) << "\n";
  cout << "Lower Bound of 2: " << *o_set.lower_bound(2) << "\n";
  cout << "\n";

  // Upper bound -> Upper Bound of X = first element > X in the set
  cout << "Upper Bound of 6: " << *o_set.upper_bound(6) << "\n";
  cout << "Upper Bound of 2: " << *o_set.upper_bound(2) << "\n";
  cout << "\n";

  // // Remove elements - 2nd query
  o_set.erase(1);
  o_set.erase(11); // element that is not present is not affected

  // o_set contains
  cout << "o_set = ";
  for (auto i : o_set)
    cout << i << " ";
  cout << "\n";
}
