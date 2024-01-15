
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
        }
        void start(){
            this->state = "running";
        }
        void abort(){
            this->state = "aborted";
        }
        void sleep(int t){
            this->state = "sleep";
            sleep(t/1000);
            this->state = "running";
        }
        void wait(){
            this->state = "waiting";
        }
        void suspended(){
            this->state = "suspended";
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
