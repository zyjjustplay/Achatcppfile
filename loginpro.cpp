#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int qnum=114514;
const int qnum2=191981;
string chat2[100];
map<string,long long> a;
map<string,string> chats;
string username[100];
int n=0;
int n2=0;
char ip[100];
bool check(char s[]){
	int a=-1,b=-1,c=-1,d=-1,e=-1;
	int t=sscanf(s,"%d.%d.%d.%d:%d",&a,&b,&c,&d,&e);//���Զ��룬������s��
	if(t!=5) return 0;//û��5���϶�����
	if(a<0||a>255) return 0;
	if(b<0||b>255) return 0;
	if(c<0||c>255) return 0;
	if(d<0||d>255) return 0;
	if(e<0||e>65535) return 0;//�ж�
	char s2[35];
	sprintf(s2,"%d.%d.%d.%d:%d",a,b,c,d,e);//������s2��
	int lens=strlen(s);//�������ж�s2��s�Ƿ�һ��
	bool ok=strcmp(s,s2)==0?1:0;
	return ok;
}
void showchats(){
    for(int i=0;i<n2;i++){
        cout<<chat2[i]<<':'<<chats[chat2[i]]<<endl;
    }
}
void showall(){
    for(int i=0;i<n;i++){
        cout<<"User name:"<<username[i];
        printf(",Password 'Hash' Value:%x\n",a[username[i]]);
    }
}
ll not_hash(char s[]){
    ll ans=abs((int)s[0]);
    for(int i=0;i<strlen(s);i++){
        ans*=s[i]*qnum;
        ans+=s[i];
        ans%=2147483647;
    }
    ans+=qnum2;
    ans*=qnum;
    ans%=2147483647;
    return abs(ans);
}
char b[100];
char c[100];
char d[100];
char lg[100];
char chat[100];
ll hhash;
void registera(){
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));
    hhash=0;
    printf("Register\n");
    printf("User Name:");
    gets(b);
    if(a[b]!=0){
        printf("This user name have been used!\n");
        memset(b,0,sizeof(b));
        system("pause");
        return;
    }
    username[n]=b;
    n++;
    printf("PassWord:");
    gets(c);
    hhash=not_hash(c);
    a[b]=hhash;
    printf("Registered!\n");
    system("pause");
    system("cls");
}
void login(){
    memset(d,0,sizeof(d));
    printf("Login\n");
    printf("User Name:");
    gets(d);
    if(a[d]==0){
        printf("Wrong User Name!\n");
        system("pause");
        return;
    }
    else{
        printf("Password:");
        gets(c);
        if(not_hash(c)==a[d]){
            strcpy(lg,d);
            printf("Logged in as:%s\n",d);
            system("pause");
            system("cls");
            return;
        }else{
            cout<<"Wrong Password!"<<endl;
            system("pause");
            return;
        }
    }
}
string bb[100];
void mainfex(){
    system("color F0");
    printf("Please connect to the server first:");
    while(1==1){
        cin>>ip;
        if(check(ip)&&strcmp(ip,"192.168.3.1:12345")==0){
            break;
        }else{
            if(check(ip)==0)cout<<"Error when try to connect to the server"<<endl;
            else cout<<"Failed to connect to the server!"<<endl;
        }
    }
    printf("Welcome to use WWechattttttttt version 0.00000001!\n");
    printf("There's a Default User for this programme\nUser Name:Default\nPassword:123456\n");
    char cs[10]={0};
    username[0]="Admin";
    n++;
    username[n]="Default";
    n++;
    char aaa[7]="123456";
    a["Default"]=not_hash(aaa);
    printf("Enter Admin's Password:");
    char pass[100]={0};
    cin>>pass;
    a["Admin"]=not_hash(pass);
    system("pause");
    system("cls");
    while(cin>>cs){
        if(strcmp(cs,"register")==0){
            getchar();
            registera();
        }else if(strcmp(cs,"login")==0){
            if(a[lg]==0){
                getchar();
                login();
            }else{
                printf("Please Logout first\n");
            }
        }else if(strcmp(cs,"show_all")==0){
            if(strcmp(lg,"Admin")==0){
                getchar();
                showall();
            }else{
                cout<<"You are not admin."<<endl;
                continue;
            }
        }else if(strcmp(cs,"user_name")==0){
            printf("User Name:%s\n",lg);
        }else if(strcmp(cs,"show_chats")==0){
            if(n==0)printf("No chat!\n");
            else showchats();
        }else if(strcmp(cs,"chat")==0){
            if(a[lg]!=0){
                getchar();
                gets(chat);
                if(strcmp(chat,"")==0)continue;
                printf("%s:%s\n",lg,chat);
                chat2[n2]=lg;
                n2++;
                chats[lg]=chat;
                memset(chat,0,sizeof(chat));
            }else{
                cout<<"Login First"<<endl;
            }
        }else if(strcmp(cs,"logout")==0){
            memset(lg,0,sizeof(lg));
            printf("Logged Out!\n");
        }else{
            printf("There's no such this command,Please check your input.\n");
            continue;
        }
    }
    system("pause");
    return;
}