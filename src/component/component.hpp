#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <iostream>

class Component {
    public:
        virtual void init() = 0;

};

class Woo:Component {
    public:
        void init() override;
};


#endif // COMPONENT_H_
