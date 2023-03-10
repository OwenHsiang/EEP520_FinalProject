#ifndef __PATH_AGENT__H
#define __PATH_AGENT__H 

#include "enviro.h"

using namespace enviro;

class PathController : public Process, public AgentInterface {

    public:
    PathController() : Process(), AgentInterface() {}

    void init() {
        label("Optical axis (focal length: 125)" , -500,-10);
    }
    void start() {}
    void update() {}
    void stop() {}

};

class Path : public Agent {
    public:
    Path(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    PathController c;
};

DECLARE_INTERFACE(Path)

#endif