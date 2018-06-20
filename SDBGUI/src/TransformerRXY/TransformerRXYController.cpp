#include "TransformerRXY/TransformerRXYController.h"

TransformerRXYController::TransformerRXYController(pTransformerRXYModel model): ComponentController(model)
{
    //ctor
}

TransformerRXYController::~TransformerRXYController()
{
    //dtor
}

bool TransformerRXYController::Handle(sf::Event event)
{
    if (ComponentController::Handle(event))
        return true;
    if (pTransformerRXYModel(Owner())->Target() != nullptr)
    {
        switch (event.type)
        {
        //Обработка нажатия кнопки мыши

        case sf::Event::MouseButtonPressed:
        {
            //
            //pTransformerRXY(Owner())->Targ
            //Owner()->Target()->Model()->SetLocalCoord(Sensor2->Model()->LocalCoord()+sf::Vector2f(5,5));
            //

            pTransformerRXYModel(Owner())->MouseCoord.x=event.mouseButton.x;
            pTransformerRXYModel(Owner())->MouseCoord.y=event.mouseButton.y;
            if ((pTransformerRXYModel(Owner())->MouseCoord.x >= pTransformerRXYModel(Owner())->arrow_x->Model()->AbsoluteCoord().x)&&
                    (pTransformerRXYModel(Owner())->MouseCoord.y >= pTransformerRXYModel(Owner())->arrow_x->Model()->AbsoluteCoord().y)&&
                    (pTransformerRXYModel(Owner())->MouseCoord.x) <= (pTransformerRXYModel(Owner())->arrow_x->Model()->AbsoluteCoord().x+pTransformerRXYModel(Owner())->arrow_x->Model()->Size().x)&&
                    (pTransformerRXYModel(Owner())->MouseCoord.y) <= (pTransformerRXYModel(Owner())->arrow_x->Model()->AbsoluteCoord().y+pTransformerRXYModel(Owner())->arrow_x->Model()->Size().y))
            {

                pTransformerRXYModel(Owner())->flagOffsetX = true;
                pTransformerRXYModel(Owner())->OffsetPoint = pTransformerRXYModel(Owner())->MouseCoord - pTransformerRXYModel(Owner())->AbsoluteCoord();
            }

            if ((pTransformerRXYModel(Owner())->MouseCoord.x >= pTransformerRXYModel(Owner())->arrow_y->Model()->AbsoluteCoord().x)&&
                    (pTransformerRXYModel(Owner())->MouseCoord.y >= pTransformerRXYModel(Owner())->arrow_y->Model()->AbsoluteCoord().y)&&
                    (pTransformerRXYModel(Owner())->MouseCoord.x) <= (pTransformerRXYModel(Owner())->arrow_y->Model()->AbsoluteCoord().x+pTransformerRXYModel(Owner())->arrow_y->Model()->Size().x)&&
                    (pTransformerRXYModel(Owner())->MouseCoord.y) <= (pTransformerRXYModel(Owner())->arrow_y->Model()->AbsoluteCoord().y+pTransformerRXYModel(Owner())->arrow_y->Model()->Size().y))
            {

                pTransformerRXYModel(Owner())->flagOffsetY = true;
                pTransformerRXYModel(Owner())->OffsetPoint = pTransformerRXYModel(Owner())->MouseCoord - pTransformerRXYModel(Owner())->AbsoluteCoord();
            }

            return true;
            break;
        }
        case sf::Event::MouseMoved:
        {

            pTransformerRXYModel(Owner())->MouseCoord.x=event.mouseMove.x;
            pTransformerRXYModel(Owner())->MouseCoord.y=event.mouseMove.y;

            if (pTransformerRXYModel(Owner())->flagOffsetX)
            {
                sf::Vector2f offsX = pTransformerRXYModel(Owner())->AbsoluteCoord();
                offsX.x = pTransformerRXYModel(Owner())->MouseCoord.x - pTransformerRXYModel(Owner())->OffsetPoint.x;
                pTransformerRXYModel(Owner())->Target()->Model()->SetLocalCoord(offsX);
                pTransformerRXYModel(Owner())->SetLocalCoord(offsX);

            }

            if (pTransformerRXYModel(Owner())->flagOffsetY)
            {
                sf::Vector2f offsY = pTransformerRXYModel(Owner())->AbsoluteCoord();
                offsY.y = pTransformerRXYModel(Owner())->MouseCoord.y - pTransformerRXYModel(Owner())->OffsetPoint.y;
                pTransformerRXYModel(Owner())->Target()->Model()->SetLocalCoord(offsY);
                pTransformerRXYModel(Owner())->SetLocalCoord(offsY);

            }


            return true;
            break;
        }

        case sf::Event::MouseButtonReleased:
        {
            pTransformerRXYModel(Owner())->flagOffsetX = false;
            pTransformerRXYModel(Owner())->flagOffsetY = false;
//            pTransformerRXYModel(Owner())->flagRotate = false;
            return true;
            break;
        }
        }
    }

    return false;
}
