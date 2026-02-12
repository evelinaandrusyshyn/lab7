#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
void input(char*&str,const char*message){
    char buffer[256];
    cout<<message;
    cin.getline(buffer,256);
    int len=strlen(buffer);
    str=new char[len+1];
    strcpy(str,buffer);
}
void print(const char*str,const char*message){
    cout<<message<<str<<endl;
}
int stringToInt(const char* str){
    int num=0;
    int i=0;
    while(str[i]>='0' && str[i]<='9'){
        num=num*10+(str[i]-'0');
        i++;
    }
    return num;
}
double calculateAverage(const char*line){
    double sum=0;
    int count=0;
    char buffer[256];
    strcpy(buffer,line);
    const char* delim="-#,";
    char* field=strtok(buffer,delim);
    if(field) field=strtok(NULL,delim);
    if(field) field=strtok(NULL,delim);
    while(field && count<5){
        sum+=stringToInt(field);
        count++;
        field=strtok(NULL,delim);
    }
    if(count==0) return 0;
    return sum/count;
}
int main(){
    int N;
    cout<<"Введіть кількість студентів: ";
    cin>>N;
    cin.ignore();
    char** students=new char*[N];
    for(int i=0;i<N;i++){
        input(students[i],"Введіть дані студента (прізвище-№ залікової-5 оцінок): ");
    }
    cout<<"\nВведені дані:\n";
    for(int i=0;i<N;i++){
        print(students[i],"Студент: ");
        double avg=calculateAverage(students[i]);
        cout<<"Середній бал: "<<avg<<"\n\n";
    }
    for(int i=0;i<N;i++) delete[] students[i];
    delete[] students;
    return 0;
}
