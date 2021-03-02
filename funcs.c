#include <stdio.h>
#include <inttypes.h>

# define W 32
#define WORD uint32_t
#define PF PRIX32

// Page 10 of the Secure Hash Standard.
#define CH(x,y,z) (x&y)^(~x&z)
#define MAJ(x,y,z) (x&y)^(x&z)^(y&z)


// Page 5 of the Secure Hash Standard.
#define ROTL(x,n) (x<<n)|(x>>(W-n))
#define ROTR(x,n) (x>>n)|(x<<(W-n))




WORD Ch(WORD x, WORD y , WORD z){

    return (x&y)^(~x&z);
}


int main(int argc, char *argv[]){
    
    
    WORD x = 0x1234567;
    WORD y = 0x0A0A0A0A;
    WORD z = 0xB0B0B0B0;

    //Temporary WORD for answers
    WORD ans;

    ans = CH(x,y,z);

    printf("Ch(%08"PF",%08"PF",%08"PF")=%08"PF"\n",x ,y, z, ans);
    

    ans = MAJ(x,y,z);

    printf("Ch(%08"PF",%08"PF",%08"PF")=%08"PF"\n",x ,y, z, ans);

    printf("ROTL(%08"PF" -> %08"PF "\n",x ,ROTL(x,4));
    printf("ROTR(%08"PF" -> %08"PF "\n",x ,ROTR(x,4));
    
    
    return 0;
}