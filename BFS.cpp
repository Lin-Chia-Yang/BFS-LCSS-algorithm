#include <iostream>
#include <queue>
#include <vector>
using namespace std;
void printpuzzle(string now){//print puzzle
    for(int a=0;a<9;a++){
        if(a%3==2){
            cout <<now[a]<<endl;
        }
        else{
            cout << now[a]<<" ";
        }
    }
}
int searchzero(string now){//search zero
    for(int a=0;a<9;a++){
        if(now[a]=='0'){
            return a+1;

        }
    }
}
int main()
{
    queue<string> nowpuzzle;
    queue<int> record;
    queue<int> count;
    string puzzle[3][3];
    string s1="";
    string s2="";
    string want[3][3];
    int position;
    for(int i=0;i<3;i++){//change puzzle to string
        for(int j=0;j<3;j++){
            cin >> puzzle[i][j];
            s1=s1+puzzle[i][j];
        }
    }
    nowpuzzle.push(s1);
    record.push(0);
    record.push(searchzero(s1));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){//change target to string
            cin >> want[i][j];
            s2=s2+want[i][j];
        }
    }
    int once=0;
    static int amount1=0;
    count.push(0);
    printpuzzle(s1);
    while(true){
        string now=nowpuzzle.front();
        position=searchzero(now);//zero position
        nowpuzzle.pop();
        if(now==s2){
            break;
        }
        int amount=0;
        if(amount1==0){
            amount1=count.front();
            count.pop();
            if(once!=0){
                record.pop();
            }
        }
        if(position>3){//up
            swap(now[position-1],now[position-4]);
            if(searchzero(now)==record.front()){
                swap(now[position-1],now[position-4]);
            }
            else{
                nowpuzzle.push(now);
                amount=amount+1;
                record.push(searchzero(now));
                printpuzzle(now);
                if(now==s2){
                    break;
                }
                swap(now[position-1],now[position-4]);
            }
        }
        if((position%3)!=0){//right
            swap(now[position-1],now[position]);
            if(searchzero(now)==record.front()){
                swap(now[position-1],now[position]);
            }
            else{
                nowpuzzle.push(now);
                amount=amount+1;
                record.push(searchzero(now));
                printpuzzle(now);
                if(now==s2){
                    break;
                }
                swap(now[position-1],now[position]);
            }
        }
        if(position<7){//down
            swap(now[position-1],now[position+2]);
            if(searchzero(now)==record.front()){
                swap(now[position-1],now[position+2]);
            }
            else{
                nowpuzzle.push(now);
                amount=amount+1;
                record.push(searchzero(now));
                printpuzzle(now);
                if(now==s2){
                    break;
                }
                swap(now[position-1],now[position+2]);
            }
        }
        if((position%3)!=1){//left
            swap(now[position-1],now[position-2]);
            if(searchzero(now)==record.front()){
                swap(now[position-1],now[position-2]);
            }
            else{
                nowpuzzle.push(now);
                amount=amount+1;
                record.push(searchzero(now));
                printpuzzle(now);
                if(now==s2){
                    break;
                }
                swap(now[position-1],now[position-2]);
            }
        }
        if(amount1!=0){
            amount1=amount1-1;
        }
        count.push(amount);
        once=once+1;
    }
    return 0;
}
