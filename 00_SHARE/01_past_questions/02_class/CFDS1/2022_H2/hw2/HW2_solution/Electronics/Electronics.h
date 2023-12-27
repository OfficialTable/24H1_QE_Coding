#pragma once

// Fill in here
#include <stdlib.h>
class Electronics {
    public:
        Electronics(float aSize); // constructor
        
        void SetSize(float aSize); // accessors
        float GetSize(void);
        virtual float Price(void);
        virtual void PrintSelf() = 0;

        protected:
        float size;
    };

class TV : public Electronics {
    public:
        TV(float aSize) : Electronics(aSize) {}; // constructor
        
        float Price(void);
        void PrintSelf();
    };

class Cellphone : public Electronics {
    public:
        Cellphone(float aSize) : Electronics(aSize) {}; // constructor
        
        float Price(void);
        void PrintSelf();
    };

class Computer : public Electronics {
    public:
        Computer(float aSize) : Electronics(aSize) {}; // constructor

        virtual float Price(void);
        void PrintSelf();
    };

class Laptop : public Computer {
    public:
        Laptop(float aSize) : Computer(aSize) {
            int nGPU = 0;
            GPU1 = NULL;
            GPU2 = NULL;
        }; // constructor
    
        void AddGPU(Computer *aCub);
        float Price(void);
        float TotalPrice(void); void PrintSelf();
    
    protected:
        Computer *GPU1;
        Computer *GPU2;
        int nGPU;
};
