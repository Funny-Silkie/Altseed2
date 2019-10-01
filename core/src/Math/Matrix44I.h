#pragma once

//----------------------------------------------------------------------------------
// Include
//----------------------------------------------------------------------------------
#include "MathTemplate.h"
#include "Vector3DI.h"
#include "Vector4DI.h"
//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
namespace altseed {
//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------

/**
        @brief	4�~4�s���\���\����
        @note
        M * V[x,y,z,1] �̌`<BR>
        [0,0][0,1][0,2][0,3]
        [1,0][1,1][1,2][1,3]
        [2,0][2,1][2,2][2,3]
        [3,0][3,1][3,2][3,3]
*/
struct Matrix44I {
private:
public:
    /**
            @brief	�I�u�W�F�N�g�𐶐����A�P�ʍs��ŏ���������B
    */
    Matrix44I();

    /**
            @brief	�s��̒l
    */
    float Values[4][4];

    /**
            @brief	�P�ʍs���ݒ肷��B
            @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44I& SetIdentity();

    /**
            @brief	�]�u�s���ݒ肷��B
            @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44I& SetTransposed();

    /**
            @brief	�t�s���ݒ肷��B
            @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44I& SetInverted();

    /**
            @brief	�t�s����擾����B
            @return	�t�s��
    */
    Matrix44I GetInverted() const;

    /**
            @brief	�J�����s��(�E��n)��ݒ肷��B
            @param	eye	�J�����̈ʒu
            @param	at	�J�����̒����_
            @param	up	�J�����̏����
            @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44I& SetLookAtRH(const Vector3DI& eye, const Vector3DI& at, const Vector3DI& up);

    /**
            @brief	�J�����s��(����n)��ݒ肷��B
            @param	eye	�J�����̈ʒu
            @param	at	�J�����̒����_
            @param	up	�J�����̏����
            @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44I& SetLookAtLH(const Vector3DI& eye, const Vector3DI& at, const Vector3DI& up);

    /**
            @brief	�ˉe�s��(�E��n)��ݒ肷��B
            @param	ovY	Y�����ւ̎���p(���W�A��)
            @param	aspect	��ʂ̃A�X�y�N�g��
            @param	zn	�ŋߋ���
            @param	zf	�ŉ�����
            @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44I& SetPerspectiveFovRH(float ovY, float aspect, float zn, float zf);

    /**
            @brief	OpenGL�p�ˉe�s��(�E��n)��ݒ肷��B
            @param	ovY	Y�����ւ̎���p(���W�A��)
            @param	aspect	��ʂ̃A�X�y�N�g��
            @param	zn	�ŋߋ���
            @param	zf	�ŉ�����
            @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44I& SetPerspectiveFovRH_OpenGL(float ovY, float aspect, float zn, float zf);

    /**
            @brief	�ˉe�s��(����n)��ݒ肷��B
            @param	ovY	Y�����ւ̎���p(���W�A��)
            @param	aspect	��ʂ̃A�X�y�N�g��
            @param	zn	�ŋߋ���
            @param	zf	�ŉ�����
            @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44I& SetPerspectiveFovLH(float ovY, float aspect, float zn, float zf);

    /**
            @brief	���ˉe�s��(�E��n)��ݒ肷��B
            @param	width	����
            @param	height	�c��
            @param	zn	�ŋߋ���
            @param	zf	�ŉ�����
            @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44I& SetOrthographicRH(float width, float height, float zn, float zf);

    /**
            @brief	���ˉe�s��(����n)��ݒ肷��B
            @param	width	����
            @param	height	�c��
            @param	zn	�ŋߋ���
            @param	zf	�ŉ�����
            @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44I& SetOrthographicLH(float width, float height, float zn, float zf);

    /**
            @brief	���s�ړ��s���ݒ肷��B
            @param	x	X�����ړ���
            @param	y	Y�����ړ���
            @param	z	Z�����ړ���
            @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44I& SetTranslation(float x, float y, float z);

    /**
            @brief	X����]�s��(�E��)��ݒ肷��B
            @param	angle	X����]��(���W�A��)
            @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44I& SetRotationX(float angle);

    /**
            @brief	Y����]�s��(�E��)��ݒ肷��B
            @param	angle	Y����]��(���W�A��)
            @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44I& SetRotationY(float angle);

    /**
            @brief	Z����]�s��(�E��)��ݒ肷��B
            @param	angle	Z����]��(���W�A��)
            @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44I& SetRotationZ(float angle);

    /**
    @brief	�C�ӎ��̔����v��]�s��(�E��)��ݒ肷��B
    @param	axis	��
    @param	angle	��]��(���W�A��)
    @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44I& SetRotationAxis(const Vector3DI& axis, float angle);

    /**
    @brief	�N�I�[�^�j�I�������ɉ�]�s��(�E��)��ݒ肷��B
    @param	x	�N�I�[�^�j�I��
    @param	y	�N�I�[�^�j�I��
    @param	z	�N�I�[�^�j�I��
    @param	w	�N�I�[�^�j�I��
    @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44I& SetQuaternion(float x, float y, float z, float w);

    /**
    @brief	�g��s���ݒ肷��B
    @param	x	X�����g�嗦
    @param	y	Y�����g�嗦
    @param	z	Z�����g�嗦
    @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44I& SetScale(float x, float y, float z);

    /**
    @brief	�s��Ńx�N�g����ό`������B
    @param	in	�ό`�O�x�N�g��
    @return	�ό`��x�N�g��
    */
    Vector3DI Transform3D(const Vector3DI& in) const;

    /**
    @brief	�s��Ńx�N�g����ό`������B
    @param	in	�ό`�O�x�N�g��
    @return	�ό`��x�N�g��
    */
    Vector4DI Transform4D(const Vector4DI& in) const;

    Matrix44I operator*(const Matrix44I& right) const;

    Vector3DI operator*(const Vector3DI& right) const;

    Vector4DI operator*(const Vector4DI& right) const;

    /**
            @brief	��Z���s���B
            @param	o	�o�͐�
            @param	in1	�s��1
            @param	in2	�s��2
            @return	�o�͐�̎Q��
    */
    static Matrix44I& Mul(Matrix44I& o, const Matrix44I& in1, const Matrix44I& in2);
};

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
}  // namespace altseed
//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------