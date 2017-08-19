#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <stdexcept>

#ifndef BIGNUMBER_H
#define BIGNUMBER_H

using namespace std;

class BigNumber {
    public:

        BigNumber(string Big){
            setBase(Big);
        }


        string getBase(){
            return base;
        }


        void setBase(string val){
            base = val;
        }


        BigNumber abs(){
            string tmp = getBase();
            return BigNumber(isdigit(tmp[0])? tmp: tmp.erase(0, 1));
        }


        BigNumber add(BigNumber val){
            string tmp = getBase();
            string Sum = val.toString();
            if(tmp.size() > Sum.size()){
                include_zeros(Sum, tmp);
            } else {
                include_zeros(tmp, Sum);
            }

            int soma=0, _resto=0, s;
            string total = tmp;
            for(int i=tmp.size()-1; i>=0; i--){
                s = (tmp[i]-'0')+(Sum[i]-'0')+_resto;
                total[i] = (s%10) + '0';
                _resto = s/10;
            }
            if(_resto) total = "1" + total;
            return BigNumber(total);
        }


        int compare(string val){
            if(getBase() == val){
                return 0;
            } else {
                if(getBase().compare(val) < 0) return 1;
                else return -1;
            }
        }


        BigNumber divide(string Div){
            /**
                TO-DO
            */
        }


        BigNumber factorial(){
            BigNumber tmp = BigNumber(getBase());
            BigNumber fact = valueOf(1);
            for (int i = 1; i <= tmp.toInt(); i++)
                fact = fact.multiply(valueOf(i));
            return fact;
        }


        BigNumber multiply(BigNumber Mult){
            string ret;
            string tmp = getBase();
            int a_len = tmp.length();
            int b_len = Mult.toString().length();
            int mat[b_len][a_len+b_len+2];
            for(int i =0; i<b_len; ++i) {
                for(int j=0; j<a_len+b_len+2; ++j) {
                    mat[i][j] = 0;

                }
            }

            int carry=0, n,x=a_len-1,y=b_len-1;
            for(int i=0; i<b_len; ++i) {
                x=a_len-1;
                carry = 0;
                for(int j=(a_len+b_len+2-1)-i; j>=0; --j) {
                    if((x>=0)&&(y>=0))  {
                        n = ((tmp[x]-'0')*(Mult.toString()[y]-'0'))+carry;
                        mat[i][j] = n%10;
                        carry = getCarry(n);
                    }
                    else if((x>=-1)&&(y>=-1)) mat[i][j] = carry;
                    x=x-1;
                }
                y=y-1;
            }

            carry = 0;
            int sum_arr[a_len+b_len+2];
            for(int i =0; i<a_len+b_len+2; ++i) sum_arr[i] = 0;
            for(int i=0; i<b_len; ++i) {
                for(int j=a_len+b_len+2-1; j>=0; --j) {
                    sum_arr[j] += (mat[i][j]);
                }
            }
            int temp;
            for(int i=a_len+b_len+2-1; i>=0; --i) {
                sum_arr[i] += carry;
                temp = sum_arr[i];
                sum_arr[i] = sum_arr[i]%10;
                carry = getCarry(temp);
            }

            for(int i=0; i<a_len+b_len+2; ++i) {
                ret.push_back(char(sum_arr[i]+48));
            }

            while(ret[0]=='0'){
                ret = ret.substr(1,ret.length()-1);
            }
            return ret;
        }


        int signum(){
            string tmp = getBase();
            if(tmp[0]=='-') return -1;
            else if(tmp[0]=='0' && tmp.size()==count_zeros(tmp)) return 0;
            else return 1;
        }


        long long size(){
            long long count = 0;
            string tmp = getBase();
            for(int i=0; tmp[i]; i++){
                count++;
            }
            return count;
        }


        BigNumber subtract(BigNumber Sub){
            string tmp = getBase();
            string sub = (tmp.length()>Sub.toString().length())? tmp : Sub.toString();
            int differenceInLength = std::abs( (int)(tmp.size() - Sub.toString().size()) );

            if(tmp.size() > Sub.toString().size())
                Sub.toString().insert(0, differenceInLength, '0');

            else
                tmp.insert(0, differenceInLength, '0');

            for(int i=tmp.length()-1; i>=0; --i) {
                if(tmp[i] < Sub.toString()[i]) {
                    tmp[i] += 10;
                    tmp[i-1]--;
                }
                sub[i] = ((tmp[i]-'0')-(Sub.toString()[i]-'0')) + '0';
            }

            while(sub[0]=='0' && sub.length()!=1)
                sub.erase(0,1);

            return sub;
        }


        double toDouble(){
            double d;
            istringstream(getBase()) >> d;
            return d;
        }


        int toInt(){
            int i;
            istringstream(getBase()) >> i;
            return i;
        }


        long toLong(){
            long l;
            istringstream(getBase()) >> l;
            return l;
        }


        long long toLongLong(){
            long long ll;
            istringstream(getBase()) >> ll;
            return ll;
        }


        string toString(){
            return getBase();
        }


        static BigNumber valueOf(int val){
            string tmp;
            if(!val) return BigNumber("0");
            while(val){
                tmp.push_back(val%10 + '0');
                val/=10;
            }
            reverse(tmp.begin(),tmp.end());
            return BigNumber(tmp);
        }


    private:
        string base;

        void include_zeros(string &a, string &b){
            int _size = b.size() - a.size();
            string tmp="";
            while(_size--){
                tmp+="0";
            }
            a=tmp+a;
        }

        int count_zeros(string tmp){
            int count=0;
            for(int i=0; tmp[i]; i++){
                if(tmp[i]=='0') count++;
            }
            return count;
        }

        int getCarry(int num) {
            int carry = 0;
            if(num>=10) {
                while(num!=0) {
                    carry = num %10;
                    num = num/10;
                }
            }
            else carry = 0;
            return carry;
        }

        bool isNegative(){
            return base[0]=='-';
        }

        bool isNumber(string s){
            int cont=0;
            for(int i=0; s[i]; i++){
                if(isdigit(s[i]) || s[i]=='-' || (s[i]=='.' && i!=0 && i!=s.size()-1)) cont++;
            }
            return cont==s.size();
        }
};


std::ostream& operator<< (std::ostream& out, BigNumber bn) {
    out << bn.getBase();
    return out;
}


#endif // BIGNUMBER_H
