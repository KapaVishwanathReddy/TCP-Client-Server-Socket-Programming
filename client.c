#include"header.h"
void my_isr(int n)
{
	printf("Client closed...\n");
	exit(0);
}
char *gets(char *);
int main(int argc,char **argv)
{
	if(argc!=3)
	{
		printf("Uage :./c port num ip addr: \n");
		return 0;
	}

        int sfd,nsfd;
        sfd=socket(AF_INET,SOCK_STREAM,0);
        if(sfd<0)
        {
                perror("Socket: ");
                return 0;
        }
	perror("Socket:");
	struct sockaddr_in server_id,clinet_id;
	int len;
	server_id.sin_family=AF_INET;
	server_id.sin_port=htons(atoi(argv[1]));
	server_id.sin_addr.s_addr=inet_addr(argv[2]);
	len=sizeof(server_id);
	if (connect(sfd,(struct sockaddr*)&server_id,len)<0)
	{
		perror("connect: ");
		return 0;
	}
	perror("connect");

	signal(SIGINT,my_isr);
	char s[30];
	while(1)
	{
		printf("Enter data: ");
		//fscanf(s,"%s",s);
		//gets(s);
		fgets(s,30,stdin);
		s[strlen(s)-1]='\0';
		   
		write(sfd,s,strlen(s)+1);
		read(sfd,s,sizeof(s));
		printf("Server sent:%s\n",s);
	}

}  
