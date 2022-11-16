ll nxt(){
	int s=0; char c=getchar();bool f=0;
	while(c<'0'||c>'9'){if(c=='-') f=1;c=getchar();}
	while(c>='0'&&c<='9') s=(s<<1)+(s<<3)+c-48,c=getchar();
	return f?-s:s;
}
