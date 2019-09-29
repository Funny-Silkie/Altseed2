#pragma once

//----------------------------------------------------------------------------------
// Include
//----------------------------------------------------------------------------------
#include "MathTemplate.h"

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
struct Matrix44 {
private:
public:
    /**
            @brief	�I�u�W�F�N�g�𐶐����A�P�ʍs��ŏ���������B
    */
    Matrix44();

    /**
            @brief	�s��̒l
    */
    float Values[4][4];

    /**
            @brief	�P�ʍs���ݒ肷��B
            @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44& SetIdentity();

    /**
            @brief	�]�u�s���ݒ肷��B
            @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44& SetTransposed();

    /**
            @brief	�t�s���ݒ肷��B
            @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44& SetInverted();

    /**
            @brief	�t�s����擾����B
            @return	�t�s��
    */
    Matrix44 GetInverted() const;

    /**
            @brief	�J�����s��(�E��n)��ݒ肷��B
            @param	eye	�J�����̈ʒu
            @param	at	�J�����̒����_
            @param	up	�J�����̏����
            @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44& SetLookAtRH(const Vector3DF& eye, const Vector3DF& at, const Vector3DF& up);

    /**
            @brief	�J�����s��(����n)��ݒ肷��B
            @param	eye	�J�����̈ʒu
            @param	at	�J�����̒����_
            @param	up	�J�����̏����
            @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44& SetLookAtLH(const Vector3DF& eye, const Vector3DF& at, const Vector3DF& up);

    /**
            @brief	�ˉe�s��(�E��n)��ݒ肷��B
            @param	ovY	Y�����ւ̎���p(���W�A��)
            @param	aspect	��ʂ̃A�X�y�N�g��
            @param	zn	�ŋߋ���
            @param	zf	�ŉ�����
            @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44& SetPerspectiveFovRH(float ovY, float aspect, float zn, float zf);

    /**
            @brief	OpenGL�p�ˉe�s��(�E��n)��ݒ肷��B
            @param	ovY	Y�����ւ̎���p(���W�A��)
            @param	aspect	��ʂ̃A�X�y�N�g��
            @param	zn	�ŋߋ���
            @param	zf	�ŉ�����
            @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44& SetPerspectiveFovRH_OpenGL(float ovY, float aspect, float zn, float zf);

    /**
            @brief	�ˉe�s��(����n)��ݒ肷��B
            @param	ovY	Y�����ւ̎���p(���W�A��)
            @param	aspect	��ʂ̃A�X�y�N�g��
            @param	zn	�ŋߋ���
            @param	zf	�ŉ�����
            @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44& SetPerspectiveFovLH(float ovY, float aspect, float zn, float zf);

    /**
            @brief	���ˉe�s��(�E��n)��ݒ肷��B
            @param	width	����
            @param	height	�c��
            @param	zn	�ŋߋ���
            @param	zf	�ŉ�����
            @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44& SetOrthographicRH(float width, float height, float zn, float zf);

    /**
            @brief	���ˉe�s��(����n)��ݒ肷��B
            @param	width	����
            @param	height	�c��
            @param	zn	�ŋߋ���
            @param	zf	�ŉ�����
            @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44& SetOrthographicLH(float width, float height, float zn, float zf);

    /**
            @brief	���s�ړ��s���ݒ肷��B
            @param	x	X�����ړ���
            @param	y	Y�����ړ���
            @param	z	Z�����ړ���
            @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44& SetTranslation(float x, float y, float z);

    /**
            @brief	X����]�s��(�E��)��ݒ肷��B
            @param	angle	X����]��(���W�A��)
            @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44& SetRotationX(float angle);

    /**
            @brief	Y����]�s��(�E��)��ݒ肷��B
            @param	angle	Y����]��(���W�A��)
            @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44& SetRotationY(float angle);

    /**
            @brief	Z����]�s��(�E��)��ݒ肷��B
            @param	angle	Z����]��(���W�A��)
            @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44& SetRotationZ(float angle);

    /**
    @brief	�C�ӎ��̔����v��]�s��(�E��)��ݒ肷��B
    @param	axis	��
    @param	angle	��]��(���W�A��)
    @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44& SetRotationAxis(const Vector3DF& axis, float angle);

    /**
    @brief	�N�I�[�^�j�I�������ɉ�]�s��(�E��)��ݒ肷��B
    @param	x	�N�I�[�^�j�I��
    @param	y	�N�I�[�^�j�I��
    @param	z	�N�I�[�^�j�I��
    @param	w	�N�I�[�^�j�I��
    @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44& SetQuaternion(float x, float y, float z, float w);

    /**
    @brief	�g��s���ݒ肷��B
    @param	x	X�����g�嗦
    @param	y	Y�����g�嗦
    @param	z	Z�����g�嗦
    @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44& SetScale(float x, float y, float z);

    /**
    @brief	�s��Ńx�N�g����ό`������B
    @param	in	�ό`�O�x�N�g��
    @return	�ό`��x�N�g��
    */
    Vector3DF Transform3D(const Vector3DF& in) const;

    /**
    @brief	�s��Ńx�N�g����ό`������B
    @param	in	�ό`�O�x�N�g��
    @return	�ό`��x�N�g��
    */
    Vector4DF Transform4D(const Vector4DF& in) const;

    Matrix44 operator*(const Matrix44& right) const;

    Vector3DF operator*(const Vector3DF& right) const;

    Vector4DF operator*(const Vector4DF& right) const;

    /**
            @brief	��Z���s���B
            @param	o	�o�͐�
            @param	in1	�s��1
            @param	in2	�s��2
            @return	�o�͐�̎Q��
    */
    static Matrix44& Mul(Matrix44& o, const Matrix44& in1, const Matrix44& in2);
};

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
}  // namespace asd
//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------