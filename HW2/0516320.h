#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

using namespace std;

#ifndef BigNum_h
#define BigNum_h

int arraylength(int a[40000]){
	int p;
	for(p=40000-1;p>=0;p--){
		if(a[p]!=0)break;
	}
	return p+1;
}

int arraycompare(int a[40000],int b[40000]){
	int al=arraylength(a),bl=arraylength(b);
	int l=al-bl,pn=1,p;
	if(l<0)pn=0;
	else if(l>0)pn=1;
	else{
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

int arrayplus(int ast[40000],int bst[40000],int *cst,int len){
	int p;
	for(p=0;p<len;p++){
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
int arrayminus(int ast[40000],int bst[40000],int *cst,int len){
	int p;
	for(p=0;p<len;p++){
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

class BigNum{
	public:
		BigNum();
		BigNum( const BigNum& a){
			for(int p=0;p<40000;p++)st[p]=a.st[p];
			len=a.len;
			sn=a.sn;	
		};
		BigNum operator+(BigNum&);
		BigNum operator-(BigNum&);
		friend BigNum operator*(BigNum& ,BigNum&);
		friend BigNum operator/(BigNum& ,BigNum&);
		friend ostream& operator<<(ostream&,BigNum const &);
		friend istream& operator>>(istream&,BigNum&);
		int st[40000];
		int len;
		int sn;
};

BigNum::BigNum() {
    for(int p=0;p<40000;p++)st[p]=0;
	len=0;
	sn=1;
}

BigNum BigNum::operator+(BigNum& bignum2) {
  
  BigNum bignum;
  int cst[40000];
  int p;
  for(p=0;p<40000;p++)cst[p]=0;
  bignum.sn=1;
  int pn=( this->len >=bignum2.len )?1:0;
  if(this->len == bignum2.len){
  	pn=arraycompare(this->st,bignum2.st);
  }
  	  
  if((this->sn+bignum2.sn)==1&&pn==1){
			arrayminus(this->st,bignum2.st,cst,this->len);
			}
  else if((this->sn+bignum2.sn)==1&&pn==0){
			arrayminus(bignum2.st,this->st,cst,bignum2.len);
	  		}
  else if((this->sn+bignum2.sn)!=1&&pn==1){
  			arrayplus(this->st,bignum2.st,cst,this->len);
			bignum.sn=1;
  }
  else{
  			arrayplus(bignum2.st,this->st,cst,bignum2.len);
			bignum.sn=1;
  }
  if(( (this->sn==0&&pn==1)||(bignum2.sn==0&&pn==0) )&&this->len!=bignum.len)bignum.sn=0;
  
  
  bignum.len=arraylength(cst);
  for(p=0;p<bignum.len;p++){
  	bignum.st[p]=cst[p];
  }
  
  return bignum;
}

BigNum BigNum::operator-(BigNum& bignum2) {
  
  BigNum bignum;
  int cst[40000];
  int p;
  for(p=0;p<40000;p++)cst[p]=0;
  bignum.sn=1;
  int pn=(this->len >=bignum2.len)?1:0;
  if(this->len == bignum2.len){
  	pn=arraycompare(this->st,bignum2.st);
  }
  
  if((this->sn+bignum2.sn)==1&&pn==1){
			arrayplus(this->st,bignum2.st,cst,this->len);
			}
  else if((this->sn+bignum2.sn)==1&&pn==0){
			arrayplus(bignum2.st,this->st,cst,bignum2.len);
	  		}
  else if((this->sn+bignum2.sn)!=1&&pn==1){
  			arrayminus(this->st,bignum2.st,cst,this->len);
			bignum.sn=1;
  }
  else{
  			arrayminus(bignum2.st,this->st,cst,bignum2.len);
			bignum.sn=1;
  }
  if(( (this->sn==0&&pn==1)||(bignum2.sn==1&&pn==0))&&this->len!=bignum.len)bignum.sn=0;
  
  bignum.len=arraylength(cst);
  if(this->len!=bignum.len)bignum.len--;
  
  for(p=0;p<bignum.len;p++){
  	bignum.st[p]=cst[p];
  }
  
  return bignum;
}

BigNum operator*(BigNum& bignum1,BigNum& bignum2) {
  
  BigNum bignum;
  int cst[40000];
  int p,q;
  for(p=0;p<40000;p++)cst[p]=0;
  bignum.sn=1;
  int pn=(bignum1.len >=bignum2.len)?1:0;
  if(bignum1.len == bignum2.len){
  	pn=arraycompare(bignum1.st,bignum2.st);
  }
  if(pn==1){
				for(q=0;q<bignum2.len;q++){
					for(p=0;p<bignum1.len;p++){
						int tmp=bignum1.st[p]*bignum2.st[q];
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
				for(q=0;q<bignum1.len;q++){
					for(p=0;p<bignum2.len;p++){
						int tmp=bignum1.st[q]*bignum2.st[p];
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
  if(bignum1.sn+bignum2.sn==1)bignum.sn=0;
  
  bignum.len=arraylength(cst);
  for(p=0;p<bignum.len;p++){
  	bignum.st[p]=cst[p];
  }

  return bignum;
}

int bigcomparepart(int *a , int *b , int size)
{
    int i;
    for(i=size-1;i&&a[i]==b[i];--i);
    return a[i]-b[i];
}
 
void bigmulintpart(int *a , int num, int *c, int size)
{
    int i;
    for(i=0;i<size;++i)
        c[i]=num*a[i];
    for(i=0;i<size-1;++i) {
        c[i+1]+=c[i] / 10;
        c[i]%=10;
    }
}
 
void big_subs(int *a,int *b,int size)
{
    int i,borrow=0;
    for(i=0;i<size;++i){
        a[i]-=(b[i]+borrow);
        if(a[i]<0)borrow=1,a[i]+=10;
        else borrow = 0;
    }
}

BigNum operator/(BigNum& bignum1,BigNum& bignum2) {
	

	BigNum bignum3,bignuma(bignum1);
	int i,N,tmp;
    int *Nb;
    int cdig;
    int p;
 	bignum2.st[bignum2.len]=0;
 	
    int *a = bignum1.st;
	int *b = bignum2.st;
    int *c = bignum3.st;

    int a_len = bignum1.len ;
    int b_len = bignum2.len ;
    int c_len = a_len - b_len + 1;
    int r_len = b_len + 1;
 	
 	
    if(b_len==0) {
        cdig=0;
        return bignum3;
    } else if(b_len>a_len) {
        cdig=0;
        return bignum3;
    }
 	if(b_len==1)c_len--;
    Nb=(int*)malloc(sizeof(int)*r_len);
    cdig=c_len; 
	a[a_len++]=0;
	
    for(;c_len >=0;--c_len){
        for(N=1;N<10;++N) {
            bigmulintpart(b,N,Nb,r_len);
            tmp=bigcomparepart(a+c_len, Nb, r_len);
            if(tmp<=0)break;
        }
 
        if(tmp==0){
            memset( (void*)(a+c_len), 0,( sizeof(int) * (r_len)));
            c[c_len] = N;
        } else if(tmp < 0) {
            c[c_len]=--N;
            bigmulintpart(b,N,Nb,r_len);
            big_subs(a+ c_len,Nb,r_len);
        } else { 
            big_subs(a+c_len,Nb, r_len);
            c[c_len] = 9;
        }
    }
    free((void*)Nb);
    for(i=cdig;i>0&&c[i]==0;--i);
    if(i==0)cdig=((c[i]==0)?0:1);
    else cdig =i+1;
 
    for(i=b_len;i>0&&a[i]==0;--i);
    if(i==0)bignuma.len=((a[0]==0)?0:1);
    else bignuma.len = i+1;
    
 	if(bignum1.sn+bignum2.sn==1)bignum3.sn=0;
    
  	bignum3.len=arraylength(c);
  	for(p=0;p<cdig;p++){
  		bignum3.st[p]=c[p];
  	}
    return bignum3;
	
}

ostream& operator<<(ostream& out,BigNum const & bignum){
  
  int p,count=0;
  
  for(p=bignum.len-1;p>=0;p--){
  	  if(bignum.st[p]!='\0')count++;
  }
  if(bignum.sn==0&&count!=0){cout<<'-';}
  for(p=bignum.len-1;p>=0;p--){
	  out<<bignum.st[p];
  }
  if(count==0)out<<"0";
  
  return out;
}

istream& operator>>(istream& in,BigNum& bignum) {
  
  string s;
  in>>s;
  for(int p=0;p<40000;p++)bignum.st[p]=0;
  
  bignum.len=s.length();
  int p;
  if(s[0]=='-'){
			for(p=0;p<bignum.len-1;p++)
				s[p]=s[p+1];
			bignum.sn=0;
			bignum.len--;
  }
  for(p=0;p<bignum.len;p++){
			bignum.st[bignum.len-p-1]=s[p]-'0';
  }
  bignum.st[bignum.len]=0;
  s.clear();
  return in;
}



#endif

