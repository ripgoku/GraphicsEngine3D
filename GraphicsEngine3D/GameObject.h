#pragma once
class GameObject
{
public:
    virtual ~GameObject() {}

    virtual void update() = 0;
    virtual void render() const = 0;
};