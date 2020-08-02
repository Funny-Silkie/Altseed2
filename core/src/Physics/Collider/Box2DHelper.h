#pragma once

#include <box2d/box2d.h>

#include "../../Math/Matrix44F.h"
#include "../../Math/Vector2F.h"
#include "../../Math/Vector3F.h"

namespace Altseed2 {

class Box2DHelper{
public:
    /**
    @brief �ό`�s���Altseed2->Box2D�ɕϊ�
    @param transform �ϊ�������Altseed2�̕ό`�s��
    @return Box2D�̕ό`�s��
    */
    static b2Transform ToBox2D_Mat(const Matrix44F& transform);
    /**

    @brief �ό`�s���Box2D->Altseed2�ɕϊ�
    @param transform �ϊ�������Box2D�̕ό`�s��
    @return Altseed2�̕ό`�s��
    */
    static Matrix44F ToAsd_Mat(const b2Transform& transform);

    /**
    @brief 2�����x�N�g����Altseed2->Box2D�ɕϊ�
    @param vector �ϊ�������Altseed2��2�����x�N�g��
    @return Box2D��2�����x�N�g��
    */
    static b2Vec2 ToBox2D_Vec(const Vector2F& vector);

    /**
    @brief 3�����x�N�g����Altseed2->Box2D�ɕϊ�
    @param vector �ϊ�������Altseed2��3�����x�N�g��
    @return Box2D��3�����x�N�g��
    */
    static b2Vec3 ToBox2D_Vec(const Vector3F& vector);

    /**
    @brief 2�����x�N�g����Box2D->Altseed2�ɕϊ�
    @param vector �ϊ�������Altseed2��2�����x�N�g��
    @return Box2D��2�����x�N�g��
    */
    static Vector2F ToAsd_Vec(const b2Vec2& vector);

    /**
    @brief 3�����x�N�g����Box2D->Altseed2�ɕϊ�
    @param vector �ϊ�������Altseed3��2�����x�N�g��
    @return Box2D��3�����x�N�g��
    */
    static Vector3F ToAsd_Vec(const b2Vec3& vector);

    /**
    @brief 3��]�s���Altseed2->Box2D�ɕϊ�
    @param rotation �ϊ�������Altseed2�̉�]�s��
    @return Box2D�̉�]��\���I�u�W�F�N�g
    */
    static b2Rot ToBox2D_Rot(const Matrix44F& rotation);

    /**
    @brief 3��]�s���Box2D->Altseed2�ɕϊ�
    @param rotation �ϊ�������Box2D�̉�]��\���I�u�W�F�N�g
    @return Altseed2�̉�]�s��
    */
    static Matrix44F ToAsd_Rot(const b2Rot& rotation);
};

}  // namespace Altseed2

