#include <stdio.h>

struct Item {
    int v, w;
    float r;
} a[100], t[100];

void merge(int l, int m, int h) {
    int i=l,j=m+1,k=l;
    while(i<=m && j<=h)
        t[k++] = (a[i].r > a[j].r) ? a[i++] : a[j++];
    while(i<=m) t[k++] = a[i++];
    while(j<=h) t[k++] = a[j++];
    for(i=l;i<=h;i++) a[i]=t[i];
}

void mergeSort(int l,int h){
    if(l<h){
        int m=(l+h)/2;
        mergeSort(l,m);
        mergeSort(m+1,h);
        merge(l,m,h);
    }
}

int main() {
    int n,c;
    float ans=0;

    printf("Enter number of items: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter value and weight: ");
        scanf("%d%d",&a[i].v,&a[i].w);
        a[i].r=(float)a[i].v/a[i].w;
    }

    printf("Enter capacity: ");
    scanf("%d",&c);

    mergeSort(0,n-1);

    for(int i=0;i<n && c>0;i++){
        if(a[i].w<=c){
            ans+=a[i].v;
            c-=a[i].w;
        } else {
            ans+=a[i].r*c;
            c=0;
        }
    }

    printf("Maximum Value = %.2f",ans);

    return 0;
}