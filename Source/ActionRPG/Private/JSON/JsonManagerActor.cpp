// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "Serialization/JsonWriter.h"
#include "JsonManagerActor.h"

// Sets default values
AJsonManagerActor::AJsonManagerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AJsonManagerActor::BeginPlay()
{
	Super::BeginPlay();

	if (JsonDataAsset != nullptr && !JsonInputString.IsEmpty())
	{
		TSharedPtr<FJsonObject> jsonObject = GetJsonFromString(JsonInputString);
		JsonDataAsset->FromJson(*jsonObject.Get());


	}
	
}

TSharedPtr<FJsonObject>AJsonManagerActor::GetJsonFromString(const FString& JsonString)
{
	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();
	TSharedRef<TJsonReader<TCHAR>> reader = TJsonReaderFactory<TCHAR>::Create(JsonInputString);
	FJsonSerializer::Deserialize(reader, jsonObject);
	return jsonObject;
}


FString AJsonManagerActor::GetStringFromJson(TSharedRef<FJsonObject> jsonObject)
{
	FString output;
	TSharedRef<TJsonWriter<TCHAR>> writer = TJsonWriterFactory<TCHAR>::Create(&output);
	FJsonSerializer::Serialize(jsonObject, writer);
	return output;
}

void AJsonManagerActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	FName propertyName = PropertyChangedEvent.Property->GetFName();
	
	if (propertyName == GET_MEMBER_NAME_CHECKED(AJsonManagerActor, bFromJson)
	{
		bFromJson = false;
			
			if (JsonDataAsset != nullptr && !JsonInput.isEmpty())
			{
				TSharedPtr<FJsonObject> jsonObject = GetJsonFromString(JsonInput);
					JsonDataAsset->FromJson(*jsonObject.Get());
			}
	}

	if (propertyName == GET_MEMBER_NAME_CHECKED(AJsonManagerActor, bToJson)
	{
		bToJson = false;
			if (JsonDataAsset != nullptr)
			{
				JsonOutput = GetStringFromJson(JsonDataAsset->ToJson().ToSharedRef());
			}
	}
}

// Called every frame
void AJsonManagerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

