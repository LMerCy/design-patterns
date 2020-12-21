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
class StatisticDisplayer : public ObserverInterface{
public:
    StatisticDisplayer(SubjectInterface* sub): maxtemp(-100.0), mintemp(200.0), avgtemp(0.0), numreadings(0){
        sb = sub;
        sub->registerObserver(this);
    };
    void update(float temp, float humi, float press){
        avgtemp += temp;
        maxtemp = maxtemp > temp ? maxtemp:temp;
        mintemp = mintemp < temp ? mintemp:temp;
        numreadings ++ ;
        display();
    }
    void display(){
        std::cout << "maxtemp: " << maxtemp << "mintemp: "<< mintemp << "avragetemp:"  << avgtemp / numreadings << std::endl;
    }

private:
    float maxtemp=-100.0, mintemp=200.0, avgtemp=0.0;
    int numreadings=0;
    SubjectInterface *sb;
};
int main(){
    // test
    WeatherData wd;
    CurrentConditionsDisplayer *cur = new CurrentConditionsDisplayer(&wd);
    StatisticDisplayer * statis = new StatisticDisplayer(&wd);
    wd.setMeasurements(3.0,2.0,4.0);
    wd.setMeasurements(1.0,2.0,4.0);
    return 0;
}