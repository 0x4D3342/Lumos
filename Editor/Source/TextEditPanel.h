#pragma once
#include "EditorPanel.h"
#include <imguiPlugins/ImTextEditor.h>

namespace Lumos
{
    class TextEditPanel : public EditorPanel
    {
    public:
        TextEditPanel(const std::string& filePath);
        ~TextEditPanel() = default;

        void OnImGui() override;
        void OnClose();

        void SetOnSaveCallback(const std::function<void()>& callback) { m_OnSaveCallback = callback; }
        void SetErrors(const std::map<int, std::string>& errors);

    private:
        std::string m_FilePath;
        TextEditor editor;
        std::function<void()> m_OnSaveCallback;
    };
}
