#include<iostream>
#include<string>
using namespace std;

class Weapon{
public:
    virtual void shoot()=0;
    virtual void reboot()=0;
    virtual ~Weapon()=default;
};

class Gun:public Weapon{
protected:
    int bullets;
    int max_bullets;

public:
    Gun(int max=10):max_bullets(max),bullets(max){}

    void reboot() override{
        if(bullets==max_bullets){
            cout<<"Magazine already full!"<<endl;
            return;
        }
        bullets=max_bullets;
        cout<<"Reloaded! ("<<bullets<<" bullets)"<<endl;
    }

    bool hasAmmo()const{return bullets>0;}
    void decreaseAmmo(){if(bullets>0)bullets--;}
    int getBullets()const{return bullets;}
};

class Pistol:public Gun{
public:
    Pistol():Gun(8){}

    void shoot() override{
        if(!hasAmmo()){
            cout<<"Empty magazine!"<<endl;
            return;
        }
        cout<<"* "<<endl;
        decreaseAmmo();
        cout<<"("<<bullets<<" left)"<<endl;
    }
};

class Crossbow:public Gun{
public:
    Crossbow():Gun(5){}

    void shoot() override{
        if(!hasAmmo()){
            cout<<"No bolts left!"<<endl;
            return;
        }
        cout<<"-> "<<endl;
        decreaseAmmo();
        cout<<"("<<bullets<<" bolts left)"<<endl;
    }
};

class MachineGun:public Gun{
public:
    MachineGun():Gun(30){}

    void shoot() override{
        if(!hasAmmo()){
            cout<<"Ammo belt empty!"<<endl;
            return;
        }
        int shots=5;
        if(bullets<5)shots=bullets;
        cout<<"Tatata! "<<endl;
        for(int i=0;i<shots;i++){
            cout<<"-";
            decreaseAmmo();
        }
        cout<<" ("<<bullets<<" left)"<<endl;
    }
};

class Nunchaku:public Weapon{
public:
    void shoot() override{
        cout<<"Swish-swish!"<<endl;
    }

    void reboot() override{
        cout<<"Spinning nunchaku... ready!"<<endl;
    }
};

class weaponsystem
{
private:
    Pistol pistol;
    Crossbow crossbow;
    MachineGun mgun;
    Nunchaku nunchaku;

    Weapon* weapons[4]={&pistol,&crossbow,&mgun,&nunchaku};
    int current=0;

public:

    void show_status()
    {
        cout<<"Current weapon: "<<current+1<<endl;
        Gun* gun=dynamic_cast<Gun*>(weapons[current]);  //pointer
        if(gun){
            cout<<"Ammo: "<<gun->getBullets()<<endl;
        }
        else{
            cout<<"Ammo: infinite"<<endl;
        }
    }

    void shoot_weapon()
    {
        weapons[current]->shoot();
    }

    void reload_weapon()
    {
        Gun* gun=dynamic_cast<Gun*>(weapons[current]);

        if(gun){
            gun->reboot();
        }
        else{
            weapons[current]->reboot();
        }
    }

    void select_weapon()
    {
        int w;
        cout<<"Choose weapon (1-4): "<<endl;
        cin>>w;

        if(w>=1 && w<=4){
            current=w-1;
            cout<<"Weapon "<<w<<" selected"<<endl;
        }
        else{
            cout<<"Invalid weapon"<<endl;
        }
    }

    bool menu()
    {
        cout<<"Weapon System"<<endl;
        cout<<"1.Select weapon"<<endl;
        cout<<"2.Shoot"<<endl;
        cout<<"3.Reload"<<endl;
        cout<<"4.Show ammo"<<endl;
        cout<<"0.Quit"<<endl;
        int choice;
        cin>>choice;

        switch(choice){
        case 1: select_weapon(); return false;
        case 2: shoot_weapon(); return false;
        case 3: reload_weapon(); return false;
        case 4: show_status(); return false;
        case 0: return true;
        default:
            cout<<"ERROR! Try again"<<endl;
            return false;
        }
    }
};

int main()
{
    weaponsystem ws;
    cout<<"Welcome to the Weapon System"<<endl;
    while(!ws.menu()){
    }
    cout<<"Goodbye!"<<endl;

    return 0;
}