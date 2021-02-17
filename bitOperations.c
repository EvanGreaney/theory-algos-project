#include <stdio.h>

void bin_print(unsigned int i){
    // Number of bits in an Integer
    int j = (sizeof(unsigned int)*8)-1;
    //Temporary variable
    int k;
    // Loop over the number of bits in i.
    for (j--; j >= 0; j--)
    {
        k= ((1 << j) & i) ? 1 : 0;
        //print k;
        printf("%d",k);

    }
     

}

int main(int argc, char *argv[]){
    //Set i to literal value
    unsigned int i = 4294967295;
    //What we're Printing
    printf("Original:  ");
    //Print i in binary
    bin_print(i);
    // End Line
    printf("\t%x\t%u\n",i , i);

    for ( int j = 0; j < 40; j++)
    {
        //what the operation is
        printf("%3u << %2d: ",i,j);
        //i shifted left j times
        bin_print(i << j);
        //End Line
        printf("\n");
    }
    

    
    return 0;
}