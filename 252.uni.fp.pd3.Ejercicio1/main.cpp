#include <iostream>
#include <string>
using namespace std;

string expand(string str,int inicio,int final1){
    while(inicio>=0 && final1< str.length() && (str[inicio]==str[final1])){
            inicio--;
            final1++;
    }
    return str.substr(inicio+1,final1-inicio-1);
}

string encuentraSubcadenaPalindromaMayor(string str){
    if(str.length()==0)   //validamos si la cadena contiene datos
        return str;
    string max_str="", actual_str;
    int maxima_longitud=0, actual_longitud;
    for(int i=0; i<str.length(); i++){
                for(int k=0; k<=1; k++){//k=0 caso impar: bananas, k=1 caso par:"abccba"
                        actual_str=expand(str,i,i+k);
                        actual_longitud=actual_str.length();
                        if(actual_longitud>maxima_longitud){
                            maxima_longitud=actual_longitud;
                            max_str= actual_str;
                        }
                }
    }
    return max_str;
}

int main()
{
    string str1="bananas";
    string str2="ABDCBCDBDCBBC";
    string str3="abracadabra";
    string str4="abccba";

    cout<<"La subcadena palindromica mas larga de: "<<str1<<" es:"
            <<encuentraSubcadenaPalindromaMayor(str1)<<endl;
    cout<<"La subcadena palindromica mas larga de: "<<str2<<" es:"
            <<encuentraSubcadenaPalindromaMayor(str2)<<endl;

    cout<<"La subcadena palindromica mas larga de: "<<str3<<" es:"
            <<encuentraSubcadenaPalindromaMayor(str3)<<endl;
    cout<<"La subcadena palindromica mas larga de: "<<str4<<" es:"
            <<encuentraSubcadenaPalindromaMayor(str4)<<endl;

    return 0;
}
