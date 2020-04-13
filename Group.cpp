#include<iostream>
#include<map>
using namespace std;
map<float,int> m;
bool Closure_Property(float a[],char operate,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            
            float result;
            if(operate=='+')
            {
                result=(a[i]+a[j]);
            }
            else if(operate=='-')
            {
                result=(a[i]-a[j]);
            }
            else if(operate=='*')
            {
                result=(a[i]*a[j]);
            }
            else if(operate=='/')
            {
                if(a[i]==0||a[j]==0)
                {
                    return false;
                }
                result=(a[i]/a[j]);
            }
            if(m[result]==0)
            {
                return false;
            }
        }
    }
    return true;
}
bool Associative_Property(float a[],char operate,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            
            for(int k=0;k<n;k++)
            {
                
                if(operate=='+')
                {
                    if(((a[i]+a[j])+a[k])!=(a[i]+(a[j]+a[k])))
                    {
                        return false;
                    }
                }
                else if(operate=='-')
                {
                    if(((a[i]-a[j])-a[k])!=(a[i]-(a[j]-a[k])))
                    {
                        return false;
                    }
                }
                else if(operate=='*')
                {
                    if(((a[i]*a[j])*a[k])!=(a[i]*(a[j]*a[k])))
                    {
                        return false;
                    }
                }
                else if(operate=='/')
                {
                    if(a[i]==0||a[j]==0)
                    {
                        return false;
                    }
                    if(((a[i]/a[j])/a[k])!=(a[i]/(a[j]/a[k])))
                    {
                        return false;
                    }
                }

            }
        }
    }
    return true;
}
bool Identity_Element(float a[],char operate,int n)
{
    if(operate=='+')            
    {
        if(m[0]>=1)
        {
            return true;
        }
        else
            return false;
    }
    else if(operate=='-')       
    {
        if(m[0]>=1)
        {
            return true;
        }
        else
            return false;
    }
    else if(operate=='*')
    {
        if(m[1]>=1) 
        {
            return true;
        }
        else
            return false;
    }
    else if(operate=='/')           
    {
        if(m[1]>=1)
        {
            return true;
        }
        else
            return false;
    }
}
bool Inverse_Property(float a[],char operate,int n)
{
    for(int i=0;i<n;i++)
    {
        if(operate=='+')
        {
            if(m[-(a[i])]==0)
            {
                return false;
            }
        }
        else if(operate=='-')
        {
            if(m[-(a[i])]==0)
            {
                return false;
            }
        }
        else if(operate=='*')
        {
            if(m[float(1/a[i])]==0)
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{	cout<<"Chose any one method  of the below list to check wheter a given set is group or not ."<<endl;
	cout<<"Enter 1 to input the set from the given list "<<endl;
	cout<<"Enter 2 to input the set manually by entering the number of elements"<<endl;
		int input;
		cin>>input;
			if(input==1)
			{	int choice;
				cout<<"Enter the choice to chose the set from the given list"<<endl;
				cout<<"Enter 1 for set of Integers"<<endl;
				cout<<"Enter 2 for set of Natural Numbers"<<endl;
				cout<<"Enter 3 for set of Real Numbers"<<endl;
				cout<<"Enter 4 for set of Positive Real Numbers"<<endl;
				cout<<"Enter 5 for set of Negative Real Numbers"<<endl;
				cin>>choice;
				cout<<"Enter the operator from (+,/,*,-)"<<endl;
				char oper;
				cin>>oper;
				if(oper=='/')
				{
					cout<<"The given set is Not a Group"<<endl;
				}
				else
				{
					if(oper=='*' && (choice==3 || choice==4))
					{
						cout<<"The given set is a group"<<endl;
					}
					else if( (oper=='+' || oper=='-') && ( choice==1 || choice==3))
					{
						cout<<"The given set is a group"<<endl;	
					}
					
				}

			}
			if(input==2)
			{
				cout<<"Enter the number of elements of the set which you want to enter :  ";
			    int n;
			    cin>>n;
			    float a[n];
			    cout<<"Enter the elements of the set and then the operator associated with the set that is "<<"+,-,*,/"<<endl;
			    for(int i=0;i<n;i++)
			    {
			        cin>>a[i];
			        m[a[i]]++;
			    }
			    char operate;
			    cin>>operate;
			    int flag=0;
			    if(Closure_Property(a,operate,n))
			    {	
			    	flag++;
			        cout<<"The group shows Closure Property"<<endl;
			    }
			    else
			    {
			    cout<<"The group does not shows Closure Property"<<endl;
			    }
			    if(Associative_Property(a,operate,n))
			    {
			    	flag++;
			        cout<<"The group shows Associative Property"<<endl;
			    }
			    else
			    {
			    cout<<"The group does not shows Associative Property"<<endl;
			    }
			    if(Identity_Element(a,operate,n))
			    {
			    	flag++;
			        cout<<"Every element of group has Identity element. "<<endl;
			    }
			    else
			    {
			    cout<<"Every element of group does not has Identity element. "<<endl;
			    }
			    if(Inverse_Property(a,operate,n))
			    {
			    	flag++;
			        cout<<"Every element of group shows Inverse Property"<<endl;
			    }
			    else
			    {
			    cout<<"Every element of group does not shows Inverse Property"<<endl;
			    }
			    
			    if(flag==4)
			    {
			    	cout<<"The given set is a group"<<endl<<endl;
			    }
			    else
			    {
			        cout<<"The given set is Not a group"<<endl<<endl;
			    }

			}




    return 0;
}
