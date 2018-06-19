#pragma once
#include <base.h>
#include <string>
#include <Component/ComponentModel.h>
#include <Box2D/box2D.h>
#include <World/World.h>


class CircleColliderModel: public ComponentModel
{
    public:
        CircleColliderModel(pWorld world, double radius, std::string type);
        virtual ~CircleColliderModel();
        virtual void SetLocalCoord(double x,double y);
        virtual void SetLocalCoord(Vector2f ComCoord);
        //virtual void SetAbsoluteCoord(Vector2f ComCoord);
        double R();
        double Angle();
        void SetR(double r);
        void SetAngle(double angle);
        sf::Vector2f GetCenter();
        void SetWorld(b2World* world);
        void CreateBody();
        b2Body* Body();
        void setPositionAfterStep();
    protected:

    private:
        double __r;

        b2World* __world;
        b2Body* __body;
        std::string __type;

};
