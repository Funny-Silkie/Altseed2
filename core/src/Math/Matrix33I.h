#pragma once
#include "Vector2DI.h"
#include "Vector3DI.h"

namespace altseed {
/**
        @brief	3�~3�s���\���\���́B
        @note
        [0,0][0,1]
        [1,0][1,1]
        */
struct Matrix33I {
public:
    /**
            @brief	�I�u�W�F�N�g�𐶐����A�P�ʍs��ŏ���������B
    */
    Matrix33I();

    /**
            @brief	�s��̒l
    */
    int32_t Values[3][3];

    /**
            @brief	�P�ʍs���ݒ肷��B
    */
    Matrix33I& SetIdentity();

    /**
    @brief	�]�u�s���ݒ肷��B
    @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix33I& SetTransposed();

    /**
    @brief	�t�s���ݒ肷��B
    @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix33I& SetInverted();

    /**
    @brief	�t�s����擾����B
    @return	�t�s��
    */
    Matrix33I GetInverted();

    /**
    @brief	���s�ړ��̍s���ݒ肷��B
        */
    Matrix33I& SetTranslation(int32_t x, int32_t y);

    /**
@brief	�g��E�k���s���ݒ肷��B
*/
    Matrix33I& SetScale(int32_t x, int32_t y);

    /**
    @brief	�s��Ńx�N�g����ό`������B
    @param	in	�ό`�O�x�N�g��
    @return	�ό`��x�N�g��
    */
    Vector2DI Transform2D(const Vector2DI& in) const;

    /**
    @brief	�s��Ńx�N�g����ό`������B
    @param	in	�ό`�O�x�N�g��
    @return	�ό`��x�N�g��
    */
    Vector3DI Transform3D(const Vector3DI& in) const;

    /**
    @brief	3�~3�s��̊|���Z���v�Z����B
            */
    Matrix33I operator*(const Matrix33I& right);

    Vector3DI operator*(const Vector3DI& right);
};
}  // namespace altseed