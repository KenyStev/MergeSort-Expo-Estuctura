#include <QCoreApplication>
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);



    return a.exec();
}


vector<int*> mergeSort(vector<int*> m){
    vector<int*> left, right, result;
    if(m.size()<=1)
        return m;
    int middle = m.size()/2;

    for(int i=0; i<middle-1;i++)
        left.push_back(m[i]);
    for(int i=middle; i<m.size()-1;i++)
        right.push_back(m[i]);
    left = mergeSort(left);
    right = mergeSort(right);
    if(last(left) <= first(right))
    {
        left.insert(left.end(),right.begin(),right.end());
        return left;
    }
    result = mergeSort(left,right);
    return result;
}

vector<int*> mergeSort(vector<int*> left,vector<int*> right){

}

int first(vector<int*> list){
    if(!list.empty())
        return list[0];
    return INT_MIN;
}

int last(vector<int*> list){
    if(!list.empty())
        return list[list.size()-1];
    return INT_MIN;
}
