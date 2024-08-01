#include<iostream>
#include<vector>
using namespace std;

vector<int>merge(vector<int> left,vector<int>right)
{
    vector<int> combined;
    int len;
    len = left.size()+right.size();

    for(int i=0;i<len;i++)
    {
        if(left.size()==0)
        {
            combined.push_back(right.front());
            right.erase(right.begin()) ;
        }
        else if (right.size()==0)
        {
            combined.push_back(left.front());
            left.erase(left.begin()) ;
        }
        else
        {
            if(left[0]<=right[0])
            {
                combined.push_back(left.front());
                left.erase(left.begin()) ;
            }
            else
            {
                combined.push_back(right.front());
                right.erase(right.begin()) ;
            }
        }

    }
    return combined;
}

vector<int> mergesort(vector<int> arr)
{
    if(arr.size()==1){return arr;}
    int mid = (arr.size()+1)/2;

    vector<int> left(arr.begin(), arr.begin()+mid);
    vector<int> right(arr.begin()+mid, arr.end());
    vector<int> combined;
    left = mergesort(left);
    right = mergesort(right);
    combined = merge(left,right);
    return combined;

}

int main()
{
    vector<int> arr {4,3,2,1,5,6,4,7,9,2},arr2;
    for(int i=0;i<arr.size();i++){cout<<arr[i]<<" ";}
    cout<<endl;
    arr2 = mergesort(arr);
    for(int i=0;i<arr2.size();i++){cout<<arr2[i]<<" ";}
    cout<<endl;


}
