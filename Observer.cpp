#include<vector>
#include<algorithm>
#include<iostream>
class ObserverInterface{
public:
    ObserverInterface(){};
    virtual ~ObserverInterface(){};
    virtual void update(float temp, float humi, float press){};
};

class SubjectInterface{
public:
    std::vector<ObserverInterface *> obList;
    SubjectInterface(){};
    void registerObserver(ObserverInterface* observer){
        obList.push_back(observer);
        return ;
    };
    void removeObserver(ObserverInterface* observer){
        std::vector<ObserverInterface*>::iterator it = std::find(obList.begin(),obList.end(),observer);
        if(it == obList.end()){
            std::cout << "Observer has not been registered" << std::endl;
            return ;
        }
        obList.erase(it);
        return ;
    };
    virtual void notifyObservers(){};
    virtual ~SubjectInterface(){};
};
class WeatherData: public SubjectInterface{
public:
    
    void getTemperature();
    void getHumidity();
    void getPressure();
    void notifyObservers() override{
        for(auto it=obList.begin(); it!= obList.end(); it++)
            (*it)->update(temperature, humidity, pressure);
        return ;
    }
    void measurementsChanged(){
        notifyObservers();
    };
    void setMeasurements(float temp, float humi, float press){
        temperature = temp;
        humidity = humi;
        pressure = press;
        measurementsChanged();
        return ;
    }
private:
    float temperature;
    float humidity;
    float pressure;
};
class CurrentConditionsDisplayer : public ObserverInterface{
public:
    CurrentConditionsDisplayer(SubjectInterface* sub){
        subject = sub;
        subject->registerObserver(this);
    }
    void update(float temp, float humi, float press){
        temperature = temp;
        humidity = humi;
        pressure = press;
        display();
    };
    void display(){
        std::cout << "temperature: " << temperature << " humidity: " << humidity << " pressure: " << pressure << std::endl;
    };
private:
    float temperature, humidity, pressure;
    SubjectInterface* subject;
};
int main(){
    WeatherData wd;
    CurrentConditionsDisplayer *cur = new CurrentConditionsDisplayer(&wd);
    wd.setMeasurements(3.0,2.0,4.0);
    return 0;
}