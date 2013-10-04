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
    int Height_squre;
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






   //JackABK added
   printf("===Welcome to create personal information by semihost system===i\n");

   fd = fopen( "./personal_info.txt" ,"a");  
   

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


   /*Calculate BMI*/
   /* 
            */

   return 0;

}




