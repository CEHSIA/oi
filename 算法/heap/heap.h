#ifndef _HEAP_
#define _HEAP_
#define MAX 128

/*
ENGLISH:this heap was made by array
JAPANESE:ko no heppu ha a ri i ga he n se n
CHINESE:zhege dui(youxian duilie)you shuzu wancheng
*/

/*PS
ENGLSISH:this h[0] of this heap is the length of heap,the heap count from 1 to MAX
JAPANESE:ko no EICHI[ZE-RO] ha ko no heppu no naga,ko no heppu ha ichi ka ra MAKUSU
	ma de ko u to shi ma su 
CHINESE:zhege h[0] shi dui de changdu ,dui cong 1 dao MAX bian ma
*/
struct heap{
	int data[MAX];
};
int length(heap *&p);
int getmin(heap *&p);
void insert(heap *&p,int d);

#endif
