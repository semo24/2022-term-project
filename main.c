#include <stdio.h>
#include <string.h>

typedef struct{
    char name[100];
    int age;
} person;
void merge(person* member, person* sorted, int left, int mid, int right){
    int i=left, k=left, j=mid+1, l;
    while(i<=mid && j<=right){
        if(member[i].age<=member[j].age){
            sorted[k++]=member[i++];
            continue;
        }
        sorted[k++]=member[j++];
    }
    if(i>mid) for(l=j; l<=right; sorted[k++]=member[l++]);
    else for(l=i; l<=mid; sorted[k++]=member[l++]);
    for(l=left; l<=right; l++) member[l]=sorted[l];
}
void mSort(person* member, person* sorted, int left, int right){
    int mid;
    if(left<right){
        mid= (left+right)/2;
        mSort(member, sorted, left, mid);
        mSort(member, sorted, mid+1, right);
        merge(member, sorted, left, mid, right);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    person member[n];
    person sorted[n];
    for(int i=0; i<n; i++) scanf("%d %[^\n]s", &member[i].age, member[i].name);
    mSort(member, sorted, 0, n-1);
    for(int i=0; i<n; i++) printf("%d %s\n", member[i].age, member[i].name);
    return 0;
}
