#include <bits/stdc++.h>
#include <conio.h>
#include <direct.h>
using namespace std;
const int maxn=(1<<10);

string folderPath = R"(D:\leagueSettingBackup)";//备份设置文件夹路径名~
string gamePath=R"(D:\Program Files\League of Legends\Game\Config)";//游戏的路径名~

void createBackupPath();//创建文件夹
void backup();//备份
void recovery();//恢复


void createBackupPath(){
    if (0 != access(folderPath.c_str(), 0))
    {
        mkdir(folderPath.c_str());   // 返回 0 表示创建成功，-1 表示失败
    }
}


void backup(){
    int kb;
    cout<<"请注意！此操作会将你原来有的备份文件覆盖！"<<endl;
    cout<<"如果你还未备份，忽略此条信息并按1继续备份，否则按esc退出程序！"<<endl;
    while (1) {
        if (_kbhit()) {//如果有按键按下，则_kbhit()函数返回真
            kb = _getch();//使用_getch()函数获取按下的键值
            if (kb == 49) {
                break;
            }
            if (kb == 27) {
                exit(0);
            }
        }
    }
    cout <<"**************备份中**************"<<endl;
    cout<<endl;
    //使用二进制输入输出流
    ifstream filein1(gamePath+R"(\PersistedSettings.json)",ios::binary);
    ofstream fileout1(folderPath+R"(\PersistedSettings.json)",ios::binary);
    //字符流缓冲
    while(!filein1.eof()){
        char buf[maxn]="";
        int len=sizeof(buf);
        filein1.read(buf,sizeof(buf));
        if(filein1.peek()==-1){
            char *p=&buf[len-1];
            while((*p)==0){
                len--;
                p--;
            }
        }
        fileout1.write(buf,len);
    }
    filein1.close();
    fileout1.flush();
    fileout1.close();
    //备份input.ini
    ifstream filein2(gamePath+R"(\input.ini)",ios::binary);
    ofstream fileout2(folderPath+R"(\input.ini)",ios::binary);
    while(!filein2.eof()){
        char buf[maxn]="";
        int len=sizeof(buf);
        filein2.read(buf,sizeof(buf));
        if(filein2.peek()==-1){
            char *p=&buf[len-1];
            while((*p)==0){
                len--;
                p--;
            }
        }
        fileout2.write(buf,len);
    }
    filein2.close();
    fileout2.flush();
    fileout2.close();
    //备份game.cfg
    ifstream filein3(gamePath+R"(\game.cfg)",ios::binary);
    ofstream fileout3(folderPath+R"(\game.cfg)",ios::binary);
    //字符流缓冲
    while(!filein3.eof()){
        char buf[maxn]="";
        int len=sizeof(buf);
        filein3.read(buf,sizeof(buf));
        if(filein3.peek()==-1){
            char *p=&buf[len-1];
            while((*p)==0){
                len--;
                p--;
            }
        }
        fileout3.write(buf,len);
    }
    filein3.close();
    fileout3.flush();
    fileout3.close();
    cout <<"**************备份完成**************"<<endl;
    system("pause");
    exit(0);
}


void recovery(){
    cout <<"**************恢复中**************"<<endl;
    cout<<endl;
    //使用二进制输入输出流
    ifstream filein1(folderPath+R"(\PersistedSettings.json)",ios::binary);
    ofstream fileout1(gamePath+R"(\PersistedSettings.json)",ios::binary);
    //字符流缓冲
    while(!filein1.eof()){
        char buf[maxn]="";
        int len=sizeof(buf);
        filein1.read(buf,sizeof(buf));
        if(filein1.peek()==-1){
            char *p=&buf[len-1];
            while((*p)==0){
                len--;
                p--;
            }
        }
        fileout1.write(buf,len);
    }
    filein1.close();
    fileout1.flush();
    fileout1.close();
    //恢复input.ini
    ifstream filein2(folderPath+R"(\input.ini)",ios::binary);
    ofstream fileout2(gamePath+R"(\input.ini)",ios::binary);
    while(!filein2.eof()){
        char buf[maxn]="";
        int len=sizeof(buf);
        filein2.read(buf,sizeof(buf));
        if(filein2.peek()==-1){
            char *p=&buf[len-1];
            while((*p)==0){
                len--;
                p--;
            }
        }
        fileout2.write(buf,len);
    }
    filein2.close();
    fileout2.flush();
    fileout2.close();
    //恢复game.cfg
    ifstream filein3(folderPath+R"(\game.cfg)",ios::binary);
    ofstream fileout3(gamePath+R"(\game.cfg)",ios::binary);
    //字符流缓冲
    while(!filein3.eof()){
        char buf[maxn]="";
        int len=sizeof(buf);
        filein3.read(buf,sizeof(buf));
        if(filein3.peek()==-1){
            char *p=&buf[len-1];
            while((*p)==0){
                len--;
                p--;
            }
        }
        fileout3.write(buf,len);
    }
    filein3.close();
    fileout3.flush();
    fileout3.close();
    cout<<"**************恢复完成**************"<<endl;
    system("pause");
    exit(0);
}
int main(){
    int kb;
    createBackupPath();
    cout<<"使用说明：先登录你原来使用的账号，按1备份设置。"<<endl;
    cout<<"在其他账号登录游戏后使用空格恢复设置。"<<endl;
    cout<<"本程序备份的设置文件不会上传到云端。"<<endl;
    cout<<"第一次使用按1备份LOL设置，按空格恢复设置"<<endl;
    cout<<"按esc退出程序！"<<endl;
    while (1){
        if (_kbhit()){
            kb = _getch();//使用_getch()函数获取按下的键值
            if (kb == 49) {
                backup();
            }
            else if (kb == 32){
                recovery();
            }
            if (kb == 27){
               break;
            }//当按下ESC时退出，ESC键的键值时27.
        }
    }
    return 0;
}