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
    ComponentController::Handle(event);
    if (Owner()->Focus()){
        switch (event.type){
            case sf::Event::KeyPressed:{
                switch (event.key.code){
                    case sf::Keyboard::Right:{
                        int cp = pEditModel(Owner())->CaretPos();
                        if (cp <  pEditModel(Owner())->Text().size())
                            cp++;
                        pEditModel(Owner())->SetCaretPos(cp);
                        pEditModel(Owner())->__clock.restart();
                        return true;
                        break;
                    };
                    case sf::Keyboard::Left:{
                        int cp = pEditModel(Owner())->CaretPos();
                        if (cp > 0)
                            cp--;
                        pEditModel(Owner())->SetCaretPos(cp);
                        pEditModel(Owner())->__clock.restart();
                        return true;
                        break;
                    };
                    case sf::Keyboard::BackSpace:{
                        int cp = pEditModel(Owner())->CaretPos();
                        if (cp > 0){

                            std::string new_text = pEditModel(Owner())->Text();
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
                        if (cp < pEditModel(Owner())->Text().size()){

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
                        cp = pEditModel(Owner())->Text().size();
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
                    std::string new_text = pEditModel(Owner())->Text();
                    std::string ins = "";
                    if (event.text.unicode > 128){
                         //sf::Uint32 tmp = event.text.unicode;
                         //char* tmp1 = (char*)&tmp;
                         //ins += tmp1[1];
                         //ins += tmp1[];

                    }
                    else{
                        char c = event.text.unicode;
                        ins += c;
                    }


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
        };
    }
    return false;
}
