///// OPEN ADDRESSING( HANDLING COLLISIONS ) used mainly when no of elements is fixed and known /////

/* 
    > no of slots in hash table >= no of items to be inserted
    > cache friendly


******* NOT DOING OPEN ADDRESSING BECAUSE CHAINING IS OVERALL BETTER THAN OPEN ADDRESSING *******

1.	Chaining is Simpler to implement.	                                                Open Addressing requires more computation.
2.	In chaining, Hash table never fills up, we can always add more elements to chain.	In open addressing, table may become full.
3.	Chaining is Less sensitive to the hash function or load factors.	                Open addressing requires extra care to avoid clustering and load factor.
4.	Chaining is mostly used when it is unknown how many and how frequently keys maybe   Open addressing is used when the frequency and number of keys is known.
    inserted or deleted.	
5.	Cache performance of chaining is not good as keys are stored using linked list.	    Open addressing provides better cache performance as everything is stored in the same table.
6.	Wastage of Space (Some Parts of hash table in chaining are never used).	            In Open addressing, a slot can be used even if an input doesn’t map to it.
7.	Chaining uses extra space for links.	                                            No links in Open addressing

*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    
}