#include <stdio.h>

typedef unsigned char* byte_pointer; 
  
/*show bytes takes byte pointer as an argument 
  and prints memory contents from byte_pointer 
  to byte_pointer + len */
void show_bytes(byte_pointer start, int len)  
{ 
     int i; 
     for (i = 0; i < len; i++) 
           printf(" %.2X", start[i]); 

     printf("\n"); 
} 
  
void show_int(int x) 
{ 
     show_bytes((byte_pointer) &x, sizeof(int)); 
} 
  
void show_float(float x)  
{ 
     show_bytes((byte_pointer) &x, sizeof(float)); 
} 
  
void show_pointer(void *x)  
{ 
     show_bytes((byte_pointer) &x, sizeof(void *)); 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    int i = 256; 
    float f = 1.0; 
    int *p = &i; 

    printf("show_float(%f) = ", f);
    show_float(f); 

    printf("show_int(%d) = ", i);
    show_int(i); 

    printf("show_pointer(%p) = ", p);
    show_pointer(p); 

    int a;
    int b;

    printf("Address of a(%p) and addr of b(%p)\n", &a, &b);

    return 0; 
} 