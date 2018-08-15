#pragma once
//--------------------COMPONENT-----------------------------
class Component;
typedef Component* pComponent;

class ComponentModel;
typedef ComponentModel* pComponentModel;

class ComponentViewer;
typedef ComponentViewer* pComponentViewer;

class ComponentController;
typedef ComponentController* pComponentController;

//--------------------BUTTON-----------------------------
class Button;
typedef Button* pButton;

class ButtonModel;
typedef ButtonModel* pButtonModel;

class ButtonViewer;
typedef ButtonViewer* pButtonViewer;

class ButtonController;
typedef ButtonController* pButtonController;

//--------------------TRANSFORMER-----------------------------
class Transformer;
typedef Transformer* pTransformer;

class TransformerModel;
typedef TransformerModel* pTransformerModel;

class TransformerViewer;
typedef TransformerViewer* pTransformerViewer;

class TransformerController;
typedef TransformerController* pTransformerController;

//--------------------LABEL-----------------------------
class Label;
typedef Label* pLabel;

class LabelModel;
typedef LabelModel* pLabelModel;

class LabelViewer;
typedef LabelViewer* pLabelViewer;

class LabelController;
typedef LabelController* pLabelController;

//--------------------EDIT-----------------------------
class Edit;
typedef Edit* pEdit;

class EditModel;
typedef EditModel* pEditModel;

class EditViewer;
typedef EditViewer* pEditViewer;

class EditController;
typedef EditController* pEditController;

//--------------------CircleCollider-----------------------------
class CircleCollider;
typedef CircleCollider* pCircleCollider;

class CircleColliderModel;
typedef CircleColliderModel* pCircleColliderModel;

class CircleColliderViewer;
typedef CircleColliderViewer* pCircleColliderViewer;

class CircleColliderController;
typedef CircleColliderController* pCircleColliderController;


/////////////////////////////BOX COLLIDER
class BoxCollider;
typedef BoxCollider* pBoxCollider;

class BoxColliderModel;
typedef BoxColliderModel* pBoxColliderModel;

class BoxColliderViewer;
typedef BoxColliderViewer* pBoxColliderViewer;

class BoxColliderController;
typedef BoxColliderController* pBoxColliderController;

///////////////////////////////////////////////
class Picture;
typedef Picture* pPicture;

class PictureModel;
typedef PictureModel* pPictureModel;

class PictureViewer;
typedef PictureViewer* pPictureViewer;

class PictureController;
typedef PictureController* pPictureController;

/////////////////////////GUI
class GUI;
typedef GUI* pGUI;

class GUIModel;
typedef GUIModel* pGUIModel;

class GUIViewer;
typedef GUIViewer* pGUIViewer;

class GUIController;
typedef GUIController* pGUIController;

////////////////////////////////////
class Panel;
typedef Panel* pPanel;

class PanelModel;
typedef PanelModel* pPanelModel;

class PanelViewer;
typedef PanelViewer* pPanelViewer;

class PanelController;
typedef PanelController* pPanelController;

/////////////////////////////////////////////
class Timer;
typedef Timer* pTimer;

class TimerModel;
typedef TimerModel* pTimerModel;

class TimerViewer;
typedef TimerViewer* pTimerViewer;

class TimerController;
typedef TimerController* pTimerController;

////////////////////////////////////////////
class Table;
typedef Table* pTable;

class TableModel;
typedef TableModel* pTableModel;

class TableViewer;
typedef TableViewer* pTableViewer;

class TableController;
typedef TableController* pTableController;

class World;
typedef World* pWorld;

class WorldModel;
typedef WorldModel* pWorldModel;

class WorldViewer;
typedef WorldViewer* pWorldViewer;

class WorldController;
typedef WorldController* pWorldController;

class Scene;
typedef Scene* pScene;

class SceneModel;
typedef SceneModel* pSceneModel;

class SceneViewer;
typedef SceneViewer* pSceneViewer;

class SceneController;
typedef SceneController* pSceneController;

class Neuron;
typedef Neuron* pNeuron;

class NeuronModel;
typedef NeuronModel* pNeuronModel;

class NeuronViewer;
typedef NeuronViewer* pNeuronViewer;

class NeuronController;
typedef NeuronController* pNeuronController;

//Arrow

class Arrow;
typedef Arrow* pArrow;

class ArrowModel;
typedef ArrowModel* pArrowModel;

class ArrowViewer;
typedef ArrowViewer* pArrowViewer;

class ArrowController;
typedef ArrowController* pArrowController;


//--------------------> CheckBox <--------------------

class CheckBox;
typedef CheckBox* pCheckBox;

class CheckBoxModel;
typedef CheckBoxModel* pCheckBoxModel;

class CheckBoxViewer;
typedef CheckBoxViewer* pCheckBoxViewer;

class CheckBoxController;
typedef CheckBoxController* pCheckBoxController;

//--------------------> ProgressBar <--------------------

class ProgressBar;
typedef ProgressBar* pProgressBar;

class ProgressBarModel;
typedef ProgressBarModel* pProgressBarModel;

class ProgressBarViewer;
typedef ProgressBarViewer* pProgressBarViewer;

class ProgressBarController;
typedef ProgressBarController* pProgressBarController;

//--------------------> Animation <--------------------

class Animation;
typedef Animation* pAnimation;

class AnimationModel;
typedef AnimationModel* pAnimationModel;

class AnimationViewer;
typedef AnimationViewer* pAnimationViewer;

class AnimationController;
typedef AnimationController* pAnimationController;

//--------------------> Sensor <--------------------
class sensor;
typedef sensor* psensor;

class sensorModel;
typedef sensorModel* psensorModel;

class sensorViewer;
typedef sensorViewer* psensorViewer;

class sensorController;
typedef sensorController* psensorController;


//--------------------TRANSFORMERRXY-----------------------------
class TransformerRXY;
typedef TransformerRXY* pTransformerRXY;

class TransformerRXYModel;
typedef TransformerRXYModel* pTransformerRXYModel;

class TransformerRXYViewer;
typedef TransformerRXYViewer* pTransformerRXYViewer;

class TransformerRXYController;
typedef TransformerRXYController* pTransformerRXYController;

//--------------------> Joint <--------------------

class Joint;
typedef Joint* pJoint;

class JointModel;
typedef JointModel* pJointModel;

class JointViewer;
typedef JointViewer* pJointViewer;

class JointController;
typedef JointController* pJointController;

//--------------------> RigidBody <--------------------

class RigidBody;
typedef RigidBody* pRigidBody;

class RigidBodyModel;
typedef RigidBodyModel* pRigidBodyModel;

class RigidBodyViewer;
typedef RigidBodyViewer* pRigidBodyViewer;

class RigidBodyController;
typedef RigidBodyController* pRigidBodyController;
//--------------------> DistanceJoint <--------------------
class DistanceJoint;
typedef DistanceJoint* pDistanceJoint;

class DistanceJointModel;
typedef DistanceJointModel* pDistanceJointModel;

class DistanceJointViewer;
typedef DistanceJointViewer* pDistanceJointViewer;

class DistanceJointController;
typedef DistanceJointController* pDistanceJointController;
//--------------------> RevoluteJoint <--------------------
class RevoluteJoint;
typedef RevoluteJoint* pRevoluteJoint;

class RevoluteJointModel;
typedef RevoluteJointModel* pRevoluteJointModel;

class RevoluteJointViewer;
typedef RevoluteJointViewer* pRevoluteJointViewer;

class RevoluteJointController;
typedef RevoluteJointController* pRevoluteJointController;
//--------------------> Collider <--------------------

class Collider;
typedef Collider* pCollider;

class ColliderModel;
typedef ColliderModel* pColliderModel;

class ColliderViewer;
typedef ColliderViewer* pColliderViewer;

class ColliderController;
typedef ColliderController* pColliderController;

//--------------------> BoxCollider2 <--------------------

class BoxCollider2;
typedef BoxCollider2* pBoxCollider2;

class BoxCollider2Model;
typedef BoxCollider2Model* pBoxCollider2Model;

class BoxCollider2Viewer;
typedef BoxCollider2Viewer* pBoxCollider2Viewer;

class BoxCollider2Controller;
typedef BoxCollider2Controller* pBoxCollider2Controller;
//--------------------> DistanceJoint <--------------------

class DistanceJoint;
typedef DistanceJoint* pDistanceJoint;

class DistanceJointModel;
typedef DistanceJointModel* pDistanceJointModel;

class DistanceJointViewer;
typedef DistanceJointViewer* pDistanceJointViewer;

class DistanceJointController;
typedef DistanceJointController* pDistanceJointController;
