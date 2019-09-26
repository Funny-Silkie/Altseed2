#pragma once

#include "MathTemplate.h"
#include "Vector2DI.h"

namespace altseed {

/**
        @brief	2�����x�N�g��
        */
struct Vector2DF {
public:
    /**
            @brief	X����
            */
    float X;

    /**
            @brief	Y����
            */
    float Y;

    /**
            @brief	�R���X�g���N�^
            */
    Vector2DF();

    /**
            @brief	�R���X�g���N�^
            @param	x	X����
            @param	y	Y����
    */
    Vector2DF(float x, float y);

    /**
            @brief	���̃x�N�g���̒������擾����B
    */
    float GetLength() const { return sqrt(GetSquaredLength()); }

    /**
    @brief	���̃x�N�g���̒����̓����擾����B
    */
    float GetSquaredLength() const { return X * X + Y * Y; }

    /**
            @brief	���̃x�N�g���̒�����ݒ肷��B
    */
    void SetLength(float value) {
        float length = GetLength();
        (*this) *= (value / length);
    }

    /**
    @brief	���̃x�N�g���̒P�ʃx�N�g�����擾����B
    */
    Vector2DF GetNormal() {
        float length = GetLength();
        return Vector2DF(X / length, Y / length);
    }

    /**
    @brief	���̃x�N�g���̒P�ʃx�N�g��������B
    */
    void Normalize() {
        float length = GetLength();
        (*this) /= length;
    }

    /**
            @brief	���̃x�N�g���̌������ʓx�@�Ŏ擾����B
    */
    float GetRadian() const { return atan2(Y, X); }

    /**
            @brief	���̃x�N�g���̌������ʓx�@�Őݒ肷��B
            @note �傫�����ێ������܂܁A������ύX����B
    */
    void SetRadian(float value) {
        float length = GetLength();
        SinCos(value, Y, X);
        X *= length;
        Y *= length;
    }

    /**
            @brief	���̃x�N�g���̌�����x���@�Ŏ擾����B
    */
    float GetDegree() const { return RadianToDegree(atan2(Y, X)); }

    /**
            @brief	���̃x�N�g���̌�����x���@�Őݒ肷��B
    */
    void SetDegree(float value) {
        float length = GetLength();
        SinCos(DegreeToRadian(value), Y, X);
        X *= length;
        Y *= length;
    }

    bool operator==(const Vector2DF& right);

    bool operator!=(const Vector2DF& right);

    bool operator>(const Vector2DF& o) const;
    bool operator<(const Vector2DF& o) const;

    Vector2DF operator-();

    Vector2DF operator+(const Vector2DF& right) const;

    Vector2DF operator-(const Vector2DF& right) const;

    Vector2DF operator*(const Vector2DF& right) const;

    Vector2DF operator/(const Vector2DF& right) const;

    Vector2DF operator*(float right) const;

    Vector2DF operator/(float right) const;

    Vector2DF& operator+=(const Vector2DF& right);

    Vector2DF& operator-=(const Vector2DF& right);

    Vector2DF& operator*=(const Vector2DF& right);

    Vector2DF& operator/=(const Vector2DF& right);

    Vector2DF& operator*=(float right);

    Vector2DF& operator/=(float right);

    /**
            @brief	���ς��擾����B
            @param	v1	v1�x�N�g��
            @param	v2	v2�x�N�g��
            @return ����v1�Ev2
    */
    static float Dot(const Vector2DF& v1, const Vector2DF& v2) { return v1.X * v2.X + v1.Y * v2.Y; }

    /**
    @brief	�O�ς��擾����B
    @param	v1	v1�x�N�g��
    @param	v2	v2�x�N�g��
    @return �O��v1�~v2
    */
    static float Cross(const Vector2DF& v1, const Vector2DF& v2) { return v1.X * v2.Y - v1.Y * v2.X; }

    /**
    @brief	2�_�Ԃ̋������擾����B
    @param	v1	v1�x�N�g��
    @param	v2	v2�x�N�g��
    @return v1��v2�Ƃ̋���
    */
    static float Distance(const Vector2DF& v1, const Vector2DF& v2) {
        float dx = v1.X - v2.X;
        float dy = v1.Y - v2.Y;
        return sqrt(dx * dx + dy * dy);
    }

    /**
    @brief	���Z����B
    @param	v1	v1�x�N�g��
    @param	v2	v2�x�N�g��
    @return v1+v2
    */
    static Vector2DF Add(Vector2DF v1, Vector2DF v2) { return Vector2DF(v1.X + v2.X, v1.Y + v2.Y); }

    /**
    @brief	���Z����B
    @param	v1	v1�x�N�g��
    @param	v2	v2�x�N�g��
    @return v1-v2
    */
    static Vector2DF Subtract(Vector2DF v1, Vector2DF v2) { return Vector2DF(v1.X - v2.X, v1.Y - v2.Y); }

    /**
    @brief	���Z����B
    @param	v1	�l1
    @param	v2	�l2
    @return	v1/v2
    */
    static Vector2DF Divide(const Vector2DF& v1, const Vector2DF& v2) { return Vector2DF(v1.X / v2.X, v1.Y / v2.Y); }

    /**
    @brief	�X�J���[�ŏ��Z����B
    @param	v1	�l1
    @param	v2	�l2
    @return	v1/v2
    */
    static Vector2DF DivideByScalar(const Vector2DF& v1, float v2) { return Vector2DF(v1.X / v2, v1.Y / v2); }

    /**
            @brief	Vector2DI�^�ɕϊ�����B
            @return	Vector2DI�^
    */
    Vector2DI To2DI() const;
};

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
}  // namespace altseed
