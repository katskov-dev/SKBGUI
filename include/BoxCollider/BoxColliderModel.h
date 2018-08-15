#pragma once
#include <base.h>
#include <string>
#include <Component/ComponentModel.h>
#include <World/World.h>


class BoxColliderModel: public ComponentModel
{
    public:
        BoxColliderModel(pWorld world, double width, double height, std::string type);
        virtual ~BoxColliderModel();
        virtual void SetLocalCoord(double x,double y);
         virtual void SetLocalCoord(Vector2f ComCoord);

        double Angle();
        void SetR(double r);
        void SetAngle(double angle);

        void SetWorld(b2World* world);
        void CreateBody();
        b2Body* Body();
        void setPositionAfterStep();
        void ApplyMomentum(float dx, float dy);
    protected:

    private:


        b2World* __world;
        b2Body* __body;
        std::string __type;

};
