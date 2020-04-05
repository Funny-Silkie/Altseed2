#pragma once

#include <memory>
#include <vector>
#include <box2d/box2d.h>

#include "../../BaseObject.h"
#include "../../Math/Matrix44F.h"
#include "../../Math/Vector2F.h"

namespace Altseed {

class Collider : public BaseObject {
protected:
    b2Transform transform_;
    Matrix44F transformMatrix_;

    Vector2F position_;
    double rotation_;

public:
    Collider();

    virtual bool GetIsCollided(std::shared_ptr<Collider> shape);

    // 位置
    Vector2F GetPosition() const;
    void SetPosition(Vector2F position);

    // 回転
    double GetRotation() const;
    void SetRotation(double rotation);

    Matrix44F GetTransform();
};
    
} // namespace Altseed
