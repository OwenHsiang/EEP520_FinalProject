#ifndef __TARGET_AGENT__H
#define __TARGET_AGENT__H 

#include "enviro.h"
#include "limits.h"
using namespace enviro;

class targetController : public Process, public AgentInterface {

    public:
    targetController() : Process(), AgentInterface() {}

    void init() {
        watch("button_click", [&](Event& e) {
              if ( e.value()["value"] == "reset" ) {
                teleport(250.0, 0, angle());
              } else if (e.value()["value"] == "f") {
                teleport(INT_MAX, 0, angle());
              }
        });
    }
    void start() {}
    void update() {
        float goal_x = 0;
        watch("target_change", [&](Event& e) {
            goal_x = e.value()["x"];
        teleport(goal_x,y(), angle());});
        label("X_image: " + std::to_string(x()),-50,-50);
    }
    void stop() {}

};

class target : public Agent {
    public:
    target(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    targetController c;
};

DECLARE_INTERFACE(target)

#endif