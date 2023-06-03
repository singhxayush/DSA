///// COLLISION HANDLING : CHAINING + IT'S IMPLEMENTATION /////
/* 

    chaining 
    creating an array of head of the linked list for a specific key and inserting for that key in times of collison

    > say no of such key slots = m, total no of keys to be inserted through m slots(considering uniform distribution) = n
    > load factor alpha = n/m
    > expected chain length = alpha( considering uniform distribution as mentioned above )
    > expected time to search/insert/delete : O( 1+alpha )


    DATA STRUCTURES FOR STORING CHAIN

    > linked list (search/insert/delete : O(l))
    > dynaic sized array
    > self balancing BST (AVL, RED BLACK) all operations : O(log(l))

*/

#include<bits/stdc++.h>
#include<list>
using namespace std;

class myhash
{   
    private :

        int bucket;
        list<int> *table;

    public :
    
        myhash(int b) // usually it's better to provide bucket size as a prime number
        {
            bucket = b; // as soon as a myhash objeect is created, a contruct call happens initialising the bucket size
            table = new list<int>[b]; // here we are allocating space for array of list for each bucket
        }
        void insertkey(int key)
        {
            int i = key%bucket;
            table[i].push_back(key);
        }
        void removekey(int key)
        {
            int i = key%bucket;
            table[i].remove(key);
        }
        bool search_hash(int key)
        {
            int i = key%bucket;
            for(auto x : table[i]) if(x == key) return true;
            return false;
        }
        void display_hash()
        {
            for(int i=0; i<bucket; i++)
            {
                cout<<i;
                for(auto x : table[i]) cout<<" --> "<<x;
                cout<<"\n";
            }
        }
};
int main()
{
    // array that contains keys to be mapped
    int a[] = {15, 11, 27, 8, 12, 7, 14, 21, 16, 5, 3, 22};
    int n = sizeof(a)/sizeof(a[0]);
 
    // insert the keys into the hash table
    myhash h(7);// 7 is count of buckets in

    for (int i = 0; i < n; i++) h.insertkey(a[i]); 
 
    // delete 12 from hash table
    h.removekey(12);
 
    // display the Hash table
    h.display_hash();

    int key = 91;
    if(h.search_hash(key)) cout<<"YES\n";
    else cout<<"NO\n";
}

/* 

Search : O(1+(n/m))

Delete : O(1+(n/m))

where n = Number of slots in Hash table 

           m = Number of keys to be inserted

Here n/m is the Load Factor.

Load Factor (∝) must be as small as possible.

*/