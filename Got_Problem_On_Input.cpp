#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
#include<string>

using namespace std;

int main(int argc,char **argv){
	
	int n,i,k=0;
	ifstream file(argv[1],ios::in);
	
	char a[25000],b[25000],c[25000],ans[25000];
	int al,bl,l,large,pn,tmp,p,q;
	char o;
	
	
	file>>n;	
	
	for(i=0;i<n;i++){
		
		while(file>>a[k]!=0){
			if(a[k]=='-'||a[k]=='+'||a[k]=='*'||a[k]=='/'){
				o=a[k];
				break;
			}
			cout<<a[k];
			k++;
			}
		al=k;
		cout<<endl;
		k=0;
		
		cout<<o<<endl;

		
		while((file>>b[k])!=0){
			cout<<b[k];
			k++;
			}
		bl=k;
		cout<<endl;
		k=0;
		
		if(al>bl){l=al-bl;pn=1;large=al;}
		else if(al<bl){l=bl-al;pn=0;large=bl;}
		else{
			while(a[k]==b[k]){
				if(k==al)break;
				k++;
			}
			l=0;
			if(a[k]>=b[k]){large=al;pn=1;}
			else {large=bl;pn=0;}
		}
		
		cout<<"l:"<<l<<" large:"<<large<<" pn:"<<pn<<endl;
		
		for(i=0;i<=2*large;i++){
			c[i]='0';
		}
		
		if(o=='+'){
			for(i=0;i<2*large;i++){
				if(bl-1-i>=0&&al-1-i>=0){	
					if(pn==1){
						tmp=c[i]-'0'+a[al-1-i]-'0'+b[bl-1-i]-'0';
						if(tmp>=10){
							c[i]=tmp%10-'0';
							c[i+1]=tmp/10-'0';
						}
						else c[i]=tmp+'0';
					}	
					else{
						tmp=c[i]+a[al-1-i]+b[bl-1-i];
						if(tmp>=10){
							c[i]=tmp%10-'0';
							c[i+1]=tmp/10-'0';
						}
						
					}
				}
			}
		}
		else if(o=='-'){
			for(i=0;i<2*large;i++){
				if(bl-1-i>=0&&al-1-i>=0){	
					if(pn==1){
						tmp=c[i]-'0'+a[al-1-i]-'0'-b[bl-1-i]+'0';
						if(tmp<0){
							c[i]=10+tmp+'0';
							c[i+1]=-1+'0';
						}
						else c[i]=tmp-'0';
					}	
					else{
						tmp=c[i]-'0'-a[al-1-i]+'0'+b[bl-1-i]-'0';
						if(tmp<0){
							c[i]=10+tmp+'0';
							c[i+1]=-1+'0';
						}
						else c[i]=tmp+'0';						
					}
					
				}
				else{
					if(pn==1){
						c[i]=c[i]+a[al-1-i]-'0';
					}
					else{
						c[i]=c[i]+b[bl-1-i]-'0';
					}
				}
			}	
		}
		else if(o=='*'){
			
		}
		else if(o=='/'){
			
		}
		else{
			return 0;
		}
		
		large--;
		
		if(pn==0)cout<<"-";
		for(i=0;i<=2*large;i++){
			
				ans[i]=c[large-i];
				//cout<<c[large-i]<<endl;
				cout<<ans[i];
			
			//cout<<c[i];
			}
		
		int p,q;
		file>>p;
		file>>q;
		p--;q--;
		
		cout<<endl;
		cout<<p<<endl;
		//cout<<ans[p];
		
	}
	
	return 0;
}
