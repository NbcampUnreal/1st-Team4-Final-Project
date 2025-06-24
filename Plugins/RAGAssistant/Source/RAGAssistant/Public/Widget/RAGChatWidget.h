#pragma once

#include "CoreMinimal.h"
#include "Provider/RAGOllamaProvider.h"
#include "Widgets/SCompoundWidget.h"

class STextBlock;
class SEditableTextBox;
class URAGOllamaProvider;

class SRagChatWidget : public SCompoundWidget
{
public:
    SLATE_BEGIN_ARGS(SRagChatWidget) {}
    SLATE_END_ARGS()

    void Construct(const FArguments& InArgs);

private:
    TStrongObjectPtr<URAGOllamaProvider> OllamaProvider;
    TSharedPtr<STextBlock> ChatHistoryTextBlock;
    TSharedPtr<SEditableTextBox> PromptInputTextBox;
    FReply OnSendClicked();
    void OnCompletionGenerated(const FString& GeneratedText);
    void OnCompletionFailed(const FString& ErrorMessage);
    void ClearChatHistory();
};