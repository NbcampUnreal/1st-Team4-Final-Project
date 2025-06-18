#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/IHttpRequest.h" // Http 모듈 헤더
#include "C_RAGHttpActor.generated.h"

// 비동기 응답 처리를 위한 델리게이트 선언
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRagResponseReceived, const FString&, Answer);

UCLASS()
class RAGASSISTANT_API AC_RAGHttpActor : public AActor
{
    GENERATED_BODY()

public:
    AC_RAGHttpActor();

    // 블루프린트에서 호출할 함수
    UFUNCTION(BlueprintCallable, Category = "RAG Assistant")
    void SendQueryToAPIServer(const FString& Question);

    // 블루프린트에 바인딩할 델리게이트
    UPROPERTY(BlueprintAssignable, Category = "RAG Assistant")
    FOnRagResponseReceived OnResponseReceived;

private:
    // HTTP 응답을 받았을 때 호출될 함수
    void OnHttpResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
};