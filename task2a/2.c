#include <stdio.h>

 int strLength(char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return len;
}

void translate2ascii(char c)
{
    printf("%d ", (int)c);
}

int ascii2binary(int num)
{
    if (num < 2)
    {
        return num;
    }
    return ascii2binary(num / 2) * 10 + num % 2;
}


 
/* TODO: 2a functions here */
     void echo_printer(char c){ /* task 0 from lab1 - prints c to the standard output*/
        
        printf("%c ",c);      
     }
        
    
    void ascii_printer(char c){/* task 1a from lab1 - convert a char to its ascii code and print it to the standard output*/
        
        translate2ascii(c);
    }


    void binary_printer(char c){ /*task 1b from lab1 - convert a char to its ascii code in binary (least significant bit to the most  significant representation) and print it to the standard output */
        
        printf("%d ", ascii2binary((int)c));
    }
                                  
    void upper_to_lower_to_upper_printer(char c){/* task 1c from lab1 - convert to upper case letters if the input is lower case letters and vice versa*/
       
        if (isupper((int)c))
            {
            printf("%c ", tolower((int)c));
            }
        else
            {
            if (islower((int)c))
                {
                    printf("%c ", toupper((int)c));
                }
            else
                {
                    printf("%c ", c);
                }
            }
            
    }

 
void string_printer(char* str, void (*f) (char)){
  int i=0;
  while (str[i]!=NULL)
  {
        f(str[i]);
        i++;
  }
  
}
 
void string_reader(char* s){
    fgets(s,10,stdin);
}
 
void bitwise_xor(char* s){
  int ascii[sizeof(s)];
  int i=2;
  int sum=s[0]^s[1];
  while(s[i]!=NULL){
      sum=sum^s[i];
      i++;
  }
  printf("%d",ascii2binary(sum));
  
}
 
int main(int argc, char **argv){
	menu();
}

struct fun_desc {
  char *name;
  void (*fun)(void);
};

void menu(){
    struct fun_desc fun_arr[4];
    fun_arr[0].name="echo_printer";
    fun_arr[0].fun=&echo_printer;
    
    fun_arr[1].name="ascii_printer";
    fun_arr[1].fun=&ascii_printer;

    fun_arr[2].name="binary_printer";
    fun_arr[2].fun=&binary_printer;

    fun_arr[3].name="upper_to_lower_to_upper_printer";
    fun_arr[3].fun=&upper_to_lower_to_upper_printer;

    while(getchar!=EOF){
    printf("%s","Please enter a string (0<size<=10):");
    char str[10];
    string_reader(str);
    printf("%s","Please choose printer type:\n0) echo printer\n1) ascii printer\n2) binary printer\n3) upper to lower and lower to upper case\n4) bitwise xor\n");
    int option;
    scanf("%d",&option);
    printf("%s","Option: ");
    printf("%d\n",option);
    if(option==4)
        bitwise_xor(str);
    else if(option>4||option<0){
        printf("%s","ERROR! Illegal input!");
        exit(0);
    }
    else{
        string_printer(str, fun_arr[option].fun);
    }
    }
    printf("%s","Option: DONE.");

}
 
