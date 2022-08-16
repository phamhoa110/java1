#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

struct Stack{
    int top;
    int *e;
};
void Create(Stack &S)
{
    S.top = -1;
    S.e = NULL;
}
bool Empty(Stack S)
{
    return S.top == -1;
}
void Push(Stack &S, int item)
{
    if(Empty(S)) S.e = new int[1];
    else{
        S.e =  (int*)realloc(S.e,(S.top+2)*sizeof(int));
    }
    S.top++;
    S.e[S.top] = item;
}
bool Pop(Stack &S, int &x)
{
    if(Empty(S)) return false;
    else {
        x = S.e[S.top];
        S.e = (int*) realloc(S.e,S.top * sizeof(int));
        S.top--;
        return true;
    }
}
void Pour(Stack &S, Stack &Q)
{
    Create(S);
    int x;
    while(Pop(Q,x))
    {
        Push(S,x);
    };
}
void Sort(Stack &S)
{
    Stack P,Q;
    int x, temp;
    Create(P);
    Create(Q);
    while(!Empty(S))
    {
        Pop(S,temp);
        while(!Empty(S))
        {
            Pop(S,x);
            if(x < temp){
                Push(Q,temp);
                temp = x;
            }
            else Push(Q,x);
        }
            Push(P,temp);
            Pour(S,Q);
            Create(Q);
    }
    Pour(S,P);
}
void KTNX(Stack &S)
{
    Create(S);
    srand(time(0));
    for(int i=0; i<=5;i++)
    Push(S,rand()%100);
}
int main()
{
    Stack S;
    int x;
    Create(S);
    KTNX(S);
	while(Pop(S,x)) cout<<x<<" ";
    Sort(S);
    cout<<"S : ";
    while(Pop(S,x)) cout<<x<<" ";
    return 0;
}
