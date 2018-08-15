#pragma once
#include <base.h>
#include <string>
#include <Component/ComponentModel.h>
#include <Box2D/box2D.h>
#include <World/World.h>

class JointModel: public ComponentModel
{
    public:
        JointModel(pRigidBody FBody, pRigidBody SBody, pWorld world);
        void Destroy();
        void Init(b2Vec2 AnchorOne, b2Vec2 AnchorTwo);
        virtual ~JointModel();
        pRigidBody FBody();
        pRigidBody SBody();
        pWorld World();
    protected:

    private:
    pRigidBody __FBody,__SBody;
    pWorld __World;


};
