#include<bits/stdc++.h>
using namespace std;
int smoothingbymeans(vector<int>v,size_t n)
{
    sort(v.begin(),v.end());
    double counter=1,i,sum,temp,last,avg;
    queue<int>q1;
    queue<int>q;
    for(i=0; i<v.size(); i++)
    {
        q.push(v[i]);

    }
    while(!q.empty())
    {
        if(q.size()==1)
        {
            cout<<"bin"<<counter<<":";
            last= q.front();
            cout<<last<<endl;
            q.pop();
        }

        else if(n<q.size())
        {
            sum=0;
            for(i=0; i<n; i++)
            {
                temp=q.front();
                q1.push(temp);
                q.pop();
            }

            while(!q1.empty())
            {

                sum+=q1.front();
                q1.pop();
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
            a= q.size();
            sum=0;
            for(i=0; i<a; i++)
            {
                q1.push(q.front());
                q.pop();
            }
            while(!q1.empty())
            {
                sum+=q1.front();
                q1.pop();
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
int smoothingbyboundaries(vector<int>v,size_t n)
{
    sort(v.begin(),v.end());
    size_t counter=1,i;
    int temp,last,current,minresult,maxresult,result,minimum, maximum;
    queue<int>q1;
    queue<int>q;
    for(i=0; i<v.size(); i++)
    {
        q.push(v[i]);

    }
    while(!q.empty())
    {
        if(q.size()==1)
        {
            cout<<"Bin"<<counter<<":";
            last= q.front();
            cout<<last<<endl;
            q.pop();
        }
        else if(n<q.size())
        {
            for(i=0; i<n; i++)
            {
                temp=q.front();
                q1.push(temp);
                q.pop();
            }
            minimum= q1.front();
            maximum= q1.back();
            for(i=0; i<n; i++)
            {
                current= q1.front();
                minresult= abs(minimum-current);
                maxresult= abs(maximum- current);
                if(minresult<=maxresult)
                {
                    q1.push(minimum);
                }
                else
                {
                    q1.push(maximum);
                }
                q1.pop();
            }
            cout<<"Bin"<<counter<<":";
            while(!q1.empty())
            {
                result=q1.front();
                cout<<result<<",";
                q1.pop();

            }
            cout<<endl;
            counter++;


        }
        else
        {
            int len=q.size();
            for(i=0; i<len; i++)
            {
                temp=q.front();
                q1.push(temp);
                q.pop();
            }
            minimum= q1.front();
            maximum= q1.back();
            for(i=0; i<len; i++)
            {
                current= q1.front();
                minresult= abs(minimum-current);
                maxresult= abs(maximum- current);
                if(minresult<=maxresult)
                {
                    q1.push(minimum);
                }
                else
                {
                    q1.push(maximum);
                }
                q1.pop();
            }
            cout<<"Bin"<<counter<<":";
            while(!q1.empty())
            {
                result=q1.front();
                cout<<result<<",";
                q1.pop();

            }
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
        vector<int>v;
        cout<<"Input Data: ";
        cin>>s;
        stringstream str(s);
        for(int i; str>>i;)
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
