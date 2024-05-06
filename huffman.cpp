#include<bits/stdc++.h>
using namespace std;

struct Minheap{

    char data;
    int freq;

    Minheap *left,*right;

    Minheap(char a , int b)
    {
        left = right = NULL;
        this->data = a;
        this->freq = b;
    }


};

void printcode(Minheap *root, string str)
{
    if(!root)
    {
        return;

    }
    if(root->data!='&')
    {
        cout<<root->data<<" "<<str<<endl;
    }
    printcode(root->left, str+'0');
    printcode(root->right, str+'1');
}

struct compare{
    bool operator()(Minheap *l, Minheap *r)
    {
        return (l->freq>r->freq);
    }
};

void huffman(char data[], int freq[], int size)


{
    struct Minheap *left, *right, *top;


    priority_queue<Minheap *, vector<Minheap*>, compare>pq;

    for(int i=0; i<size; i++)
    {
        pq.push(new Minheap(data[i],freq[i]));

    }

    while (pq.size()>1)
    {
        left = pq.top();
        pq.pop();

        right = pq.top();
        pq.pop();

        top = new Minheap('&' , left->freq + right->freq);

        top->left = left;
        top->right = right;

        pq.push(top);
    }

    printcode(pq.top(), "");
    

    


}

int main()
{
    char arr[] = { 'a', 'b' ,'c','d','e','f'};
    int freq[] = { 5,9,12,13,16,45};

    int size = 6;
    huffman(arr,freq,size);
    return 0;
}