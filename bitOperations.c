#include <stdio.h>

void bin_print(unsigned int i){
    // Number of bits in an Integer
    int j = sizeof(unsigned int)*8;
    //Temporary variable
    int k;
    // Loop over the number of bits in i.
    for (j--; j >= 0; j--)
    {
        //Pick out the jth bit of i, left to right.
        k= ((1 << j) & i) ? 1 : 0;
        //print k;
        printf("%d",k);

    }
     

}

int main(int argc, char *argv[]){
    //Set i to literal value
    unsigned int i = 0x0f0f0f0f;
    //What we're Printing
    printf("Original:  ");
    //Print i in binary
    bin_print(i);
    // End Line
    printf("\t%x\t%u\n",i , i);

    //32
    int j = sizeof(unsigned int)*8;

    for ( j--; j>=0; j--)
    {
        // i shifted j times
        bin_print(1 << j); printf("\n");
        // i
        bin_print(i); printf("\n");
        printf("------------------------------&\n");
        // (1 shifted left j times and i) bitwise logical and i
        bin_print(((i << j) & i)); printf("\n\n");
    }
    

    
    return 0;
}