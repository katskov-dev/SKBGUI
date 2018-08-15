#pragma once

#include <base.h>
#include <Component/Component.h>
#include <BoxCollider2/BoxCollider2Model.h>
#include <BoxCollider2/BoxCollider2Viewer.h>
#include <BoxCollider2/BoxCollider2Controller.h>
#include <Collider/Collider.h>
class BoxCollider2: public Collider
{
    public:
        BoxCollider2(float x, float y,float weight, float height, pWorld World, string type);
        ~BoxCollider2();
        virtual pBoxCollider2Model Model();
        virtual void SetModel(pBoxCollider2Model model);
        virtual pBoxCollider2Viewer Viewer();
        virtual void SetViewer(pBoxCollider2Viewer viewer);
        virtual pBoxCollider2Controller Controller();
        virtual void SetController(pBoxCollider2Controller controller);
    private:

};
