#include<iostream>
#include<string>
using namespace std;
char ch[] = {'(', ')', '^', '+', '-', '_', '<','#', '.', '%', '&', '*', '@', '$','>', '/', ':', '?', '}', '{', ']', '[', '~', '!', ';', '.' };
int encryption(){
    string mess;
    string cipher;
   cout<<"Please enter the message: "<<endl;
   cin.ignore();
   getline(cin,mess);
   int key;
   cout<<"Please enter the key: "<<endl;
   cin>>key;
   int counter=0;
    for(int i=0;i<mess.length();++i){
        
    if(isalpha(mess[i])){
        counter=key;
        if(isupper(mess[i])){
           cipher+=char(int(mess[i]-65+key)%26+65);
            for(int j=i+1;j<mess.length();++j){
        if(mess[i]==mess[j])
           counter++;
           cipher[i]=char(int(cipher[i]-65-key+counter)%26+65);
    }
        }
        else if(islower(mess[i])){
           cipher+=char(int(mess[i]-97+key)%26+97);
            for(int j=i+1;j<mess.length();++j){
        if(mess[i]==mess[j])
           counter++;
           cipher[i]=char(int(cipher[i]-97-key+counter)%26+97);
    }
        }
   
    }
    else if(mess[i]==' ')
      cipher+=ch[rand()%26];
}
cout<<"cipher: "<<cipher;
return 0;
}

int decryption(){
  string cipher;
  string plain;
   cout<<"Please enter the message: "<<endl;
   cin.ignore();
   getline(cin,cipher);
   int key;
   cout<<"Please enter the key: "<<endl;
   cin>>key;
    for(int i=0;i<cipher.length();++i){
    if(isalpha(cipher[i])){
        if(isupper(cipher[i])){
          plain+=char(int(cipher[i]-65-key+26)%26+65);
            for(int j=i+1;j<cipher.length();++j){
               if(plain[i]==plain[j]-key)  
             plain+=char(int(cipher[i]-65-key+26)%26+65);
            }
        }
        else if(islower(cipher[i]))
          plain+=char(int(cipher[i]-97-key+26)%26+97);
}
    else if(cipher[i]==' ')
      plain+=' ';
}
cout<<"plain: "<<plain<<endl;
return 0;
}

int choice()
{
int choice;
cout<<"Please enter 1.Encryption 2.Decryption: "<<endl;
   cin>>choice;
return choice;
}
int main()
{ 
    int decision;
   decision=choice();
   
   if(decision==1)
    encryption();
   else if(decision==2)
     decryption();
    return 0;
    
}
