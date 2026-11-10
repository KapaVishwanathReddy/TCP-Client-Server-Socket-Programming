#include"header.h"
void my_isr(int n)
{
	printf("Server closed..\n");
	exit(0);
}
int main(int argc,char **argv)
{
	if(argc!=3)
	{
		printf("Usage :./s poer num ip addr\n");
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
	server_id.sin_addr.s_addr=INADDR_ANY;
	len=sizeof(server_id);
	if (bind(sfd,(struct sockaddr*)&server_id,len)<0)
	{
		perror("bind: ");
		return 0;
	}
	perror("bind");
	if(listen(sfd,5)<0)
	{
		perror("Listen");
		return 0;
	}
	perror("listen:");
	while(1)
	{
		printf("\033[31mwating for client.....\033[31m\n");
		nsfd=accept(sfd,(struct sockaddr*)&clinet_id,&len);
		if(nsfd<0)
		{
			perror("Accept");
			return 0;
		}
		signal(SIGINT,my_isr);
		printf("Connected..\n");
		if(fork()==0)
		{

			char s[30];
			while(1)
			{
				read(nsfd,s,sizeof(s));
				printf("\033[34mClient sent:%s\033[34m\n",s);
				if(strcmp(s,"bye")==0)
				{
					break;
				}
				int i;
				for(i=0;s[i];i++)
				{
					if(s[i]>='a'&&s[i]<='z')
					{
						s[i]=s[i]-32;
					}
					else if(s[i]>='A'&&s[i]<='Z')
					{
						s[i]=s[i]+32;
					}
				}
				write(nsfd,s,strlen(s)+1);
			}

		}
	}
}
