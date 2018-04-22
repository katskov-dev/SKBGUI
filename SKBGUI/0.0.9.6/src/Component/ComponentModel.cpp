#include <Component/ComponentModel.h>

ComponentModel::ComponentModel()
{
    __focus = false;
    __visibleBorders = false;
    __parent = nullptr;
    SetEnabled(true);
    __class = "Component";
}

string ComponentModel::Name()
     {

         return name;
     }

     void ComponentModel::SetName(string StName)
     {
         name=StName;
     }

     Vector2f ComponentModel::LocalCoord()//получаем координаты верхнего левого угла
     {
         return __localCoord;
     }


     void ComponentModel::SetLocalCoord(double x,double y)//выбираем координаты верхнего левого угла через 2 переменные
      {
         __localCoord.x=x;
         __localCoord.y=y;
      }

      Vector2f ComponentModel::Size()//получаем размеры
     {
         return __size;
     }


     void ComponentModel::SetSize(double x,double y)//задаем размеры через 2 переменные
      {
         __size.x=x;
         __size.y=y;
      }

      void ComponentModel::SetSize(Vector2f ComSize)//задаем размеры через 2 переменные
      {
         __size.x=ComSize.x;
         __size.y=ComSize.y;
      }

    void ComponentModel::SetLocalCoord(Vector2f ComCoord)
    {
       __localCoord.x=ComCoord.x;
       __localCoord.y=ComCoord.y;
    }



     void ComponentModel::SetState(int state)
     {
         __state = state;
     }

    int ComponentModel::State()
    {
        return __state;
    }




     void ComponentModel::SetFocus(bool focus)
     {
         __focus = focus;
     }

     bool ComponentModel::Focus()
     {
         return __focus;
     }

     void ComponentModel::SetParent(pComponentModel parent)
     {
         __parent=parent;
     }

     pComponentModel ComponentModel::Parent()
     {
         return __parent;
     }


     void ComponentModel::Add(pComponent child)
      {
         __children.push_back(child);
         child->Model()->SetParent(this);
      }

     std::string ComponentModel::Info()
      {
         std::string info;

      }

     pComponent ComponentModel::Find(string StName)
      {
          pComponent FindingComp=nullptr;
           for(int i=0;i<__children.size();i++)
           {
             if (__children[i]->Model()->Name()==StName){
                //std::cout << __children[i]->Model()->Name() << std::endl;
                FindingComp = __children[i];
                break;
             }
           }
            return FindingComp;

      }

      pComponent ComponentModel::FindAll(std::string name)
      {
          pComponent found = nullptr;
          for (int i = 0; i < Count(); i++){
              if (Children(i)->Model()->Name() == name){
                  found = Children(i);
              break;
              }

          }
          if (found == nullptr){
              for (int i = 0; i < Count(); i++){
                pComponent temp = Children(i)->Model()->FindAll(name);
                if (temp != nullptr){
                    found = temp;
                    break;
                }
              }
          }

          return found;

      }


     void ComponentModel::Delete(pComponent children)
       {
          for(int i=0;i<__children.size();i++)
           {
             if ((__children[i])== children)
               {
                delete __children[i];
                __children.erase(__children.begin()+i);

               }
           }
       }

       pComponent ComponentModel::Children(int index)
       {
            if ((index >= 0) && (index < __children.size())){
                return __children[index];
            }
            else
                return nullptr;
       }

       void ComponentModel::SetChildren(int index, pComponent component)
       {
            if ((index >= 0) && (index < __children.size())){
                __children[index] = component;
            }

       }

       int ComponentModel::Count()
       {
            return __children.size();
       }

        ComponentModel::~ComponentModel()
        {
           for(int i=0;i<__children.size();i++)
            delete __children[i];
            __children.clear();
        }

       void ComponentModel::Delete(string ChName)
       {

           Delete(Find(ChName));

       }


    bool ComponentModel::VisibleBorders()
    {
        return __visibleBorders;
    }

     void ComponentModel::SetVisibleBorders(bool visibleBorders)
     {
        __visibleBorders = visibleBorders;
     }

     Vector2f ComponentModel::AbsoluteCoord()
     {
        Vector2f result;
           pComponentModel a;
           a=this;
           while (a!=nullptr)
           {

               result=result+a->LocalCoord();
               a=a->__parent;

           }
             //result+=a->LocalCoord();
           return result;
     }

     void ComponentModel::SetAbsoluteCoord(Vector2f Abs)
     {
        if (__parent!=nullptr)
           __localCoord = Abs-__parent->AbsoluteCoord();
           else
            __localCoord = Abs;
     }

     void ComponentModel::SetEnabled(bool enabled)
     {
        __enabled = enabled;
     }

     bool ComponentModel::Enabled()
     {
        return __enabled;
     }

     std::string ComponentModel::SerializeToString()
     {
         std::string result = "";
         std::string parent_name = Parent()->Name();

         result += "component_create('"+Name()+"', '"+parent_name+"')\n";
         result += "component_model_setlocalcoord('"+Name()+"', "+std::to_string(LocalCoord().x)+", "+std::to_string(LocalCoord().y) + ")\n";
         result += "component_model_setsize('"+Name()+"', "+std::to_string(Size().x)+", "+std::to_string(Size().y) + ")\n";


         return result;

     }

     void ComponentModel::DeserializeFromString(std::string s)
     {
          std::string property;
          std::string value;
          int st;
          while (s.size() > 0){
             property = "";
             value = "";
             st = 0;
             while (s[0] != ';'){

                if ((s[0] == '=') && (st == 0)){
                    st = 1;
                    s.erase(s.begin());
                    continue;
                }
                if (st == 0){
                    property += s[0];
                    s.erase(s.begin());
                }
                else
                if (st == 1){
                    value += s[0];
                    s.erase(s.begin());
                }

             }
             s.erase(s.begin());
             s.erase(s.begin());
             std::cout << "Property=Value: '" << property <<"'='" << value <<"'" <<std::endl;
             if (property == "name"){
                SetName(value);
             }
             else
             if (property == "localcoord_x"){
                 sf::Vector2f v= LocalCoord();
                 v.x = std::stod(value);
                 SetLocalCoord(v);
             }
             else
             if (property == "localcoord_y"){
                 sf::Vector2f v= LocalCoord();
                 v.y = std::stod(value);
                 SetLocalCoord(v);

             }
             else
             if (property == "size_x"){
                 sf::Vector2f v= Size();
                 v.x = std::stod(value);
                 SetSize(v);

             }
             else
             if (property == "size_y"){
                 sf::Vector2f v= Size();
                 v.y = std::stod(value);
                 SetSize(v);
             }
             else
             if (property == "enabled"){
                 bool enabled = bool(std::stoi(value));
                 SetEnabled(enabled);
             }
             else
             if (property == "focus"){
                 bool focus = bool(std::stoi(value));
                 SetFocus(focus);
             }
             else
             if (property == "state"){
                 bool state = std::stoi(value);
                 SetState(state);
             }

             //std::cout << s << std::endl;

          }
     }

     std::string ComponentModel::Class()
     {
        return __class;
     }

     void ComponentModel::SetClass(std::string _class)
     {
            __class = _class;
     }
