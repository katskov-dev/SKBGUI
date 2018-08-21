#pragma once
#include <base.h>
#include <string>
#include <Component/ComponentModel.h>
#include <Collider/ColliderModel.h>

class BoxCollider2Model: public ColliderModel
{
    public:
        BoxCollider2Model(float x, float y,float weight, float height, pWorld World, string type);
        virtual ~BoxCollider2Model();
        void setWidth(float width);
        float setWidth();
        void setHeight(float height);
        float getHeight();
        void CreateBody();
        void setPositionAfterStep();
        void SetLocalCoord(double x,double y);
        void ApplyMomentum(float dx, float dy);
        void turn(int x_shift, int y_shift);
    protected:

    private:
    b2PolygonShape __dynamicBox;
    string __type;

};
