#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdlib.h> 

#define READ_COUNTER_ADDR 0x40050000
#define HOST_FILE = "./personal_info.txt" 
int32_t *read_counter = (int32_t *) READ_COUNTER_ADDR;
int main(void)
{
    FILE * fd ;
    char buf[6][15];
    int buf_str_len;
    int Height_squre , BMI;
    char file_name[15]; 

   /*disable the READ_COUNTER function*/
   #if 0
	printf("This is a test program for QEMU counter device\n");
	printf("See http://github.com/krasin/qemu-counter for more details\n\n");
	printf("Let's check if the Read Counter device presented\n");
	for (int i = 0; i < 10; i++) {
		printf("The device has been accessed for %"PRId32" times!\n", *read_counter);
	}
	int32_t now = *read_counter;
	if (now == 0) {
		printf("ERROR - No Read Counter detected\n");
	}
	else if (now == 11) {
		printf("OK - Read Counter works as intended\n");
	}
	else {
		printf("ERROR - Something is wrong with Read Counter\n");
	}
   #endif 


   //Creating the personal information 
   printf("===Welcome to create personal information by semihost system===i\n");


   /*Creat the file name*/
   printf("Please key in your file name\n");
   scanf("%s" , file_name);
   fd = fopen( file_name ,"a");  
   
   /*Name*/
   printf("Please key in  your Name\n");
   scanf("%s", buf[0]);
   buf_str_len = strlen(buf[0]);
   buf[0][buf_str_len] = '\n';
   fprintf(fd , "Name : " , 7);
   fprintf(fd , buf[0] , buf_str_len+1);
   

   /*Student ID*/
   printf("Please key in  your Student ID\n");
   scanf("%s", buf[1]);
   buf_str_len = strlen(buf[1]);
   buf[1][buf_str_len] = '\n';
   fprintf(fd , "Student : " , 10);
   fprintf(fd , buf[1] , buf_str_len+1); 


   /*School */
   printf("Please key in  your School\n");
   scanf("%s", buf[2]);
   buf_str_len = strlen(buf[2]);
   buf[2][buf_str_len] = '\n';
   fprintf(fd , "School : " , 9 );
   fprintf(fd , buf[2] , buf_str_len+1); 

   /*Height*/
   printf("Please key in  your Height\n");
   scanf("%s", buf[3]);
   buf_str_len = strlen(buf[3]);
   buf[3][buf_str_len] = '\n';
   fprintf(fd , "Height : " , 9 );
   fprintf(fd , buf[3] , buf_str_len+1);


   /*Weight*/
   printf("Please key in  your Weight\n");
   scanf("%s", buf[4]);
   buf_str_len = strlen(buf[4]);
   buf[4][buf_str_len] = '\n';
   fprintf(fd , "Weight : " , 9 );
   fprintf(fd , buf[4] , buf_str_len+1);


   /*Calculate BMI and write to file*/
   Height_squre = (str2int(buf[3]) * str2int(buf[3]))/10000;
   BMI = str2int(buf[4]) / Height_squre;
   int_To_string(BMI , buf[5]);
   buf_str_len = strlen(buf[5]);
   buf[5][buf_str_len] = '\n';
   fprintf(fd , "BMI : " , 6 );
   fprintf(fd , buf[5] , buf_str_len+1);
   return 0;

}



int str2int(char *str)
{
 int i=0,tmp=0;
 while(str[i]!='\0')
 {
  if(str[i]>='0'&&str[i]<='9')
   tmp=tmp*10+(str[i]-'0');
  i++;
 }
 return tmp;
}


void int_To_string(int in , char*out )
{
  int i, number_len=0; 
  char out_tmp[10];
 


  if(in == 0)
  {
    out[0] = '0';
    out[1] = '\0';
    return ;
  }

 
  while(in > 0)
  {
     out_tmp[number_len] = '0' +  (in % 10);
     in /= 10;
     number_len++;     
  }  
  
  for(i=0; i<number_len; i++){
     out[i] = out_tmp[number_len-1-i] ;
  }    
     out[number_len] = '\0';
}       
