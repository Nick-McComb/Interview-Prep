/*
make small class for practice
*/
#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>
#include <vector>
#include <optional>
#include <algorithm>


class Engine{
    public:
        Engine(std::string type): mType(type) {}
        void startEngine(){ mRunning = true; }
        void stopEngine(){ mRunning = false; }
        void drive(int distance){
            if(!mRunning){
                throw std::logic_error("Engine is not running!"); //choose this over expected or bool return, due to improper use
            }
            mMileage += distance;
        }
        int getMileage() const{
            return mMileage;
        }

    private:
        std::string mType{};
        bool mRunning = false;
        int mMileage{0};
};



class Vehicle{
    public:
        Vehicle(std::string name, std::string type): mName(name){
            mEngine = std::make_unique<Engine>(type);
        }
        void turnOn() const{
            mEngine->startEngine();
        }
        void turnOff() const{
            mEngine->stopEngine();
        }
        bool startDrive(int distance){
            mEngine->drive(distance);
            return true;
        }
        std::string getName() const {
            return mName;
        }
        int getMileage() const{
            return mEngine->getMileage();
        }
    private:
        std::string mName{};
        std::unique_ptr<Engine> mEngine = nullptr;
};

class Fleet{
    public:
        Fleet(std::string name): mName(name){}
        bool inFleet(std::shared_ptr<Vehicle> vehicleToSearch){
            auto it = std::find(mFleet.begin(), mFleet.end(), vehicleToSearch);
            if(*it){
                return true;
            }
            return false;
        }
        bool addVehicle(std::shared_ptr<Vehicle> vehicleToAdd){
            // if(inFleet(vehicleToAdd)){
            //     return false;
            // }
            mFleet.push_back(vehicleToAdd);
            return true;
        }
        void driveTogether(int distance){
            for(auto& vehicle : mFleet){
                vehicle->startDrive(distance);
            }
        }
        void printFleet() const{
            for(auto& vehicle : mFleet){
                std::cout<< "Type: " <<vehicle->getName() << ", Mileage: " << vehicle->getMileage() << '\n';
            }
        }
        
    private:
        std::string mName{};
        std::vector<std::shared_ptr<Vehicle>> mFleet{};
        
};


int main(){
    Vehicle v("Ford Escape", "Dissel");
    v.turnOn();
    v.startDrive(10);

    std::shared_ptr<Vehicle> v1 = std::make_shared<Vehicle>("VW Jetta", "89");
    v1->turnOn();
    v1->startDrive(30);

    std::shared_ptr<Vehicle> v2 = std::make_shared<Vehicle>("Ford Escape", "dissel");
    v2->turnOn();
    v2->startDrive(70);

    Fleet f("The Boys");

    f.addVehicle(v1);
    f.addVehicle(v2);
    f.printFleet();
    f.driveTogether(10);
    f.printFleet();


    return 0;
}