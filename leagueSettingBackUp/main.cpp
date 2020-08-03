#include <bits/stdc++.h>
#include <conio.h>
#include <direct.h>
using namespace std;
const int maxn=(1<<10);

string folderPath = R"(D:\leagueSettingBackup)";//���������ļ���·����~
string gamePath=R"(D:\Program Files\League of Legends\Game\Config)";//��Ϸ��·����~

void createBackupPath();//�����ļ���
void backup();//����
void recovery();//�ָ�


void createBackupPath(){
    if (0 != access(folderPath.c_str(), 0))
    {
        mkdir(folderPath.c_str());   // ���� 0 ��ʾ�����ɹ���-1 ��ʾʧ��
    }
}


void backup(){
    int kb;
    cout<<"��ע�⣡�˲����Ὣ��ԭ���еı����ļ����ǣ�"<<endl;
    cout<<"����㻹δ���ݣ����Դ�����Ϣ����1�������ݣ�����esc�˳�����"<<endl;
    while (1) {
        if (_kbhit()) {//����а������£���_kbhit()����������
            kb = _getch();//ʹ��_getch()������ȡ���µļ�ֵ
            if (kb == 49) {
                break;
            }
            if (kb == 27) {
                exit(0);
            }
        }
    }
    cout <<"**************������**************"<<endl;
    cout<<endl;
    //ʹ�ö��������������
    ifstream filein1(gamePath+R"(\PersistedSettings.json)",ios::binary);
    ofstream fileout1(folderPath+R"(\PersistedSettings.json)",ios::binary);
    //�ַ�������
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
    //����input.ini
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
    //����game.cfg
    ifstream filein3(gamePath+R"(\game.cfg)",ios::binary);
    ofstream fileout3(folderPath+R"(\game.cfg)",ios::binary);
    //�ַ�������
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
    cout <<"**************�������**************"<<endl;
    system("pause");
    exit(0);
}


void recovery(){
    cout <<"**************�ָ���**************"<<endl;
    cout<<endl;
    //ʹ�ö��������������
    ifstream filein1(folderPath+R"(\PersistedSettings.json)",ios::binary);
    ofstream fileout1(gamePath+R"(\PersistedSettings.json)",ios::binary);
    //�ַ�������
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
    //�ָ�input.ini
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
    //�ָ�game.cfg
    ifstream filein3(folderPath+R"(\game.cfg)",ios::binary);
    ofstream fileout3(gamePath+R"(\game.cfg)",ios::binary);
    //�ַ�������
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
    cout<<"**************�ָ����**************"<<endl;
    system("pause");
    exit(0);
}
int main(){
    int kb;
    createBackupPath();
    cout<<"ʹ��˵�����ȵ�¼��ԭ��ʹ�õ��˺ţ���1�������á�"<<endl;
    cout<<"�������˺ŵ�¼��Ϸ��ʹ�ÿո�ָ����á�"<<endl;
    cout<<"�����򱸷ݵ������ļ������ϴ����ƶˡ�"<<endl;
    cout<<"��һ��ʹ�ð�1����LOL���ã����ո�ָ�����"<<endl;
    cout<<"��esc�˳�����"<<endl;
    while (1){
        if (_kbhit()){
            kb = _getch();//ʹ��_getch()������ȡ���µļ�ֵ
            if (kb == 49) {
                backup();
            }
            else if (kb == 32){
                recovery();
            }
            if (kb == 27){
               break;
            }//������ESCʱ�˳���ESC���ļ�ֵʱ27.
        }
    }
    return 0;
}