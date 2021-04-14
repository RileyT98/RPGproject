// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "JsonDataAssetBase.h"
#include "EnemyRewardData.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class ACTIONRPG_API UEnemyRewardData : public UJsonDataAssetBase
{
	GENERATED_BODY()

public:
        UEnemyRewardData();

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Reward)
		float TimeBonusPerKill;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Reward)
	    int MinSoulsDropped;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Reward)
		int MaxSoulsDropped;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Reward)
		float PotionDropChance;

		virtual TSharedPtr<FJsonObject> ToJson() override;
		virtual bool FromJson(FJsonObject& jsonObject)override;
	
};
