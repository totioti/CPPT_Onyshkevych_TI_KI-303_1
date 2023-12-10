#include <iostream>
#include <string>

class TV
{
private:
    bool isOn;
    int currentChannel;
    int volumeLevel;
    int baseChannel;
    int baseVolume;
    std::string brand;
    float size;
    float price;

public:

    TV(std::string brand, float size, float price)
    {
        this->isOn = false;
        this->baseChannel = 0;
        this->baseVolume = 0;
        this->volumeLevel = baseVolume;
        this->currentChannel = baseChannel;
        this->brand = brand;
        this->size = size;
        this->price = price;
    }

    void turn()
    {
        std::cout << (this->isOn ? "Turning OFF the " : "Turning ON the ") << this->brand << " TV..." << std::endl;
        
        this->isOn = !this->isOn;
    }

    void setChannel(int channel) 
    {
        if (this->isOn && channel > 0)
        {
            this->currentChannel = channel;
        }
    }

    void volumeUp()
    {
        if (this->isOn && this->volumeLevel < 100)
        {
            this->volumeLevel++;
        }

    }

    void volumeDown() 
    {
        if (this->isOn && this->volumeLevel > 0)
        {
            this->volumeLevel--;
        }
    }

    void showInfo()
    {
            std::cout << "TV Brand: " << this->brand << std::endl;
            std::cout << "Size: " << this->size <<" Inch" << std::endl;
            std::cout << "Price: " << this->price << " $" << std::endl;
            std::cout << "Power: " << (this->isOn ? "On" : "Off") << std::endl;
            std::cout << "Channel: " << this->currentChannel << std::endl;
            std::cout << "Volume: " << this->volumeLevel << std::endl;
    }
};
class TvWithTuner : public TV
{
private:
    std::string brand;
    float size;
    float price;


public:
    TvWithTuner(std::string brand, float size, float price) : TV (brand, size, price)
    {
        this->brand = brand;
        this->size = size;
        this->price = price;
    }

};

int main()
{
    TV tv = TV("Samsung", 44, 350.99);
    TvWithTuner tv1 = TvWithTuner("Volodia", 50, 400);

    tv.turn();

    for (int i = 0; i < 25; i++)
    {
        tv.volumeUp();
    }

    tv.showInfo();

    tv1.turn();

    return 0;
}