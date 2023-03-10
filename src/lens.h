#ifndef __LENS_AGENT__H
#define __LENS_AGENT__H

#include "enviro.h"

using namespace enviro;

class LensController : public Process, public AgentInterface
{

public:
    LensController() : Process(), AgentInterface() {}

    void init()
    {
        watch("keydown", [&](Event &e)
              {
            auto k = e.value()["key"].get<std::string>();
            if ( k == "a") {
                float x_i = 0;
                 if (x()>= -120.0) {
                    teleport(x()-omega_m,y(), angle());}
                    x_i = x() + (1.0 / (1.0/125.0 - 1.0/(x()+250.0)));

                emit(Event("target_change", {{ "x", x_i}}));
                emit(Event("x_lens", {{ "xlens", x()}}));
            } else if ( k == "d" ) {
                float x_i2 = 0;

                teleport(x()+omega_m,y(), angle());
                    x_i2 = x() + (1.0 / (1.0/125.0 - 1.0/(x()+250.0)));

                emit(Event("target_change", {{ "x", x_i2 }}));
                emit(Event("x_lens", {{ "xlens", x()}}));
            } });

        watch("button_click", [&](Event &e)
              {
              if ( e.value()["value"] == "reset" ) {
                teleport(0, 0, angle());
              } else if (e.value()["value"] == "f") {
                teleport(-125.0, 0, angle());
              } });
    }
    void start() {}
    void update()
    {
        float x_i2 = 0;
        x_i2 = (1.0 / (1.0 / 125.0 - 1.0 / (x() + 250.0)));
        std::string str = "X_lens: " + std::to_string(x());
        label(str, -30, -220);
    }
    void stop() {}

    double const omega_m = 5;
};

class Lens : public Agent
{
public:
    Lens(json spec, World &world) : Agent(spec, world)
    {
        add_process(c);
    }

private:
    LensController c;
};

DECLARE_INTERFACE(Lens)

#endif
