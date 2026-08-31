#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h> 
#define SIZE 1000 

double _Zproc_libc_fini[] = {1267650600228229401496703205376.0,5316911983139663491615228241121378304.0,151115727451828646838272.0,281474976710656.0,158456325028528675187087900672.0,562949953421312.0,144115188075855872.0,5316911983139663491615228241121378304.0,151115727451828646838272.0,1125899906842624.0,302231454903657293676544.0,562949953421312.0,633825300114114700748351602688.0,81129638414606681695789005144064.0,1180591620717411303424.0,281474976710656.0,2535301200456458802993406410752.0,77371252455336267181195264.0,144115188075855872.0,41538374868278621028243970633760768.0,151115727451828646838272.0,2361183241434822606848.0,664613997892457936451903530140172288.0,2305843009213693952.0};


char* Does_Something(char input_str[], int len_str) 
{ 
    char char_set[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"; 
    char *res_str = (char *) malloc(SIZE * sizeof(char)); 
      
    int index, no_of_bits = 0, padding = 0, val = 0, count = 0, temp; 
    int i, j, k = 0; 
    for (i = 0; i < len_str; i += 3) 
        { 
            val = 0, count = 0, no_of_bits = 0; 
  
            for (j = i; j < len_str && j <= i + 2; j++) 
            { 
                val = val << 8;  
                  
                val = val | input_str[j];  
                count++; 
              
            } 
  
            no_of_bits = count * 8;  
  
            padding = no_of_bits % 3;  
  
            while (no_of_bits != 0)  
            { 
              
                if (no_of_bits >= 6) 
                { 
                    temp = no_of_bits - 6; 
                    
                    index = (val >> temp) & 63;  
                    no_of_bits -= 6;          
                } 
                else
                { 
                    temp = 6 - no_of_bits; 
                    index = (val << temp) & 63;  
                    no_of_bits = 0; 
                } 
                res_str[k++] = char_set[index]; 
            } 
    } 
  
    for (i = 1; i <= padding; i++)  
    { 
        res_str[k++] = '='; 
    } 
  
    res_str[k] = '\0'; 
  
    return res_str; 
  
}



int validate_key(char s[]){
    int length = strlen(s);
    if(length != 17){
        printf("Sorry no flag for you\n");
        return 0;
    }
    char* new_input = Does_Something(s, 17);
    for(int i = 0; i < 24 ; ++i){
        double expo = pow(2, new_input[i]);
        if(expo != _Zproc_libc_fini[i]){
            printf("Sorry no flag for you\n");
            return 0;
        }
    }
    return 1;

}

int main(int argc, char **argv){
    if(argc<2){
        printf("Usage: ./keygen <KEY>\n");
        return 1;
    }
    if(validate_key(argv[1])){
        printf("Congratulations!! here is you flag: flag{%s}", argv[1]);
        return 1;
    }
    return 0;

}