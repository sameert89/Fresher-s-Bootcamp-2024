
#include <bits/stdc++.h>

using namespace std;

class IObserver{
    public:
        virtual void update(string state) = 0;
};
class ConcObserverA : public IObserver{
    public:
        void update(string state){
            // implementation
        }
};
class Thread{
    private:
        string Id;
        string state;
        int priority;
        vector<IObserver*> observers;
        void notify(){
            for(auto IObserverObjRef: observers){
                IObserverObjRef->update(this->state);
            }
        }
    public:
        Thread(){
            this->state = "created";
            this->notify();
        }
        void start(){
            this->state = "running";
            this->notify();
        }
        void abort(){
            this->state = "aborted";
            this->notify();
        }
        void sleep(int t){
            this->state = "sleeping";
            this->notify();
            sleep(t/1000);
            this->state = "running";
            this->notify();
        }
        void wait(){
            this->state = "waiting";
            this->notify();
        }
        void suspended(){
            this->state = "suspended";
            this->notify();
        }
        void subscribe(IObserver* IObserverObjRef){
            this->observers.push_back(IObserverObjRef);
        }
        void unsubscribe(IObserver* IObserverObjRef){
            this->observers.erase(find(this->observers.begin(), this->observers.end(), IObserverObjRef));
        }
};


int main()
{
    cout<<"Hello World";

    return 0;
}
