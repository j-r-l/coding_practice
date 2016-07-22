
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findKthLargest(vector<int>& v, int k)
{
    make_heap(v.begin(), v.end());
    // O(n)
    
    for (int n=0; n<k; ++n)
    {   pop_heap(v.begin(), v.end() - n);   }
    // O(k log n)
    
    int idx = v.size() - k;
    return v[idx];
}

int main(int argc, const char * argv[])
{
    vector<int> v;
    
    for (int n=0; n<7; n++)
    {   v.push_back(n); }
    
    random_shuffle(v.begin(), v.end());
    
    int kthlargest = findKthLargest(v, 2);
    
    return 0;
}
