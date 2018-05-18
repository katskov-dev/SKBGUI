#include "Edit/EditController.h"
#include <string>
EditController::EditController(pEditModel model): ComponentController(model)
{

}

EditController::~EditController()
{
    //dtor
}

bool EditController::Handle(sf::Event event)
{

    if (ComponentController::Handle(event))
        return true;

    if (Owner()->Focus()){
//        std::cout << "EditEvent " << event.type << std::endl;
        switch (event.type){
            case sf::Event::KeyPressed:{
                switch (event.key.code){
                    case sf::Keyboard::Right:{//перевот каретки вправо
                        int cp = pEditModel(Owner())->CaretPos();
                        if (cp <  pEditModel(Owner())->Text().getSize())
                            cp++;
                        pEditModel(Owner())->SetCaretPos(cp);
                        pEditModel(Owner())->__clock.restart();
                        return true;
                        break;
                    };
                    case sf::Keyboard::Left:{//перевод каретки влево
                        int cp = pEditModel(Owner())->CaretPos();
                        if (cp > 0)
                            cp--;
                        pEditModel(Owner())->SetCaretPos(cp);
                        pEditModel(Owner())->__clock.restart();
                        return true;
                        break;
                    };
                    case sf::Keyboard::BackSpace:{//удаление символа слева от каретки
                        int cp = pEditModel(Owner())->CaretPos();
                        if (cp > 0){

//                            std::string new_text = pEditModel(Owner())->Text();
//                            new_text.erase(cp-1, 1);
                            sf::String new_text = pEditModel(Owner())->Text();
                            new_text.erase(cp-1, 1);
                            cp--;
                            pEditModel(Owner())->SetCaretPos(cp);
                            pEditModel(Owner())->SetText(new_text);
                            pEditModel(Owner())->__clock.restart();
                        }
                        return true;
                        break;
                    };
                    case sf::Keyboard::Delete:{
                        int cp = pEditModel(Owner())->CaretPos();
                        if (cp < pEditModel(Owner())->Text().getSize()){

                            std::string new_text = pEditModel(Owner())->Text();
                            new_text.erase(cp, 1);

                            pEditModel(Owner())->SetCaretPos(cp);
                            pEditModel(Owner())->SetText(new_text);
                            pEditModel(Owner())->__clock.restart();
                        }
                        return true;
                        break;
                    };
                    case sf::Keyboard::Home:{
                        int cp = pEditModel(Owner())->CaretPos();
                        cp = 0;
                        pEditModel(Owner())->SetCaretPos(cp);
                        pEditModel(Owner())->__clock.restart();
                        return true;
                        break;
                    };
                    case sf::Keyboard::End:{
                        int cp = pEditModel(Owner())->CaretPos();
                        cp = pEditModel(Owner())->Text().getSize();
                        pEditModel(Owner())->SetCaretPos(cp);
                        pEditModel(Owner())->__clock.restart();
                        return true;
                        break;
                    };
                };
                break;
            };
            case sf::Event::TextEntered:{

                if ( (event.text.unicode > 31)){
                    int cp = pEditModel(Owner())->CaretPos();
//                    std::string new_text = pEditModel(Owner())->Text();
//                    std::string ins = "";
//                    if (event.text.unicode > 128){
//                         //sf::Uint32 tmp = event.text.unicode;
//                         //char* tmp1 = (char*)&tmp;
//                         //ins += tmp1[1];
//                         //ins += tmp1[];
//
//                    }
//                    else{
//                        char c = event.text.unicode;
//                        ins += c;
//                    }
                    sf::String new_text = pEditModel(Owner())->Text();
                    sf::String ins = L"";
                    ins += event.text.unicode;


                    //std::string ins = "1";
                    if (ins == "")
                        break;
                    new_text.insert(cp, ins);
                    cp++;
                    pEditModel(Owner())->SetCaretPos(cp);
                    pEditModel(Owner())->SetText(new_text);
                    pEditModel(Owner())->__clock.restart();
                    return true;
                }
                break;

            };
            case sf::Event::MouseButtonPressed:{
                pEditModel(Owner())->__clock.restart();
                if (Owner()->Focus()){

                    sf::Vector2f mc;
                    mc.x = event.mouseButton.x;
                    mc.y = event.mouseButton.y;

                    int caret;
                    for (int caret = 1; caret <= pEditModel(Owner())->Text().getSize(); caret++){
                        sf::Vector2f t_c;
                        int w = pEditModel(Owner())->__render_text.findCharacterPos(caret).x - pEditModel(Owner())->__render_text.findCharacterPos(caret-1).x;
                        t_c = Owner()->AbsoluteCoord();
                        t_c += pEditModel(Owner())->__render_text.getPosition();
//                        std::cout << caret << std::endl;
//                        std::cout << Owner()->AbsoluteCoord().x + pEditModel(Owner())->__render_text.findCharacterPos(caret).x << std::endl;
//                        std::cout << mc.x << std::endl;
                        if (mc.x < Owner()->AbsoluteCoord().x + pEditModel(Owner())->__render_text.findCharacterPos(caret).x + 5 - w / 2){
                            pEditModel(Owner())->SetCaretPos(caret-1);
                            pEditModel(Owner())->__clock.restart();
                            break;
                        }
                        else
                        if (mc.x < Owner()->AbsoluteCoord().x + pEditModel(Owner())->__render_text.findCharacterPos(caret).x + 5 ){
                            pEditModel(Owner())->SetCaretPos(caret);
                            pEditModel(Owner())->__clock.restart();
                            break;
                        }
                        else{
                            pEditModel(Owner())->SetCaretPos(pEditModel(Owner())->Text().getSize());
                            pEditModel(Owner())->__clock.restart();
                        }

                    };


                }
                return true;
                break;
            };
        };
    }
    return false;
}
