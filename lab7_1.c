#include <iostream>
#include <string.h>
using namespace std;
void input(char* &s,const char* msg){
    cout<<msg;
    char buffer[1000];
    cin.getline(buffer,1000);
    s=new char[strlen(buffer)+1];
    strcpy(s,buffer);
}
void print(const char* s,const char* msg){
    cout<<msg<<s<<endl;
}
void countLetters(const char* w,int freq[256]){
    for(int i=0;i<256;i++) freq[i]=0;
    for(int i=0;w[i]!='\0';i++) freq[(unsigned char)w[i]]++;
}
bool sameLetters(const char* w1,const char* w2){
    int f1[256],f2[256];
    countLetters(w1,f1);
    countLetters(w2,f2);
    for(int i=0;i<256;i++) if(f1[i]!=f2[i]) return false;
    return true;
}
void findWords(const char* sentence,const char* helpWord){
    cout<<"Слова, що складаються з тих самих літер:\n";
    char temp[1000];
    strcpy(temp,sentence);
    char* word=strtok(temp," ,.!?-");
    while(word!=NULL){
        if(sameLetters(word,helpWord)) cout<<word<<endl;
        word=strtok(NULL," ,.!?-");
    }
}
int main(){
    char* sentence=nullptr;
    char* helpWord=nullptr;
    input(sentence,"Введіть речення: ");
    input(helpWord,"Введіть допоміжне слово: ");
    print(sentence,"\nРечення: ");
    print(helpWord,"Допоміжне слово: ");
    cout<<"\n";
    findWords(sentence,helpWord);
    delete[] sentence;
    delete[] helpWord;
    return 0;
}
