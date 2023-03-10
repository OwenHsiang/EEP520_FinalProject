#ifndef __LIGHT_AGENT__H
#define __LIGHT_AGENT__H 

#include "enviro.h"

using namespace enviro;

class lightController : public Process, public AgentInterface {

    public:
    lightController() : Process(), AgentInterface() {}

    void init() {
        label("X_object: " + std::to_string(x()),-50,-50);
    }
    void start() {}
    void update() {}
    void stop() {}

};

class light : public Agent {
    public:
    light(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    lightController c;
};

DECLARE_INTERFACE(light)

#endif