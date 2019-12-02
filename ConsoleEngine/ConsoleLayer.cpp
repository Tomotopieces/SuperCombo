#include "ConsoleLayer.h"
#include "ConsoleButton.h"
#include "ConsoleText.h"
using namespace console_engine;
using namespace consolr_controller;

ConsoleLayer::ConsoleLayer()
    : ConsoleObject("")
{
}

ConsoleLayer::ConsoleLayer(const ConsoleLayer& scene)
    : ConsoleObject("")
    , _objectList(scene._objectList)
{
}

ConsoleLayer::ConsoleLayer(ConsoleLayer&& scene)
    : ConsoleObject("")
    , _objectList(scene._objectList)
{
    scene.~ConsoleLayer();
}

const ConsoleLayer& ConsoleLayer::operator=(const ConsoleLayer& scene)
{
    if(this == &scene)
        return*this;
    ConsoleObject::operator=(scene);
    _objectList = scene._objectList;
    return*this;
}

ConsoleLayer* ConsoleLayer::GetClone() const
{
    ConsoleLayer* clone = new ConsoleLayer(*this);
    return clone;
}

ConsoleObject* ConsoleLayer::operator[](const int number)
{
    if(number < _objectList.size())
        return _objectList[number];
    return nullptr;
}

ConsoleLayer& ConsoleLayer::AddObject(const ConsoleObject& object)
{
    _objectList.push_back(object.GetClone());
    return*this;
}

ConsoleLayer& ConsoleLayer::AddObject(const ConsoleObject& object, const ConsolePoint2D position)
{
    ConsoleObject* clone = object.GetClone();
    clone->SetPosition(position);
    _objectList.push_back(clone);
    return*this;
}

ConsoleLayer& ConsoleLayer::AddObject(const ConsoleObject& object, const int x, const int y)
{
    ConsoleObject* clone = object.GetClone();
    clone->SetPosition(x, y);
    _objectList.push_back(clone);
    return*this;
}

const ConsoleLayer& ConsoleLayer::UpdateState()
{
    if (_objectList.size() == 0)
        return*this;
    for (ConsoleObject* object : _objectList) {
        ConsoleButton* button = dynamic_cast<ConsoleButton*>(object);
        if(button != nullptr)
            button->UpdateState();
    }
    return*this;
}

const ConsoleLayer& ConsoleLayer::Render() const
{
    if (_objectList.size() == 0)
        return*this;
    for (const ConsoleObject* object : _objectList)
        object->Render();
    return*this;
}
