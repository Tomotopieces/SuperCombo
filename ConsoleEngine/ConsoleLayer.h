#pragma once
#include "ConsoleObject.h"
#include <vector>

namespace console_engine
{
    class ConsoleLayer
        : private ConsoleObject
    {
    private:
        std::vector<ConsoleObject*> _objectList;
    public:
        //  constructor
        ConsoleLayer();
        ConsoleLayer(const ConsoleLayer& scene);
        ConsoleLayer(ConsoleLayer&& scene);
        const ConsoleLayer& operator=(const ConsoleLayer& scene);

        //  get
        virtual ConsoleLayer* GetClone()const override;
        //  modifiable get element
        ConsoleObject* operator[](const int number);

        //  add
        ConsoleLayer& AddObject(const ConsoleObject& object);
        ConsoleLayer& AddObject(
            const ConsoleObject& object,
            const ConsolePoint2D position
        );
        ConsoleLayer& AddObject(const ConsoleObject& object,
            const int x,
            const int y
        );

        //  others
        const ConsoleLayer& UpdateState();
        const ConsoleLayer& Render()const override;
    };
}