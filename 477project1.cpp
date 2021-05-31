#include<bits/stdc++.h>
using namespace std;

vector<double> merger(vector<double>left, vector<double>right)
{
    vector<double>result;
    while(left.size()>0 || right.size()>0)
    {
        if(left.size()>0 && right.size()>0)
        {
            if(left.front()<= right.front())
            {
                result.push_back(left.front());
                left.erase(left.begin());
            }
            else
            {
                result.push_back(right.front());
                right.erase(right.begin());

            }
        }
        else if(left.size()>0)
        {
            for(int i=0; i<left.size(); i++)
            {
                result.push_back(left[i]);
            }
            break;

        }
        else if(right.size()>0)
        {
            for(int i=0; i<right.size(); i++)
            {
                result.push_back(right[i]);
            }
            break;
        }
    }
    return result;
}
vector<double> mergesort(vector<double>m)
{
    if(m.size()<=1)
    {
        return m;
    }
    vector<double> left, right, result;
    int middle= (m.size()+1)/2;
    for (int i= 0; i<middle; i++)
    {
        left.push_back(m[i]);
    }
    for (int i= middle; i<m.size(); i++)
    {
        right.push_back(m[i]);
    }
    left= mergesort(left);
    right= mergesort(right);
    result= merger(left,right);
    return result;

}

int smoothingbymeans(vector<double>v,size_t n)
{
    v= mergesort(v);
    double counter=1,i,sum,temp,last,avg;
    while(!v.empty())
    {
        if(v.size()==1)
        {
            cout<<"bin"<<counter<<":";
            last= v.front();
            cout<<last<<endl;
            v.erase(v.begin());
        }

        else if(n<=v.size())
        {
            sum=0;
            for(i=0; i<n; i++)
            {
                sum+=v.front();
                v.erase(v.begin());
            }

            avg= sum/n;
            cout<<"bin"<<counter<<":";
            for(i=0; i<n-1; i++)
            {
                cout<<avg<<",";
            }
            cout<<avg<<endl;
            counter++;

        }
        else
        {
            size_t a;
            a= v.size();
            sum=0;
            for(i=0; i<a; i++)
            {
                sum+=v.front();
                v.erase(v.begin());

            }
            avg= sum/a;
            cout<<"bin"<<counter<<":";
            for(i=0; i<a-1; i++)
            {
                cout<<avg<<",";
            }
            cout<<avg<<endl;
            counter++;
        }

    }

}
int smoothingbyboundaries(vector<double>v,size_t n)
{
    v= mergesort(v);
    size_t counter=1,i;
    vector<double> v1;
    double temp,last,current,minresult,maxresult,result,minimum, maximum;
    while(!v.empty())
    {
        if(v.size()==1)
        {
            cout<<"Bin"<<counter<<":";
            last= v.front();
            cout<<last<<endl;
            v.erase(v.begin());
        }
        else if(n<=v.size())
        {
            cout<<"Bin"<<counter<<":";
            minimum= v.front();
            maximum= v.at(n-1);
            for(i=0; i<n; i++)
            {
                current= v.front();
                minresult= abs(minimum-current);
                maxresult= abs(maximum- current);
                if(minresult<=maxresult)
                {
                    v1.push_back(minimum);
                }
                else
                {
                    v1.push_back(maximum);
                }
                v.erase(v.begin());
            }
            /*for(i=0; i<v1.size(); i++)
            {
                cout<<v1[i];
            }*/
            for(i=0; i<v1.size(); i++)
            {
                cout<<v1.front()<<",";
                v1.erase(v1.begin());
            }

            cout<<v1.front();
            v1.erase(v1.begin());


            cout<<endl;
            counter++;

        }
        else
        {
            int len=v.size();
            cout<<"Bin"<<counter<<":";
            minimum= v.front();
            maximum= v.at(len-1);
            for(i=0; i<len; i++)
            {
                current= v.front();
                minresult= abs(minimum-current);
                maxresult= abs(maximum- current);
                if(minresult<=maxresult)
                {
                    v1.push_back(minimum);
                }
                else
                {
                    v1.push_back(maximum);
                }
                v.erase(v.begin());
            }
            for(i=0; i<v1.size(); i++)
            {
                cout<<v1.front()<<",";
                v1.erase(v1.begin());
            }

            cout<<v1.front();
            v1.erase(v1.begin());


            cout<<endl;
            counter++;

        }

    }

}
int main()
{
    while(1)
    {
        string s;
        vector<double>v;
        cout<<"Input Data: ";
        cin>>s;
        stringstream str(s);
        for(double i; str>>i;)
        {
            v.push_back(i);
            if(str.peek()== ',')
            {
                str.ignore();
            }
        }
        size_t binSize;
        int choice;
        cout<<endl;
        cout<<"Bin size:";
        cin>>binSize;
        cout<<endl;
        cout<<"Choice:";
        cin>>choice;
        if(choice==1)
        {
            smoothingbymeans(v,binSize);
            cout<<endl;
        }
        else if(choice==2)
        {
            smoothingbyboundaries(v,binSize);
            cout<<endl;
        }

    }
}
