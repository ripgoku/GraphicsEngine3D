#pragma once
#include "GameObject.h"

class DrawableObject : public GameObject {
public:
    virtual void draw() const;
};