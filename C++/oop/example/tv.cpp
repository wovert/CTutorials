#include <iostream>
#include <string>

using namespace std;
class TV {
    friend class Remote;
    // 默认 private
    enum { On, Off };
    enum { minVol, maxVol=100 };
    enum { minChannel, maxChannel = 255 };
    private:
        int mState; // 状态：开关机
        int mVolume; // 音量
        int mChannel; // 频道
    public:
        TV() {
            this->mState = Off;
            this->mVolume = minVol;
            this->mChannel = minChannel;
        }
        void onOrOff() {
            this->mState = (this->mState == On ? Off:On); 
        }
        // 加大音量
        void volumeUp(void) {
            if (this->mVolume >= maxVol) {
                return;
            }
            this->mVolume++;
        }
        // 减小音量
        void volumeDown(void) {
            if (this->mVolume <= maxVol) {
                return;
            }
            this->mVolume--;
        }
        void channelUp(void) {
            if (this->mChannel >= maxChannel) {
                return;
            }
            this->mChannel++;
        }
        void channelDown(void) {
            if (this->mChannel <= minChannel) {
                return;
            }
            this->mChannel--;
        }
        void showState(void) {
            cout << "TV state:" << (this->mState == On ? "On" : "Off") << endl;
            cout << "TV volumne:" << this->mVolume << endl;
            cout << "TV channel:" << this->mChannel << endl;
        }
};

class Remote {
    private:
        TV *pTv;
    public:
        Remote(TV *pTv) {
            this->pTv = pTv;
        }
        void onOrOff() {
            this->pTv->onOrOff();
        }
        void volumeUp() {
            this->pTv->volumeUp();
        }
        void volumeDown() {
            this->pTv->volumeDown();
        }
        void channelUp() {
            this->pTv->channelUp();
        }
        void channelDown() {
            this->pTv->channelDown();
        }
        void setChannel(int num) {
            if (num >= TV::minChannel && num <= TV::maxChannel) {
                this->pTv->mChannel = num;
            }
        }

        void showState() {
            this->pTv->showState();
        }

};

void test01() {
    TV tv;
    tv.onOrOff();
    tv.volumeUp();
    tv.volumeUp();
    tv.volumeUp();

    tv.channelUp();
    tv.channelUp();
    tv.channelUp();

    tv.showState();
    
}

void test02() {
    TV tv;
    Remote rt(&tv);
    rt.onOrOff();
    rt.volumeUp();
    rt.volumeUp();
    rt.volumeUp();
    
    rt.channelUp();
    rt.channelUp();
    rt.channelUp();
    rt.channelUp();
    
    rt.showState();


    rt.setChannel(20);

    rt.showState();
}   

int main(int argc, char *argv[]) {
    // test01();
    test02();
    return 0;
}