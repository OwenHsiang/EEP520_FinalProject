#ifndef __LABEL_AGENT__H
#define __LABEL_AGENT__H 

#include "enviro.h"

using namespace enviro;

class LabelController : public Process, public AgentInterface {

    public:
    LabelController() : Process(), AgentInterface() {}

    void init() {
        watch("button_click", [&](Event& e) {
              if ( e.value()["value"] == "reset" ) {
                label("Image distance: 250 / Object distance: 250", 5,-2);
              } else if (e.value()["value"] == "f") {
                label("Image distance: inf / Object distance: 125", 5,-2);
              }
        });
        label("Image distance: 250 / Object distance: 250", 5,-2);
    }
    void start() {}
    void update() {
        float goal_x = 0;
        float x_lens = 0;
        watch("target_change", [&](Event& e) {
            goal_x = e.value()["x"];
    
        watch("x_lens", [&](Event& e) {
            x_lens = e.value()["xlens"];
        
        float xi = goal_x-x_lens;
        float xo = x_lens+250;
        if (xi == xo) {
            label("Image distance: 250 / Object distance: 250", 5,-2);
        } else {
            label("Image distance: " + std::to_string(xi) + " / " + "Object distance: " + std::to_string(xo), 5,-2);
        }
    });});
        
    }
    void stop() {}

};

class Label : public Agent {
    public:
    Label(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    LabelController c;
};

DECLARE_INTERFACE(Label)

#endif