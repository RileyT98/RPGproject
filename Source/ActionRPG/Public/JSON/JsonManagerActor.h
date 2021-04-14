// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JsonDataAssetBase.h"
#include "Serialization/JsonWriter.h"
#include "JsonManagerActor.generated.h"

UCLASS()
class ACTIONRPG_API AJsonManagerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AJsonManagerActor();

	UPROPERTY(EditAnywhere, Category = JSON)
	FString JsonInputString;

	UPROPERTY(EditAnywhere, Category = JSON)
	UJsonDataAssetBase* JsonDataAsset;

	TSharedPtr<FJsonObject> GetJsonFromString(const FString& jsonString);
	
	FString GetStringFromJson(TSharedRef<FJsonObject> jsonObject);

	UPROPERTY(EditAnywhere, Category = "Json Editor")
	FString JsonInput;
	
	UPROPERTY(EditAnywhere, Category = "Json Editor")
	FString JsonOutput;

	UPROPERTY(EditAnywhere, Category = "Json Editor")
	bool bFromJson;

	UPROPERTY(EditAnywhere, Category = "Json Editor")
	bool bToJson;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
