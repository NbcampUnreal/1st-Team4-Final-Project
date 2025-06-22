#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Data/GenAICoreStructs.h" // 방금 위에서 확정한 구조체 헤더
#include "GenAI_BaseProvider.generated.h"

// AI 응답 수신 시 호출될 델리게이트
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnChatResponseReceived, const TArray<FGenAIMessage>&, ResponseMessages, bool, bSuccess, const FString&, ErrorMessage);

// 모든 Provider가 상속받아야 하는 추상 기본 클래스
UCLASS(Abstract)
class GENERATIVEAISUPPORT_API UGenAI_BaseProvider : public UObject
{
	GENERATED_BODY()
public:
	// 채팅 AI 모델에 요청을 비동기적으로 전송하는 순수 가상 함수
	virtual void SendChatRequest(const FGenAIChatRequest& Request, const FOnChatResponseReceived& OnResponseReceived) PURE_VIRTUAL(UGenAI_BaseProvider::SendChatRequest,);
};