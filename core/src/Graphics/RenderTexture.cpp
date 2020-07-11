﻿#include "RenderTexture.h"

#include "CommandList.h"
#include "Graphics.h"
#include "Texture2D.h"

namespace Altseed2 {

RenderTexture::RenderTexture(const std::shared_ptr<LLGI::Texture>& texture) { texture_ = texture; }

RenderTexture::RenderTexture(Vector2I size) {
    texture_ = Graphics::GetInstance()->CreateRenderTexture(size.X, size.Y);
    size_.X = texture_->GetSizeAs2D().X;
    size_.Y = texture_->GetSizeAs2D().Y;
}

RenderTexture::~RenderTexture() { texture_ = nullptr; }

std::shared_ptr<RenderTexture> RenderTexture::Create(Vector2I size) { return MakeAsdShared<RenderTexture>(size); }

bool RenderTexture::Save(const char16_t* path) {
    Graphics::GetInstance()->GetCommandList()->SaveRenderTexture(path, CreateAndAddSharedPtr(this));
    return true;
}

}  // namespace Altseed2