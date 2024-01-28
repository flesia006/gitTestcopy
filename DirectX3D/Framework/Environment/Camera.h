#pragma once
class Sphere;
struct Ray;
class Camera : public Transform
{
public:
    Camera();
    ~Camera();

    void Update();
    void GUIRender();

    void SetView();

    void SetTarget(Transform* target) { this->target = target; }    
    Transform* GetTarget() { return target; }

    Vector3 ScreenToWorld(Vector3 screenPos);
    Vector3 WorldToScreen(Vector3 worldPos);

    Ray ScreenPointToRay(Vector3 screenPoint);

    void LookAtTarget();

    void TargetOptionSave(string file);
    void TargetOptionLoad(string file);

    bool ContainPoint(Vector3 point);

private:
    void FreeMode();
    void FollowMode();    

    void ThirdPersonMode();
    void ThirdPresonViewMode();


    void Frustum();

private:
    ViewBuffer* viewBuffer;
    Matrix view;
    Matrix projection;

    Vector3 planes[6];
    float a, b, c, d;

    float moveSpeed = 50.0f;
    float rotSpeed = 10.0f;

    Vector3 prevMousePos;
    Vector3 prevPos;

    Transform* target = nullptr;    

    float distance = 300.0f;
    float height = 100.0f;
    float moveDamping = 5.0f;
    float rotDamping = 1.0f;

    float rotY = 0;

    float destRot = 0.0f;
    Vector3 destPos;
    Vector3 focusOffset;

    bool isLookAtTargetX = true;
    bool isLookAtTargetY = true;

    Matrix rotMatrix;

    char file[128] = {};

    SphereCollider* camSphere = nullptr;
    BoxCollider* ground = nullptr;
    Ray sight;
    Transform* sightRot;
};