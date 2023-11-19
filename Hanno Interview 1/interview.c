#include <stdio.h>
#include <stdlib.h> 

typedef enum {false, true} bool;

typedef struct{
  int *values;
  int size;
} array;

bool valueinarray(array arr , int testvalue);
int get_sum_of_unique_odd_numbers_except_five();
array getdata();

int main() {
  get_sum_of_unique_odd_numbers_except_five();
}

int get_sum_of_unique_odd_numbers_except_five() {
   array data = getdata();

   array unique;
   unique.size = 1;
   unique.values = (int *)malloc(unique.size*sizeof(int));

   for (int i = 0; i < data.size; i++) {
     //printf("data [%d] = %d \n",i,data.values[i]);
     if (data.values[i] != 5 ) {
       //printf("check !=5 data [%d] = %d \n",i,data.values[i]);
       if (data.values[i]%2 == 1) {
         //printf("check %2 == 1data [%d] = %d \n",i,data.values[i]);
         if (valueinarray(unique,data.values[i]) == false) {
           //printf("data [%d] = %d \n",i,data.values[i]);
           int* oldunique = unique.values;
           unique.size = unique.size + 1;
           unique.values = realloc(unique.values, unique.size*sizeof(int));
           unique.values[unique.size-1] = data.values[i];
         }    
       }
     }
   }
   //printf("size = %d\n",unique.size);
   int sum = 0;
   for(int a = 1; a < unique.size; a++) {
      //printf("unique_odd_numbers.values[%d] = %d\n",a,unique.values[a]);
      sum = sum + unique.values[a];
   }
   printf("sum of unique odd values except five = %d",sum);   
   free(unique.values);
   return 0;
}

array getdata() {
        static int numbers[15] = {1,3,1,4,1,8,9,7,9,9,2,5,5,3,4};
        array arr = {.values = numbers , .size=15};
        return arr;
}

bool valueinarray(array arr , int testvalue) {
    for(int i = 0; i < arr.size; i++) {
        if(arr.values[i] == testvalue)
            return true;
    }
    return false;
}
