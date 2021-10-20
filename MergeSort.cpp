#include <bits/stdc++.h>

using namespace std;

void Merge(int v[], int i, int m, int f){
    int n1 = m - i + 1, n2 = f-m;
    int v1[n1], v2[n2];
    for(int a = 0; a < n1; a++){
        v1[a] = v[i+a];
    }
    for(int b = 0; b < n2; b++){
        v2[b] = v[m+1+b];
    }
    int k = 0, j = 0, l = i;
    while(k < n1 && j < n2){
        if(v1[k] < v2[j]){
            v[l] = v1[k];
            l++;
            k++;
        }else{
            v[l] = v2[j];
            l++;
            j++;
        }
    }
    while(k < n1){
        v[l] = v1[k];
        l++;
        k++;
    }
    while(j < n2){
        v[l] = v2[j];
        l++;
        j++;
    }
}
void MergeSort(int v[], int i, int f){
    int m = (i+f)/2;
    if(i == f){
        return ;
    }
    
    MergeSort(v, i, m);
    MergeSort(v, m+1, f);
    return Merge(v, i, m, f);
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    MergeSort(a, 0, n);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    
    return 0;
}
