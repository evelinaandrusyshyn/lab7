#include <iostream>
#include <cstring>
using namespace std;
char* input(const char* msg,int max){
    char* str=new char[max];
    cout<<msg;
    cin.getline(str,max);
    return str;
}
char inputChar(const char* msg){
    char c;
    cout<<msg;
    cin>>c;
    cin.ignore();
    return c;
}
void parseStr(const char* s,char c,char*& before,char*& after){
    const char* pos=strchr(s,c);
    if(pos){
        int Before=pos-s;
        int After=strlen(s)-Before-1;
        before=new char[Before+1];
        after=new char[After+1];
        strncpy(before,s,Before);
        before[Before]='\0';
        strcpy(after,pos+1);
    }else{
        before=new char[strlen(s)+1];
        strcpy(before,s);
        after=new char[1];
        after[0]='\0';
    }
}
void print(const char* msg,const char* str){
    cout<<msg<<str<<endl;
}
int main(){
    const int MAX=200;
    char* s=input("Введіть рядок: ",MAX);
    char c=inputChar("Введіть символ для розбиття: ");
    char* before=nullptr;
    char* after=nullptr;
    parseStr(s,c,before,after);
    print("\nПочатковий рядок: ",s);
    print("Частина до символу: ",before);
    print("Частина після символу: ",after);
    delete[] s;
    delete[] before;
    delete[] after;
    return 0;
}
