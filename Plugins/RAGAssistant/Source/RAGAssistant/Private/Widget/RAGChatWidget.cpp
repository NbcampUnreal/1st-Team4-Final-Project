// SRagChatWidget.cpp

#include "Widget/RagChatWidget.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Layout/SScrollBox.h"

void SRagChatWidget::Construct(const FArguments& InArgs)
{
    // ⭐️ Provider 객체 생성 및 초기화
    OllamaProvider = TStrongObjectPtr<URAGOllamaProvider>(NewObject<URAGOllamaProvider>());
    OllamaProvider->InitOllamaProvider(TEXT(""), TEXT("")); // 기본 설정값 사용

    ChildSlot
        [
            // ... (UI 레이아웃 코드는 이전과 동일)
            SNew(SVerticalBox)
                + SVerticalBox::Slot().FillHeight(1.0f)
                [
                    SNew(SScrollBox)
                        + SScrollBox::Slot()
                        [
                            SAssignNew(ChatHistoryTextBlock, STextBlock)
                                .Text(FText::FromString(TEXT("RAG 어시스턴트에게 무엇이든 물어보세요...")))
                                .WrapTextAt(500.0f)
                        ]
                ]
            + SVerticalBox::Slot().AutoHeight().Padding(0, 5, 0, 5)
                [
                    SAssignNew(PromptInputTextBox, SEditableTextBox)
                        .HintText(NSLOCTEXT("RagChat", "PromptHint", "여기에 프롬프트를 입력하세요..."))
                ]
                + SVerticalBox::Slot().AutoHeight()
                [
                    SNew(SButton)
                        .HAlign(HAlign_Center)
                        .Text(NSLOCTEXT("RagChat", "SendButton", "전송"))
                        .OnClicked(this, &SRagChatWidget::OnSendClicked)
                ]
        ];
}

FReply SRagChatWidget::OnSendClicked()
{
    const FString PromptText = PromptInputTextBox->GetText().ToString();
    if (PromptText.IsEmpty())
    {
        return FReply::Handled(); // 입력이 없으면 무시
    }

    // ⭐️ 채팅 기록에 내 질문 추가
    FString NewHistory = ChatHistoryTextBlock->GetText().ToString() + TEXT("\n\n[나]: ") + PromptText;
    ChatHistoryTextBlock->SetText(FText::FromString(NewHistory));

    // ⭐️ 입력창 비우기
    PromptInputTextBox->SetText(FText());

    // ⭐️ AI 응답 대기 중임을 표시
    ChatHistoryTextBlock->SetText(FText::FromString(NewHistory + TEXT("\n\n[AI]: 생각 중...")));

    
    // ⭐️ 드디어 Provider의 비동기 함수 호출!
    OllamaProvider->GenerateCompletionAsync(
        PromptText,
        URAGOllamaProvider::FOnOllamaCompletionGenerated::CreateSP(this, &SRagChatWidget::OnCompletionGenerated),
        URAGOllamaProvider::FOnOllamaCompletionFailed::CreateSP(this, &SRagChatWidget::OnCompletionFailed)
    );

    return FReply::Handled();
}

void SRagChatWidget::OnCompletionGenerated(const FString& GeneratedText)
{
    // ⭐️ "생각 중..." 텍스트를 실제 AI 응답으로 교체
    FString CurrentHistory = ChatHistoryTextBlock->GetText().ToString();
    CurrentHistory.RemoveFromEnd(TEXT("생각 중..."));
    CurrentHistory += GeneratedText;
    ChatHistoryTextBlock->SetText(FText::FromString(CurrentHistory));
}

void SRagChatWidget::OnCompletionFailed(const FString& ErrorMessage)
{
    // ⭐️ "생각 중..." 텍스트를 에러 메시지로 교체
    FString CurrentHistory = ChatHistoryTextBlock->GetText().ToString();
    CurrentHistory.RemoveFromEnd(TEXT("생각 중..."));
    CurrentHistory += FString::Printf(TEXT("[오류]: %s"), *ErrorMessage);
    ChatHistoryTextBlock->SetText(FText::FromString(CurrentHistory));
}

// ⭐️ 채팅 기록 초기화 함수
void SRagChatWidget::ClearChatHistory()
{
    ChatHistoryTextBlock->SetText(FText::FromString(TEXT("RAG 어시스턴트에게 무엇이든 물어보세요...")));
}
