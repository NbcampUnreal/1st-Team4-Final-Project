// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#define LogLine(){ CLog::Log(__FILE__, __FUNCTION__, __LINE__); }
#define PrintLine(){ CLog::Print(__FILE__, __FUNCTION__, __LINE__); }
#define DebugLog(val) CLog::Log(this, TEXT(__FUNCTION__), val)

class EMBER_API CLog
{
public:
	static void Log(TObjectPtr<UObject> Class, const TCHAR* FunctionName, int32 InValue);
	static void Log(TObjectPtr<UObject> Class, const TCHAR* FunctionName, float InValue);
	static void Log(TObjectPtr<UObject> Class, const TCHAR* FunctionName, const FString& InValue);
	static void Log(TObjectPtr<UObject> Class, const TCHAR* FunctionName, const FVector& InValue);
	static void Log(TObjectPtr<UObject> Class, const TCHAR* FunctionName, const FRotator& InValue);

	static void Log(int32 InValue);
	static void Log(float InValue);
	static void Log(const FString& InValue);
	static void Log(const FVector& InValue);
	static void Log(const FRotator& InValue);
	static void Log(const UObject* InValue);
	static void Log(const FString& InFileName, const FString& InFuncName, int32 InLineNumber);

	static void Print(int32 InValue, int32 InKey = -1, float InDuration = 10, FColor InColor = FColor::Blue);
	static void Print(float InValue, int32 InKey = -1, float InDuration = 10, FColor InColor = FColor::Blue);
	static void Print(const FString& InValue, int32 InKey = -1, float InDuration = 10, FColor InColor = FColor::Blue);
	static void Print(const FVector& InValue, int32 InKey = -1, float InDuration = 10, FColor InColor = FColor::Blue);
	static void Print(const FRotator& InValue, int32 InKey = -1, float InDuration = 10, FColor InColor = FColor::Blue);
	static void Print(const UObject* InValue, int32 InKey = -1, float InDuration = 10, FColor InColor = FColor::Blue);
	static void Print(const FString& InFileName, const FString& InFuncName, int32 InLineNumber);
};
