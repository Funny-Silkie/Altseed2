#pragma once

#include <array>
#include "MathTemplate.h"
#include "Vector2DF.h"

namespace altseed {
/**
@brief	�����`(���������_)�̍\����
*/
struct RectF {
public:
    /**
    @brief	����X���W
    */
    float X;

    /**
    @brief	����Y���W
    */
    float Y;

    /**
    @brief	����
    */
    float Width;

    /**
    @brief	�c��
    */
    float Height;

    /**
    @brief	�R���X�g���N�^
    */
    RectF();

    /**
    @brief	�R���X�g���N�^
    @param	x	����X���W
    @param	y	����Y���W
    @param	width	����
    @param	height	�c��
    */
    RectF(float x, float y, float width, float height);

    /**
    @brief	�R���X�g���N�^
    @param	position	������W
    @param	size	�傫��
    */
    RectF(Vector2DF position, Vector2DF size);

    /**
    @brief	������W���擾����B
    @return	������W
    */
    Vector2DF GetPosition() const;

    /**
    @brief	�傫�����擾����B
    @return	�傫��
    */
    Vector2DF GetSize() const;

    /**
    @brief	�l���̍��W��(X,Y)�A(X+Width,Y)�A(X+Width,Y+Height)�A(X,Y+Height)�̏��ɔz��Ƃ��Ď擾����B
    @return	���W
    */
    std::array<Vector2DF, 4> GetVertexes() const;

    bool operator!=(const RectF& right);

    /**
    @brief	RectI�^�ɕϊ�����B
    @return	RectI�^
    */
    RectI ToI() const;
};

}  // namespace altseed
