#include "Transformer/TransformerController.h"

TransformerController::TransformerController(pTransformerModel model): ComponentController(model)
{
    //ctor
}

TransformerController::~TransformerController()
{
    //dtor
}

bool TransformerController::Handle(sf::Event event)
{
    ComponentController::Handle(event);
    if (pTransformerModel(Owner())->Target() != nullptr){
        switch (event.type){
            //Обработка нажатия кнопки мыши
            case sf::Event::MouseButtonPressed:{
                int x = event.mouseButton.x;
                int y = event.mouseButton.y;
                for (int i = 0; i < 9; i++){
                    double r = pTransformerModel(Owner())->Radius();
                    sf::Vector2f p = pTransformerModel(Owner())->__points[i];
                    double distance = sqrt((pow(x - p.x, 2) + pow(y - p.y, 2)));
                    if (distance <= r){
                        Owner()->SetState(TRANSFORMER_STATE_DOWN);
                        pTransformerModel(Owner())->activePoint = i;
                        __oldMouseCoord = sf::Vector2f(x, y);
                        return true;
                    }

                }

                break;
            }
            case sf::Event::MouseMoved:{
                if (pTransformerModel(Owner())->State() == TRANSFORMER_STATE_DOWN){
                    sf::Vector2f oldCoord =  pTransformerModel(Owner())->Target()->Model()->LocalCoord();
                    sf::Vector2f oldSize =  pTransformerModel(Owner())->Target()->Model()->Size();
                    sf::Vector2f offset = sf::Vector2f(event.mouseMove.x, event.mouseMove.y) - __oldMouseCoord;
                    sf::Vector2f newCoord;
                     sf::Vector2f newSize;
                    if (pTransformerModel(Owner())->activePoint == 0){
                        newCoord = pTransformerModel(Owner())->Target()->Model()->LocalCoord() + offset;
                        newSize = pTransformerModel(Owner())->Target()->Model()->Size() - offset;
                    }
                    else
                    if (pTransformerModel(Owner())->activePoint == 1){
                        offset.x = 0;
                        newCoord = pTransformerModel(Owner())->Target()->Model()->LocalCoord() + offset;
                        newSize = pTransformerModel(Owner())->Target()->Model()->Size() - offset;
                    }
                    else
                    if (pTransformerModel(Owner())->activePoint == 2){
                        sf::Vector2f coord = sf::Vector2f(0, offset.y);
                        sf::Vector2f size = sf::Vector2f(offset.x, -offset.y);
                        newCoord = pTransformerModel(Owner())->Target()->Model()->LocalCoord() + coord;
                        newSize = pTransformerModel(Owner())->Target()->Model()->Size() + size;
                    }
                    else
                    if (pTransformerModel(Owner())->activePoint == 3){
                        sf::Vector2f coord = sf::Vector2f(0, 0);
                        sf::Vector2f size = sf::Vector2f(offset.x, 0);
                        newCoord = pTransformerModel(Owner())->Target()->Model()->LocalCoord() + coord;
                        newSize = pTransformerModel(Owner())->Target()->Model()->Size() + size;
                    }
                    else
                    if (pTransformerModel(Owner())->activePoint == 4){
                        sf::Vector2f coord = sf::Vector2f(0, 0);
                        sf::Vector2f size = sf::Vector2f(offset.x, offset.y);
                        newCoord = pTransformerModel(Owner())->Target()->Model()->LocalCoord() + coord;
                        newSize = pTransformerModel(Owner())->Target()->Model()->Size() + size;
                    }
                    else
                    if (pTransformerModel(Owner())->activePoint == 5){
                        sf::Vector2f coord = sf::Vector2f(0, 0);
                        sf::Vector2f size = sf::Vector2f(0, offset.y);
                        newCoord = pTransformerModel(Owner())->Target()->Model()->LocalCoord() + coord;
                        newSize = pTransformerModel(Owner())->Target()->Model()->Size() + size;
                    }
                    else
                    if (pTransformerModel(Owner())->activePoint == 6){
                        sf::Vector2f coord = sf::Vector2f(offset.x, offset.y);
                        sf::Vector2f size = sf::Vector2f(-offset.x, -offset.y);
                        newCoord = pTransformerModel(Owner())->Target()->Model()->LocalCoord() + coord;
                        newSize = pTransformerModel(Owner())->Target()->Model()->Size() + size;
                    }
                    else
                    if (pTransformerModel(Owner())->activePoint == 7){
                        sf::Vector2f coord = sf::Vector2f(offset.x, 0);
                        sf::Vector2f size = sf::Vector2f(-offset.x, 0);
                        newCoord = pTransformerModel(Owner())->Target()->Model()->LocalCoord() + coord;
                        newSize = pTransformerModel(Owner())->Target()->Model()->Size() + size;
                    }
                    else
                    if (pTransformerModel(Owner())->activePoint == 8){
                        sf::Vector2f coord = sf::Vector2f(offset.x, offset.y);
                        sf::Vector2f size = sf::Vector2f(0, 0);
                        newCoord = oldCoord + offset;
//                        std::cout << "Oldcoord.x " << oldCoord.x << ", Oldcoord.y " << oldCoord.y << std::endl;
//                        std::cout << "offset.x " << offset.x << ", offset.y " << offset.y << std::endl;
//                        std::cout << "newcoord.x " << newCoord.x << ", newCoord.y " << newCoord.y << std::endl;
//                        std::cout << "Count: " << pTransformerModel(Owner())->Target()->Model()->Count() << std::endl;

                        newSize = pTransformerModel(Owner())->Target()->Model()->Size() + size;

                    }

                    pTransformerModel(Owner())->Target()->Model()->SetLocalCoord(newCoord);
                    pTransformerModel(Owner())->Target()->Model()->SetSize(newSize);
                    __oldMouseCoord = __oldMouseCoord + offset;

                    double r = pTransformerModel(Owner())->Radius();
                    if (pTransformerModel(Owner())->Target()->Model()->Size().x < r * 5){
                        pTransformerModel(Owner())->Target()->Model()->SetLocalCoord(oldCoord);
                        pTransformerModel(Owner())->Target()->Model()->SetSize(oldSize);
                    }
                    if (pTransformerModel(Owner())->Target()->Model()->Size().y < r * 5){
                        pTransformerModel(Owner())->Target()->Model()->SetLocalCoord(oldCoord);
                        pTransformerModel(Owner())->Target()->Model()->SetSize(oldSize);
                    }
                    return true;

                }
                break;
            }

            case sf::Event::MouseButtonReleased:{
                //Обработка отпускания кнопки мыши
    //            int x = event.mouseButton.x;
    //            int y = event.mouseButton.y;
    //            sf::Vector2f pos = Owner()->Coord();
    //            sf::Vector2f size = Owner()->Size();
    //            if ((x >= pos.x) && (x <= pos.x + size.x) && (y >= pos.y) && (y <= pos.y + size.y)){
    //                if ((onClick() != nullptr ) && (Owner()->State() != BUTTON_STATE_NORMAL))
    //                    onClick()();
    //            }
                Owner()->SetState(TRANSFORMER_STATE_NORMAL);
                pTransformerModel(Owner())->activePoint = -1;
                break;
            }
        }
    }

    return false;
}
