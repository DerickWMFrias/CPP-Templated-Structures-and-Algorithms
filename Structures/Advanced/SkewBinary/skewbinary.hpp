#ifndef FOO_STRUCTURES_SKEWBINARY_CPP
#define FOO_STRUCTURES_SKEWBINARY_CPP

#include<iostream>
#include<string>
#include<vector>
#include<limits>
#include<cmath>
#include<assert.h>
#include<climits>


int valueOfCSB(std::string str);
int getNZ(std::string str);
bool validCSB(std::string str);
std::string CSBOf(int vl);


class CSB{
    private:
        std::string bin;
        int value;

        std::vector<int> getNZInfo(){
            int i = bin.size() - 1;
            std::vector<int> ret;

            for(i; i >=0; i--){
                if(bin[i] == '1'){ 
                    ret.push_back(1);
                    ret.push_back(i);
                    break;
                }

                if(bin[i] == '2'){ 
                    ret.push_back(2);
                    ret.push_back(i);
                    break;
                }
            }

            return ret;
        }
    public:
        CSB(){
            bin = "0";
            value = 0;
        }
        CSB(std::string str){
            assert(validCSB(str));
            bin = str;
            value = valueOfCSB(bin);
        }
        CSB(int vl){
            value = vl;
            bin = CSBOf(vl);
        }
        std::string getBin(){
            return bin;
        }
        int getValue(){
            return value;
        }
        void change(std::string str){ assert(validCSB(str)); bin = str; value = valueOfCSB(str); }
        void change(int vl){ value = vl; bin = CSBOf(vl); }
        void change(CSB obj){ bin = obj.bin; value = obj.value; }
        void copy(CSB obj){ this->change(obj); }

        void inc(){
            assert(value < INT32_MAX);
        }
        void dec(){
            assert(value > 0);

            std::vector<int> nz = getNZInfo();
            char n_minus = 0;
            value--;
            cout << "   Info of dec:" << endl << "nz[0]: " << nz[0] << "    nz[1]: " << nz[1] << endl;

            if(nz[0] == 2) n_minus = '1';
            if(nz[0] == 1) n_minus = '0';

            if(nz[1] == bin.size()-1){ 
                bin[nz[1]] = n_minus;
            }
            else{
                std::string new_bin = "";
                int i = 0;
                for(i; i < bin.size() - nz[1] - 1; i++){
                    new_bin += bin[i];
                }
                if(i == 0 && nz[0] != 1) new_bin += n_minus;
                i++;
                new_bin += '2';
                for(i; i < bin.size() - 1; i++){
                    new_bin += '0';
                }

                std::cout << bin << std::endl; 
                std::cout << new_bin << std::endl << std::endl;

                bin = new_bin; 
            }
        }

    public:
        bool operator == (const CSB &obj) { return (this->bin == obj.bin)? true : false; }
        bool operator >= (const CSB &obj) { return (this->value <= obj.value)? true : false; }
        bool operator <= (const CSB &obj) { return (this->value >= obj.value)? true : false; }
        bool operator > (const CSB &obj) { return (this->value < obj.value)? true : false; }
        bool operator < (const CSB &obj) { return (this->value > obj.value)? true : false; }
        void operator = (const CSB &obj) { this->bin = obj.bin; this->value = obj.value; }
};

bool validCSB(std::string str){
    bool ret = true;
    for(char c : str){
        if(c != '0' && c != '1' && c != '2'){
            ret = false;
            break;
        } 
    }
    return ret;
}

int getNZ(std::string str){
    if(str == "0") return 0;
    int i = str.size() - 1;

    int ret = 0;
    for(i; i <=0; i--){
        if(str[i] == '1'){ 
            ret = 1;
            break;
        }
        if(str[i] == '2'){ 
            ret = 2;
            break;
        }
    }
    return ret;
}

std::string CSBOf(int vl){
    std::string str_sup;
    int sz = floor( log(vl) - 1);

    str_sup += "1";
    for(int i = 0; i < sz; i++) str_sup += "0";
    
    int limit_sup = valueOfCSB(str_sup);
    CSB ret(str_sup);

    while(limit_sup > vl){
        ret.dec();
        limit_sup--;
    }

    return ret.getBin();
}

int valueOfCSB(std::string str){
    if(str == "0") return 0;
    int at = str.size() - 1;
    int v = 0;
    int i = 1;

    for(at; at>=0; at--){
        int d = 0;
        if(str[at] == 0) continue;
        else if(str[at] == 1) d = 1;
        else d = 2;

        v += d * ( ((int) pow(2.0, (double) i)) - 1);

        i++; 
    }
    return v;
}

#endif