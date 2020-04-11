#include<iostream>
#include<string>
#include<map>
using namespace std;
void intersect(string a,string b,map<char,int> m1,map<char,int> m2,map<char,int> res)
{	cout<<"Intersection of Set A and B is : ";
    for(int i=0;i<a.size();i++)
    {
        if(res[a[i]]==0)
        {

            int counts=0;
            if(m1[a[i]]>0&&m2[a[i]]>0)
            {
                counts=min(m1[a[i]],m2[a[i]]);
                for(int j=0;j<counts;j++)
                {
                    cout<<a[i]<<" ";
                }
            }
            res[a[i]]=1;
        }
    }
    for(int i=0;i<b.size();i++)
    {
        if(res[b[i]]==0)
        {

            int counts=0;
            if(m1[b[i]]>0&&m2[b[i]]>0)
            {
                counts=min(m1[a[i]],m2[a[i]]);
                for(int j=0;j<counts;j++)
                {
                    cout<<b[i]<<" ";
                }
            }
            res[b[i]]=1;
        }
    }
    cout<<endl;
}
void uunion(string a,string b,map<char,int> m1,map<char,int> m2,map<char,int> res)
{
	cout<<"Union of Set A and B is : ";
    for(int i=0;i<a.size();i++)
    {
        if(res[a[i]]==0)
        {

            int counts=max(m1[a[i]],m2[a[i]]);
            for(int j=0;j<counts;j++)
            {
                cout<<a[i]<<" ";
            }
            res[a[i]]=1;
        }

    }
    for(int i=0;i<b.size();i++)
    {
        if(res[b[i]]==0)
        {

            int counts=max(m2[b[i]],m1[b[i]]);

            for(int j=0;j<counts;j++)
            {
                cout<<b[i]<<" ";
            }
            res[b[i]]=1;
        }

    }
    cout<<endl;
}

void sum(string a,string b,map<char,int> m1,map<char,int> m2,map<char,int> res)
{
	cout<<"Sum of Set A and B is : ";
    for(int i=0;i<a.size();i++)
    {
        if(res[a[i]]==0)
        {
            int counts=0;
            counts=m1[a[i]]+m2[a[i]];
            for(int j=0;j<counts;j++)
            {
                cout<<a[i]<<" ";
            }
            res[a[i]]=1;
        }

    }
    for(int i=0;i<b.size();i++)
    {
        if(res[b[i]]==0)
        {
            int counts=0;
            counts=m1[b[i]]+m2[b[i]];
            for(int j=0;j<counts;j++)
            {
                cout<<b[i]<<" ";
            }
            res[b[i]]=1;
        }

    }
    cout<<endl;
}

void differenceab(string a,string b,map<char,int> m1,map<char,int> m2,map<char,int> res)
{
	cout<<"Difference of Set A and B is : ";
    for(int i=0;i<a.size();i++)
    {
        if(res[a[i]] ==0)
        {

            int counts=0;
            counts=max(m1[a[i]]-m2[a[i]],0);
            for(int j=0;j<counts;j++)
            {
                cout<<a[i]<<" ";
            }
            res[a[i]]=1;
        }
    }
    cout<<endl;
}

void differenceba(string a,string b,map<char,int> m1,map<char,int> m2,map<char,int> res)
{
	cout<<"Difference of Set B and A is : ";
    for(int i=0;i<b.size();i++)
    {
        if(res[b[i]] ==0)
        {

            int counts=0;
            counts=max(m2[b[i]]-m1[b[i]],0);
            for(int j=0;j<counts;j++)
            {
                cout<<b[i]<<" ";
            }
            res[b[i]]=1;
        }
    }
    cout<<endl;
}
int main()
{	
    string s1,s2;
    cout<<"Enter the elements of set A : ";
    cin>>s1;
    cout<<endl<<"Enter the elements of set B : ";
    cin>>s2;
    cout<<endl;

    map<char,int> m1,m2,res;
    for(int i=0;i<s1.size();i++)
    {
        m1[s1[i]]++;
    }
    for(int i=0;i<s2.size();i++)
    {
        m2[s2[i]]++;
    }
    char r='y';
    while(r=='y')
    {
        cout<<"Enter the choice as given the following list \n1)Intersection\n2)Union\n3)Addition\n4)A-B\n5)B-A\n";
        int c;
        cin>>c;
        if(c==1)
        {
            intersect(s1,s2,m1,m2,res);
        }
        if(c==2)
        {
            uunion(s1,s2,m1,m2,res);
        }
        if(c==3)
        {
            sum(s1,s2,m1,m2,res);
        }
        if(c==4)
        {
            differenceab(s1,s2,m1,m2,res);
        }
        if(c==5)
        {
            differenceba(s1,s2,m1,m2,res);
        }
        cout<<endl<<"For further results press? (y/n)\n";
        cin>>r;
    }
    return 0;
}
