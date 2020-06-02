#include <Configuration.h>
#include <Core.h>
#include <Graphics/CommandList.h>
#include <Graphics/Renderer/CullingSystem.h>
#include <Graphics/Renderer/RenderedSprite.h>
#include <Graphics/Renderer/Renderer.h>
#include <gtest/gtest.h>

TEST(Configuration, Initialize) {
    auto config = Altseed::Configuration::Create();
    EXPECT_EQ(config->GetIsFullscreen(), false);
    EXPECT_EQ(config->GetIsResizable(), false);
    EXPECT_EQ(config->GetConsoleLoggingEnabled(), false);
    EXPECT_EQ(config->GetFileLoggingEnabled(), false);
    EXPECT_EQ(config->GetToolEnabled(), false);
    EXPECT_EQ(std::u16string(config->GetLogFileName()), u"Log.txt");

    config->SetIsFullscreen(true);
    config->SetIsResizable(true);
    config->SetConsoleLoggingEnabled(true);
    config->SetFileLoggingEnabled(true);
    config->SetToolEnabled(true);
    config->SetLogFileName(u"Log-configtest.txt");

    EXPECT_EQ(config->GetIsFullscreen(), true);
    EXPECT_EQ(config->GetIsResizable(), true);
    EXPECT_EQ(config->GetConsoleLoggingEnabled(), true);
    EXPECT_EQ(config->GetFileLoggingEnabled(), true);
    EXPECT_EQ(config->GetToolEnabled(), true);
    EXPECT_EQ(std::u16string(config->GetLogFileName()), u"Log-configtest.txt");

    EXPECT_TRUE(Altseed::Core::Initialize(u"test", 640, 480, config));

    Altseed::Core::Terminate();
}

TEST(Configuration, GraphicsOnly) {
    auto config = Altseed::Configuration::Create();

    config->SetIsGraphicsOnly(true);

    EXPECT_EQ(config->GetIsGraphicsOnly(), true);

    EXPECT_TRUE(Altseed::Core::Initialize(u"test", 640, 480, config));

    int count = 0;

    auto instance = Altseed::Graphics::GetInstance();

    auto t1 = Altseed::Texture2D::Load(u"TestData/IO/AltseedPink.png");
    auto t2 = Altseed::Texture2D::Load(u"TestData/IO/AltseedPink.jpg");

    EXPECT_TRUE(t1 != nullptr);
    EXPECT_TRUE(t2 != nullptr);

    auto s1 = Altseed::RenderedSprite::Create();
    auto s2 = Altseed::RenderedSprite::Create();

    s1->SetTexture(t1);
    s1->SetSrc(Altseed::RectF(0, 0, 128, 128));

    auto trans = Altseed::Matrix44F();
    trans.SetTranslation(200, 200, 0);
    s2->SetTexture(t2);
    s2->SetTransform(trans);
    s2->SetSrc(Altseed::RectF(128, 128, 256, 256));

    while (count++ < 10 && instance->DoEvents()) {
        Altseed::CullingSystem::GetInstance()->UpdateAABB();
        Altseed::CullingSystem::GetInstance()->Cull(Altseed::RectF(Altseed::Vector2F(), Altseed::Window::GetInstance()->GetSize().To2F()));

        Altseed::RenderPassParameter renderPassParameter;
        renderPassParameter.ClearColor = Altseed::Color(50, 50, 50, 255);
        renderPassParameter.IsColorCleared = true;
        renderPassParameter.IsDepthCleared = true;
        EXPECT_TRUE(instance->BeginFrame(renderPassParameter));

        Altseed::Renderer::GetInstance()->DrawSprite(s1);
        Altseed::Renderer::GetInstance()->DrawSprite(s2);

        Altseed::Renderer::GetInstance()->Render();

        EXPECT_TRUE(instance->EndFrame());

        // Take screenshot
        if (count == 5) {
            // Altseed::Graphics::GetInstance()->TakeScreenshot(u"SpriteTexture.png");
        }
    }

    Altseed::Core::Terminate();
}