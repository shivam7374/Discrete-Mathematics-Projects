#include<iostream>
#include<string>
using namespace std;
int main()
{
    cout<<"Enter number of Queries to be entered : ";
    int n;
    cin>>n;
    cout<<"Strings whose next permutation is required."<<endl;
    while(n--)
    {
        cout<<"Enter string : ";
        int j=-1;
		string s;
        cin>>s;
        string b(s);
        int t=s.size();
        for(int i=0;i<t-1;i++)
        {
        if(s[i]<s[i+1])
        {
            j=i;
        }
        }
        if(j==-1)
        {
        cout<<"No more permutations possible. This was last permutation"<<endl;
        continue;
        }

        for(int k=j+1;k<t;k++)
        {
        if(s[j]>=s[k])
        {
            int temp=s[j];
            s[j]=s[k-1];
            s[k-1]=temp;
            break;
        }
        else if(k==t-1)
        {
            int temp=s[j];
            s[j]=s[k];
            s[k]=temp;
        }
        }
        int l=t-1;
        for(int i=j+1;i<=(j+t)/2;i++)
        {
            int temp=s[i];
            s[i]=s[l];
            s[l]=temp;
            l--;
		 }
        cout<<"The next permutation of string  "<<b<<" is "<<s<<"."<<endl;
        
    }
    return 0;
}