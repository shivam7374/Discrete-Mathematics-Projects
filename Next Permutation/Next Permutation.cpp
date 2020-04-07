#include <iostream> 
using namespace std; 
int binarysearch(string& s, int l, int r, int key) 
{ 
    int idx = -1; 
    while (l <= r) { 
        int mid = l + (r - l) / 2; 
        if (s[mid] <= key) 
            r = mid - 1; 
        else { 
            l = mid + 1; 
            if (idx == -1 || s[idx] >= s[mid]) 
                idx = mid; 
        } 
    } 
    return idx; 
} 
void reverse_string(string& s, int l, int r) 
{ 
    while (l < r) 
    {
        swap(s[l], s[r]);
        l++;
        r--; 
    }
}  
bool nextpermutation(string& s) 
{ 
    int len = s.length(), i = len - 2; 
    while (i >= 0 && s[i] >= s[i + 1]) 
        {
            --i;
        } 
    if (i < 0) 
       {    // Last permutation
        return 0;
        } 
    else 
    { 

        int idx = binarysearch(s, i + 1, len - 1, s[i]); 
        swap(s[i], s[idx]); 
        reverse_string(s, i + 1, len - 1); 
        return 1; 
    } 
} 
int main() 
{   cout<<endl<<"Enter the Number of Queries : ";
    int n;
    cin>>n;
    while(n--)
    {
    cout<<endl<<"Enter the string : ";   
    string a;
    cin>>a;
    string b(a);
    if (!nextpermutation(a)) 
        cout << "No more permutations possible. This was last permutation" << endl; 
    else
        cout<<"The next permutation of string  "<<b<<" is "<<a<<"."<<endl; 
    }
    return 0; 
} 