Given there is a number n and it's length we need to find if it's divisible by 8 or not. If it's divisible by 8 then we need to print the exact number and if it's not then print 
the closest one but we can only change one digit of it.

Input
4
1 7
3 512
4 1044 --> not divisble by 8
21 299792458196831048576 --> divisble by 8

Output
8
512
1144
299792458196831048576


#include <bits/stdc++.h>
#define ll long long
using namespace std;
int solve(){
	    int n;
	    cin>>n;
	    string s;
	    cin>>s; // for storing the number as a string coz n is huge
	    string sss; // last 3 digits(char)
	    if(n==1){
	        cout<<"8"<<endl;
	        return 0; // if n=1 so answer will obviously 8
	    }
	    else{
	        // for a number greater than or equal to 3
	        // for eg--> 1144
	        ll num;
	        if(n>=3){
	            sss=s.substr(n-3,3); // store the last 3 numbers as a string
	        }
	        else{
	            // n==2 for eg--> 29 here we have two possibiltes 32 and 24 but the answer will be 24 coz we will get by changing one digit in 24 
	           // so store it as a number
	           ll num;
	           num=stoll(s);
	           // then check if it is divisible by 8 or not so if it's not divisible then
	           // then minus the reminder from it and add the remainder to it 
	           // 29%8--> rem=5
	           // so--> ans1=29-5=24 or ans2=29+8-rem=32
	           // if(last digit-rem>0) ans1 will be the answer or ans2
	           if(num%10>=num%8){
	               num=num-(num%8);
	           }
	           else{
	               num=num+(8-num%8);
	           }
	            cout<<num<<endl;
	            return 0;
	        }
	        // if n>=3
	        // we store the last 3 chars as a string in sss so now convert them into integer
	        num=stoll(sss);
	        if(num%8==0){
	            cout<<s<<endl;
	            return 0;
	        }
	        // else do the same thing as above if not divisible by 8
	        else{
	            if(num%10>=num%8){
	                num=num-(num%8);
	            }
	            else{
	                num=num+(8-num%8);
	            }
	        }
	        // now we need to merge the numbers also right from front
	        // for eg-->299792458196831048576  we already store the last 3 chars and we need to store all of them in another string i mean-->299792458196831048+576
	        string ssss="";
	        if(n>=3){
	            string addd="";
	            ssss=ssss+s.substr(0,n-3); // this-->299792458196831048
	            addd=to_string(num);
	            // but what if 299792458196831048076 so the last 3 chars are 076 so when we convert it into string we will get 76 only which is incorrect 
	            // so we need to reverse it and push "0" in it --> 76->rev(76)->67->670
	            // that means size of add is not equal to sss
	            reverse(addd.begin(), addd.end());
	            while(addd.size()!=sss.size()){
	                addd.push_back('0');
	            }
	            // now reverse it again and merge it in addd
	            reverse(addd.begin(),addd.end());
	            ssss=ssss+addd;
	           cout<<ssss<<endl;
	    }
	}

	return 0;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}



