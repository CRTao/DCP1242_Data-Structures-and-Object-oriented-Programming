#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

using namespace std;


int arraylength(int a[50000]){
	int p;
	for(p=49999;p>=0;p--){
		if(a[p]!=0)break;
	}
	return p+1;
}

int arraycompare(int a[50000],int b[50000]){
	int al=arraylength(a),bl=arraylength(b);
	int l=al-bl,pn=1,p;
	if(l<0)pn=0;
		else if(l==0){
			for(p=al-1;p>=0;p--){
				if(a[p]>b[p]){
					pn=1;
					break;
				}
				else if(a[p]<b[p]){
					pn=0;
					break;
				}
			}
		}
	return pn;
}

int main(int argc,char **argv){

	
	string a,b,c;
	ifstream file(argv[1],ios::in);
	int al,bl,n,i,j,pn=1,l;
	char o,oo;
	
	file>>n;
	//cout<<n<<endl;
	
	int p,pp,q;
	
	for(pp=0;pp<n;pp++){
		
		pn=1;
		file>>a>>o>>b>>i>>j;
		//cout<<a<<" "<<o<<" "<<b<<" "<<i<<" "<<j<<endl;
		
		
		int ast[50000],bst[50000],cst[50000];
		for(p=0;p<50000;p++)
			{ast[p]=bst[p]=cst[p]=0;
			}
		
		int an=1,bn=1;
		oo=o;
		al=a.length();
		bl=b.length();
		
		
		if(a[0]=='-'){
			for(p=0;p<al-1;p++)
				a[p]=a[p+1];
			an=0;
			al--;
		}
		if(b[0]=='-'){
			for(p=0;p<bl-1;p++)
				b[p]=b[p+1];
			bn=0;
			bl--;
		}
		
		for(p=0;p<al;p++){
			ast[al-p-1]=a[p]-'0';
		}
		for(p=0;p<bl;p++){
			bst[bl-p-1]=b[p]-'0';
		}
		
		l=al-bl;
		if(l<0)pn=0;
		else if(l==0){
			for(p=0;p<al;p++){
				if(a[p]>b[p]){
					pn=1;
					break;
				}
				else if(a[p]<b[p]){
					pn=0;
					break;
				}
			}
		}
		
		if((an+bn)==1&&o=='+')o='-';
		if((an+bn)==1&&o=='-')o='+';
		
		if(o=='+'){
			if(pn==1){
				for(p=0;p<al;p++){
					int tmp=ast[p]+bst[p];
					cst[p]+=tmp%10;
					if(tmp>=10)cst[p+1]+=tmp/10;
					if(cst[p]>=10){
						tmp=cst[p];
						cst[p]=tmp%10;
						cst[p+1]+=tmp/10;
					}
				}
			}
			else{
				for(p=0;p<bl;p++){
					int tmp=ast[p]+bst[p];
					cst[p]+=tmp%10;
					if(tmp>=10)cst[p+1]+=tmp/10;
					if(cst[p]>=10){
						tmp=cst[p];
						cst[p]=tmp%10;
						cst[p+1]+=tmp/10;
					}
				}				
			}
		}
		else if(o=='-'){
			 if(pn==1){
				for(p=0;p<al;p++){
					int tmp=ast[p]-bst[p];
					
					if(tmp<0){
						cst[p]+=10+tmp;
						cst[p+1]--;
					}
					else cst[p]+=tmp;
					
					if(cst[p]<0){
						tmp=cst[p];
						cst[p]=tmp+10;
						cst[p+1]-=1;
					}
					
				}
			 }
		 	else{
		 		for(p=0;p<bl;p++){
		 			
					int tmp=bst[p]-ast[p];
					if(tmp<0){
						cst[p]+=10+tmp;
						cst[p+1]--;
					}
					else cst[p]+=tmp;
					
					if(cst[p]<0){
						tmp=cst[p];
						cst[p]=tmp+10;
						cst[p+1]-=1;
					}
					
				}			
		 	 }
		}
		else if(o=='*'){
			if(pn==1){
				for(q=0;q<bl;q++){
					for(p=0;p<al;p++){
						int tmp=ast[p]*bst[q];
						cst[p+q]+=tmp%10;
						if(tmp>=10)cst[p+q+1]+=tmp/10;
						
					}
				}
				for(p=0;p<arraylength(cst);p++){
					if(cst[p]>=10){
						int tmp=cst[p];
						cst[p]=tmp%10;
						cst[p+1]+=tmp/10;
						}
				}
			}
			else{
				for(q=0;q<al;q++){
					for(p=0;p<bl;p++){
						int tmp=ast[q]*bst[p];
						cst[p+q]+=tmp%10;
						if(tmp>=10)cst[p+q+1]+=tmp/10;
					}
				}
				for(p=0;p<arraylength(cst);p++){
					if(cst[p]>=10){
						int tmp=cst[p];
						cst[p]=tmp%10;
						cst[p+1]+=tmp/10;
						}
				}		
				string a =cst-'0';		
			}
		}
		else if(o=='/'){
			 if(pn==1&&(bl==1&&b[0]=='0')!=1){
			 	
			 	int div[50000],dend[50000],r[50000];
			 	int loc=bl,aloc=al,sor=0,divl=0;
				int head=0,flag1=0,flag2=0;
						
				while(arraycompare(ast,bst)==1){
				
			 	loc=bl,aloc=arraylength(ast),sor=0;
			 	for(p=0;p<bl;p++){
				dend[p]=ast[aloc-bl+p];
				}
				
				while(arraycompare(dend,bst)==0){
					loc++;
					for(p=0;p<loc;p++){
					dend[p]=ast[aloc-loc+p];
					}		
					//if(head==1&&bl==1){
					//div[divl]=0;
					//divl++;
					//}
		
				}
				
				flag1=aloc;
				
				for(p=0;p<(flag2-flag1);p++){
					//if(bl==1&&arraycompare(dend,bst)==1)break;
					div[divl]=0;
					divl++;
				}
			
				while(arraycompare(dend,bst)!=0){
					
					for(p=0;p<loc;p++){
					r[p]=dend[p];
					}
					
					for(p=0;p<bl;p++){
					r[p]=0;
					}		
					
					for(p=0;p<bl;p++){
						int tmp=dend[p]-bst[p];	
						if(tmp<0){
							r[p]+=10+tmp;
							r[p+1]--;
						}
						else r[p]+=tmp;
					}
					
					for(p=0;p<loc;p++){
						dend[p]=r[p];
					}
					
					sor++;
				}
				
				
				div[divl]=sor;
				divl++;						
				
				for(p=0;p<loc;p++){
					ast[aloc-loc+p]=r[p];
					
					}
					aloc--;
					flag2=aloc;		
				
					head=1;
				}
			 	
			 	flag1=arraylength(ast);
			 	
			 	for(p=0;p<(flag2-flag1);p++){
					div[divl]=0;
					divl++;
				}
			 	
			 	
			 	for(p=0;p<divl;p++){
			 		cst[divl-1-p]=div[p];
			 	}
				 /*
			 	
			 	for(p=divl-1;p>=0;p--){
					if(cst[p]==0)cout<<0; 
					else cout<<cst[p];
				}
				cout<<endl;
				 */
				 				
			 }	
			 else if(bl==1&&b[0]=='0'){
				cout<<"Inf";
			 }		
			 else{
		 		cst[0]=0;		
		 	 }
		 	 
		}
		else{
			return 0;
		}
		
		if((an==0&&pn==1||bn==0&&pn==0)&&oo=='+'&&l!=0)cout<<"-";
		if((an==0&&pn==1||bn==1&&pn==0)&&oo=='-'&&l!=0)cout<<"-";
		if((an+bn==1)&&oo=='*')cout<<"-";
		if((an+bn==1)&&oo=='/')cout<<"-";
		
		
		for(p=j;p>=i;p--){
			//if(bl==1&&b[0]=='0')break;
			if(cst[p]==0)cout<<0; 
			else cout<<cst[p];
		}
		if(o=='-'&&a==b)cout<<0;
		cout<<endl;
		
		
	}
	return 0;
}
