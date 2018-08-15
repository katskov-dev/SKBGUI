#pragma once
#include <base.h>
#include <Component/ComponentViewer.h>
#include <BoxCollider2/BoxCollider2Model.h>
#include <SFML/Graphics.hpp>
#include <Collider/ColliderViewer.h>
class BoxCollider2Viewer: public ColliderViewer
{
    public:
        BoxCollider2Viewer(pBoxCollider2Model model);
        virtual ~BoxCollider2Viewer();
        virtual void Render(sf::RenderTarget& target);
		virtual pBoxCollider2Model Owner();
        virtual void SetOwner(pBoxCollider2Model owner);
    protected:

    private:


};
