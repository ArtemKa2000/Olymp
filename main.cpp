#include <bits/stdc++.h>
using namespace std;
struct node{
    int value;
    node* prev;
    node* next;
};
node* dat;
void freeTop(node* total){
    total=total->next;
    while(total!=nullptr){
        total->prev->next=nullptr;
        total->prev=nullptr;
        total=total->next;
    }
}
node* getTop(node* total){
    while(total->next!=nullptr)
        total=total->next;
    return total;
}
int main()
{
    int n,a,b;
    cin>>n;
    dat=new node[n];
    for(int i=0;i<n;i++){
        dat[i].next=dat[i].prev=nullptr;
        dat[i].value=i;
    }
    string coms[2];
    cin>>coms[0];
    while(coms[0]!="quit"){
        cin>>a>>coms[1]>>b;
        if(coms[0]=="move"){
            if(coms[1]=="onto"){
                freeTop(&dat[b]);
                if(a!=b){
                    freeTop(&dat[a]);
                    if(dat[a].prev!=nullptr)
                        dat[a].prev->next=nullptr;
                    dat[a].prev=&dat[b];
                    dat[b].next=&dat[a];
                }
            }else{
                freeTop(&dat[a]);
                if(a!=b){
                    if(dat[a].prev!=nullptr)
                        dat[a].prev->next=nullptr;
                    node* top=getTop(&dat[b]);
                    top->next=&dat[a];
                    dat[a].prev=top;
                }
            }
        }else{
            if(coms[1]=="onto"){
                freeTop(&dat[b]);
                if(a!=b && getTop(&dat[a])!=&dat[b]){
                    if(dat[a].prev!=nullptr)
                        dat[a].prev->next=nullptr;
                    dat[a].prev=&dat[b];
                    dat[b].next=&dat[a];
                }
            }else{
                if(a!=b){
                    node* top=getTop(&dat[b]);
                    if(getTop(&dat[a])!=top){
                        if(dat[a].prev!=nullptr)
                            dat[a].prev->next=nullptr;
                        top->next=&dat[a];
                        dat[a].prev=top;
                    }
                }
            }
        }
        cin>>coms[0];
    }
   for(int i=0;i<n;i++){
        cout<<i<<":";
        if(dat[i].prev==nullptr){
            node* total=&dat[i];
            while(total!=nullptr){
                cout<<" "<<total->value;
                total=total->next;
            }
        }
        cout<<'\n';
    }
    return 0;
}
