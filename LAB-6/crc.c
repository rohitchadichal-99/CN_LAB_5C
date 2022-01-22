#include  <stdio.h>
#include  <string.h>
#define  N  strlen(gen)
char  modif[28],checksum[28],gen[28];
int  a,e,c,b;
void  xor() {
  for(c=1;c<N;c++)
    checksum[c]=((checksum[c]==gen[c])?'0':'1');
}
void  crc() {
  for(e=0;e<N;e++)
    checksum[e]=modif[e];
  do {
    if(checksum[0]=='1') xor();
    for(c=0;c<N-1;c++) checksum[c]=checksum[c+1];
    checksum[c]=modif[e++]; }while(e<=a+N-1);
}

int  main() {
  int  flag=0;
  strcpy(gen,"10001000000100001");
  printf("\n  enter  data:");
  scanf("%s",modif);
  printf("\n-----------------------\n");
  printf("\n  generating  polynomial:%s",gen);
  a=strlen(modif);
  for(e=a;e<a+N-1;e++)
    modif[e]='0';
    printf("\n--------------------------\n");
  printf("mod-ified  data  is:%s",modif);
  printf("\n-----------------------\n");
  crc();
  printf("checksum  is:%s",checksum);
  for(e=a;e<a+N-1;e++) modif[e]=checksum[e-a];
  printf("\n-----------------------\n");
  printf("\n  final  codeword  is  :  %s",modif);
  printf("\n------------------------\n");
  printf("\ntest  error  detection  0(yes)  1(no)?:");
  scanf("%d",&e);
  if(e==0) {
    do{
      printf("\nenter  the  position  where  error  is  to  be  inserted:"); scanf("%d",&e);
    }
    while(e==0||e>a+N-1);
    modif[e-1]=(modif[e-1]=='0')?'1':'0';
    printf("\n-----------------------\n");
    printf("\nerroneous  data:%s\n",modif);
  }
  crc();
  for(e=0;(e<N-1)&&(checksum[e]!='1');e++);
  if(e<N-1)
    printf("error  detected\n\n");
  else
    printf("\n  no  error  detected  \n\n");
  printf("\n-----------------------");
}
